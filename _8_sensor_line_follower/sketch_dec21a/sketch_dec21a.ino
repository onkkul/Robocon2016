#define leftCenterSensor 3
#define leftNearSensor 4
#define leftFarSensor 5
#define rightCenterSensor 2
#define rightNearSensor 1
#define rightFarSensor 0
#define leftMotor1 7
#define leftMotor2 6
#define rightMotor1 5
#define rightMotor2 8
#define led 13
int leftCenterReading; int leftNearReading; int leftFarReading;
int rightCenterReading; int rightNearReading; int rightFarReading; int leftNudge;
int replaystage; int rightNudge; char path[30] = {}; int pathLength; int readLength; void setup() {
  pinMode(leftCenterSensor, INPUT); pinMode(leftNearSensor, INPUT); pinMode(leftFarSensor, INPUT);
  pinMode(rightCenterSensor, INPUT); pinMode(rightNearSensor, INPUT); pinMode(rightFarSensor, INPUT);
  pinMode(leftMotor1, OUTPUT); pinMode(leftMotor2, OUTPUT); pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(led, OUTPUT); digitalWrite(led, HIGH); delay(1000);
}
void loop() {              ////######################STARTING OF CODE###########################
  readSensors();
  if (leftFarReading < 200 && rightFarReading < 200 && (leftCenterReading > 200 || rightCenterReading > 200) )
  {
    straight();
  }
  else {
    leftHandWall();
    //Maze Solving Robot Using Freeduino And Lsrb Algorithm
    //National Conference on Architecture, Software systems and Green computing (NCASG) 97 | Page
  }
}


void readSensors()
{
  leftCenterReading = analogRead(leftCenterSensor);
  leftNearReading = analogRead(leftNearSensor);
  leftFarReading = analogRead(leftFarSensor);
  rightCenterReading = analogRead(rightCenterSensor);
  rightNearReading = analogRead(rightNearSensor);
  rightFarReading = analogRead(rightFarSensor);
}


void leftHandWall()
{
  if (leftFarReading > 200 && rightFarReading > 200)
  { digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(170);
    readSensors();
    if (leftFarReading > 200 || rightFarReading > 200) {
      done();
    }
    if (leftFarReading < 200 && rightFarReading < 200) {
      turnLeft();
    }
    if (leftFarReading > 200) {
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      delay(170);

      readSensors();

      if (leftFarReading < 200 && rightFarReading < 200) {
        turnLeft();
      }
      else
      {
        done();
      }
      if (rightFarReading > 200)
      {
        digitalWrite(leftMotor1, HIGH); delay(2000);
        digitalWrite(leftMotor2, LOW); replay();
        digitalWrite(rightMotor1, HIGH);
      }
      digitalWrite(rightMotor2, LOW);
      delay(30);
      readSensors();

    }
  }
}
void turnLeft()
{
  if (leftFarReading > 200)
  {
    while (analogRead(rightCenterSensor) > 200 || analogRead(leftCenterSensor) > 200)
    {
      readSensors(); digitalWrite(leftMotor1, LOW);
      if (rightFarReading > 200 && leftFarReading > 200)
      {
        digitalWrite(leftMotor2, HIGH);
        done();
        digitalWrite(rightMotor1, HIGH);
      }
      digitalWrite(rightMotor2, LOW);
    }
  }
  else
  {
    delay(2);
    turnLeft(); digitalWrite(leftMotor1, LOW);
    return; digitalWrite(leftMotor2, LOW);
  }
  digitalWrite(rightMotor1, LOW);


  digitalWrite(rightMotor2, LOW);
  delay(140);
  delay(1);
  readSensors();

}


void l()
{
  if (leftFarReading < 200 && leftCenterReading < 200 )
  {
    digitalWrite(leftMotor1, LOW);
    turnRight();
    digitalWrite(leftMotor2, HIGH);
    return;
    digitalWrite(rightMotor1, HIGH);
  }


  digitalWrite(rightMotor2, LOW);
  path[pathLength] = 'S';
  delay(2);
  pathLength++;
  digitalWrite(leftMotor1, LOW);

  if (path[pathLength - 2] == 'B')
  {
    digitalWrite(leftMotor2, LOW);
    shortPath();
    digitalWrite(rightMotor1, LOW);
  }
  digitalWrite(rightMotor2, LOW);
  straight();
  delay(1);
}

readSensors();
if (replaystage == 0)
{
  if (leftFarReading < 200 && leftCenterReading < 200 && path[pathLength] = 'L';

      rightCenterReading < 200 && rightFarReading < 200 && pathLength++;
      leftNearReading < 200 && rightNearReading < 200)
  {
    r        if (path[pathLength - 2] == 'B')
    {
      turnAround();
      shortPath();
    }
  }
}
}
}
void done()
{
  digitalWrite(leftMotor1, LOW);
}
void turnRight() {
  digitalWrite(leftMotor2, LOW);
  while (analogRead(rightCenterSensor) > 200)
  {
    digitalWrite(rightMotor1, LOW);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    digitalWrite(leftMotor2, LOW);
    replaystage = 1;
    digitalWrite(rightMotor1, LOW);
    path[pathLength] = 'D';
    digitalWrite(rightMotor2, HIGH);
    pathLength++;
    delay(2);
    while (analogRead(leftFarSensor) > 200)
    {
      digitalWrite(leftMotor1, LOW);
      digitalWrite(led, LOW);
      digitalWrite(leftMotor2, LOW);
      delay(150);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(led, HIGH);
      digitalWrite(rightMotor2, LOW);
      delay(150); delay(1);
    }
  }

  while (analogRead(rightCenterSensor) < 200)
  {
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    digitalWrite(rightMotor2, HIGH);
    delay(7);
    delay(2);
    return;
    digitalWrite(leftMotor1, LOW);
  }
  digitalWrite(leftMotor2, LOW);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  delay(1);
  digitalWrite(rightMotor2, LOW);
}
delay(4);
while (analogRead(leftCenterSensor) < 200)
{
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  digitalWrite(rightMotor2, HIGH);
  delay(1);
  delay(2);
  digitalWrite(leftMotor1, LOW);
}
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);


void turnAround()
{
  digitalWrite(rightMotor2, LOW);
  digitalWrite(leftMotor1, HIGH);
  delay(1);
  digitalWrite(leftMotor2, LOW);
}



digitalWrite(rightMotor1, HIGH);
if (replaystage == 0)
{
  digitalWrite(rightMotor2, LOW);
  path[pathLength] = 'R';
  delay(150);
  pathLength++;
  while (analogRead(leftCenterSensor) < 200)
  {
    if (path[pathLength - 2] == 'B')
    {
      digitalWrite(leftMotor1, LOW);
      shortPath();
      digitalWrite(leftMotor2, HIGH);
    }
    digitalWrite(rightMotor1, HIGH);
  }
  digitalWrite(rightMotor2, LOW);
}
delay(2);
}


void straight()
{
  digitalWrite(leftMotor1, LOW);

  if (analogRead(leftCenterSensor) < 200)
  {
    digitalWrite(leftMotor2, LOW);

    digitalWrite(leftMotor1, HIGH);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    delay(1);
    digitalWrite(rightMotor2, LOW);

    delay(2); path[pathLength] = 'B';
    digitalWrite(leftMotor1, HIGH); pathLength++;
    digitalWrite(leftMotor2, LOW); straight();
    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);
  }
}

void shortPath()
{
  delay(7);
  int shortDone = 0;
  return;
  if (path[pathLength - 3] == 'L' && path[pathLength - 1] == 'R')
  {
    //Maze Solving Robot Using Freeduino And Lsrb Algorithm
    //National Conference on Architecture, Software systems and Green computing (NCASG) 99 | Page
    if (analogRead(rightCenterSensor) < 200)
    {
      pathLength -= 3;
      digitalWrite(leftMotor1, HIGH); path[pathLength] = 'B';
      digitalWrite(leftMotor2, LOW); shortDone = 1;
      digitalWrite(rightMotor1, HIGH);
    }
    digitalWrite(rightMotor2, LOW); if (path[pathLength - 3] == 'L' && path[pathLengthdelay(2); 1] == 'S' && shortDone == 0) {
      pathLength -= 3; digitalWrite(leftMotor2, LOW);
      path[pathLength] = 'R'; digitalWrite(rightMotor1, HIGH);
      shortDone = 1; digitalWrite(rightMotor2, LOW);
    } delay(150);
    if (path[pathLength - 3] == 'R' && path[pathLength - turnLeft();
                                            1] == 'L' && shortDone == 0) { }
    pathLength -= 3; if (path[readLength] == 'R') {
      path[pathLength] = 'B'; digitalWrite(leftMotor1, HIGH);
      shortDone = 1; digitalWrite(leftMotor2, LOW);
    } digitalWrite(rightMotor1, HIGH);
    if (path[pathLength - 3] == 'S' && path[pathLength - digitalWrite(rightMotor2, LOW);
                                            1] == 'L' && shortDone == 0) {
      delay(150);
      pathLength -= 3; turnRight();
      path[pathLength] = 'R';
    }
    shortDone = 1; if (path[readLength] == 'S') {
    } digitalWrite(leftMotor1, HIGH);
    if (path[pathLength - 3] == 'S' && path[pathLength - digitalWrite(leftMotor2, LOW);
                                            1] == 'S' && shortDone == 0) {
      digitalWrite(rightMotor1, HIGH);
      pathLength -= 3; digitalWrite(rightMotor2, LOW);
      path[pathLength] = 'B'; delay(150);
      shortDone = 1; straight();
    }
  }
  if (path[pathLength - 3] == 'L' && path[pathLength - readLength++;
                                          1] == 'L' && shortDone == 0) { }
  pathLength -= 3; replay();
  path[pathLength] = 'S';
}




shortDone = 1; void endMotion() {
} digitalWrite(led, LOW);
path[pathLength + 1] = 'D'; delay(500);
path[pathLength + 2] = 'D'; digitalWrite(led, HIGH);
pathLength++; delay(200);
} digitalWrite(led, LOW);




void replay()
{
  delay(200);
  readSensors(); digitalWrite(led, HIGH);
  if (leftFarReading < 200 && rightFarReading < 200)
  {
    delay(500);
    straight(); endMotion();
  }
  else
  {

    if (path[readLength] == 'D')
    {
      occurred just currect it and again compile and if no
      digitalWrite(leftMotor1, HIGH); error then we click the tools menu and select typeof
      digitalWrite(leftMotor2, LOW); board and port and next to click the upload button.
      digitalWrite(rightMotor1, HIGH);
      These are the steps to code compile and transfer the
      digitalWrite(rightMotor2, LOW);
      program from computer to Freeduino board.
      delay(100);
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);
      endMotion();
    }

    else if (path[readLength] == 'L') {
      digitalWrite(leftMotor1, HIGH);
    }
  }
}
}
