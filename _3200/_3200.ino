#include "filter.h";
#include "hsv.h";
#include "types.h";

const int PIN_LED = 13;
const int PIN_SENSOR_S2 = 2;
const int PIN_SENSOR_S3 = 3;

volatile int rawRed = 0;
volatile int maxRed = 0;
volatile int filteredRed = 0;

volatile int rawGreen = 0;
volatile int maxGreen = 0;
volatile int filteredGreen = 0;

volatile int rawBlue = 0;
volatile int maxBlue = 0;
volatile int filteredBlue = 0;

volatile int rawClear = 0;
volatile int maxClear = 0;
volatile int filteredClearLP = 0;
volatile int filteredClearHP = 0;

// Scale factors, initialized to reasonable values
const unsigned int SCALE = 60000;
unsigned int scaleRed = SCALE/200;
unsigned int scaleGreen = SCALE/200;
unsigned int scaleBlue = SCALE/200;

volatile colorMode_t colorMode = CLEAR;


// Sample rate is 4ms for a full cycle of four colors, or 250 samples/sec.
// High-pass, 20Hz
Filter filterClearHP = Filter(HIGHPASS, 1.257, 0.5914);

// Low-pass, 40Hz.
Filter filterClearLP = Filter(LOWPASS, 2.819, 0.2905);

// Low-pass, 40Hz.
//Filter filterRed = Filter(LOWPASS, 2.819, 0.2905);
//Filter filterGreen = Filter(LOWPASS, 2.819, 0.2905);
//Filter filterBlue = Filter(LOWPASS, 2.819, 0.2905);

// Low-pass, 20Hz.
Filter filterRed = Filter(LOWPASS, 4.895, 0.5914);
Filter filterGreen = Filter(LOWPASS, 4.895, 0.5914);
Filter filterBlue = Filter(LOWPASS, 4.895, 0.5914);


// keep-on counter for led.
unsigned int ledTimer = 0;


// Advance to the next color, configure sensor, and return it.
colorMode_t advanceSensor(colorMode_t currentMode) {
  colorMode_t newMode;

  switch (currentMode) {
    case RED: // Green
      newMode = GREEN;
      digitalWrite(PIN_SENSOR_S2, HIGH);
      digitalWrite(PIN_SENSOR_S3, HIGH);
      break;

    case GREEN:
      newMode = BLUE;
      digitalWrite(PIN_SENSOR_S2, LOW);
      digitalWrite(PIN_SENSOR_S3, HIGH);
      break;

    case BLUE:
      newMode = CLEAR;
      digitalWrite(PIN_SENSOR_S2, HIGH);
      digitalWrite(PIN_SENSOR_S3, LOW);
      break;

    case CLEAR:
      newMode = RED;
      digitalWrite(PIN_SENSOR_S2, LOW);
      digitalWrite(PIN_SENSOR_S3, LOW);
      break;

  }

  return newMode;
}

// Determines scale values
void calibrate() {

  // Get maximum counts over long interval
  cli();
  maxRed = 0;
  maxGreen = 0;
  maxBlue = 0;
  sei();

  // Wait 500ms
  delay(500);

  cli();
  scaleRed = 60000 / maxRed;
  scaleGreen = 60000 / maxGreen;
  scaleBlue = 60000 / maxBlue;
  sei();
}


void stopTimer() {
  // Stop timer 2
  TCCR2A = 0;
  TCCR2B = 0; 
}

void startTimer() {
  // Start timer 2
  TCCR2A = bit(WGM21); // CTC mode
  TCCR2B = bit(CS20) | bit (CS22); // Prescaler 128 
}

void clearCounter() {
  // Clear counter
  TCNT1 = 0;
}

void writeResult() {

  unsigned int copyRed = rawRed;
  int copyFilteredRed = filteredRed;
  unsigned int copyGreen = rawGreen;
  int copyFilteredGreen = filteredGreen;
  unsigned int copyBlue = rawBlue;
  int copyFilteredBlue = filteredBlue;
  unsigned int copyClear = rawClear;
  int copyFilteredClear = filteredClearHP;

  unsigned int scaledRed = copyFilteredRed * scaleRed;
  unsigned int scaledGreen = copyFilteredGreen * scaleGreen;
  unsigned int scaledBlue = copyFilteredBlue * scaleBlue;

  HSV color;
  HSV::fromScaledRGB(SCALE, scaledRed, scaledGreen, scaledBlue, color);

  Serial.print("  C: ");
  Serial.print(copyClear);
  Serial.print("  Cf: ");
  Serial.print(copyFilteredClear);

  //  Serial.println();
  Serial.print("  R: ");
  Serial.print(copyRed);
  Serial.print("  G: ");
  Serial.print(copyGreen);
  Serial.print("  B: ");
  Serial.print(copyBlue);

  Serial.print("  Rf: ");
  Serial.print(copyFilteredRed);
  Serial.print("  Gf: ");
  Serial.print(copyFilteredGreen);
  Serial.print("  Bf: ");
  Serial.print(copyFilteredBlue);

  Serial.print("  Rs: ");
  Serial.print(scaledRed);
  Serial.print("  Gs: ");
  Serial.print(scaledGreen);
  Serial.print("  Bs: ");
  Serial.print(scaledBlue);

  Serial.print("  H: ");
  Serial.print(color.h);
  Serial.print("  S: ");
  Serial.print(color.s);
  Serial.print("  V: ");
  Serial.print(color.v);
  Serial.println();
}


void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(PIN_SENSOR_S2, OUTPUT);
  pinMode(PIN_SENSOR_S3, OUTPUT);

  colorMode = advanceSensor(colorMode);

  // Reset timers 1 and 2
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR2A = 0;
  TCCR2B = 0;

  // Zero the counters
  TCNT1 = 0;
  TCNT2 = 0;

  // Configure timer 1 to count external events (pulses from TCS3200)
  TCCR1B = bit(CS12) | bit(CS11) | bit(CS10);

  // Configure timer 2 to interrupt every millisecond: prescaler=128, count up to 125
  GTCCR = bit(PSRASY); // Reset prescaler
  OCR2A = 124; // Count to 125
  //OCR2A = 249;
  TIMSK2 = bit(OCIE2A); // Enable interrupt

  startTimer();

  Serial.begin(115200);
  Serial.println("Calibrating...");
  calibrate();
  Serial.print("Scale red: ");
  Serial.print(scaleRed);
  Serial.print("  Scale green: ");
  Serial.print(scaleGreen);
  Serial.print("  Scale blue: ");
  Serial.print(scaleBlue);
  Serial.println();
}



void loop() {
  int v = abs(filteredClearHP);
  if (v > 35 && v < 100) {
    writeResult();
  }
}

ISR(TIMER2_COMPA_vect) {

  // LED on
  PORTD |= bit(7);

  // Get counter value
  stopTimer();
  colorMode_t prevMode = colorMode;
  unsigned int count = TCNT1;
  clearCounter();
  colorMode = advanceSensor(colorMode);
  startTimer();

  switch(prevMode) {
    case RED:
      rawRed = count;
      filteredRed = filterRed.next(count);
      if (filteredRed > maxRed) maxRed = filteredRed;
      break;

    case GREEN:
      rawGreen = count;
      filteredGreen = filterGreen.next(count);
      if (filteredGreen > maxGreen) maxGreen = filteredGreen;
      break;

    case BLUE:
      rawBlue = count;
      filteredBlue = filterBlue.next(count);
      if (filteredBlue > maxBlue) maxBlue = filteredBlue;
      break;

    default:
      rawClear = count;
      filteredClearLP = filterClearLP.next(count);
      if (filteredClearLP > maxClear) maxClear = filteredClearLP;
      filteredClearHP = filterClearHP.next(count);
      break;
      }

  // LED off
  PORTD &= ~bit(7);
}+
