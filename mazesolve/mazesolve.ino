void setup()
{
  int button;     initialize(); //this code call the calibration code to see how the line looks to the sensors
  maze_solve(); //calling maze solving code
  while (1);  // infintie loop to run after the robot has solved the maze
}
void initialize()
{
  int count; // used as a timer
  int sensors[5]; // an array to hold sensor values
  wait_for_button_release(button);
  delay_ms(1000);
  for (count = 0; count < 80; count++) //calibration of sensors
  { if (count < 20 || count >= 60)
      set_motors(40, -40);
    else    set_motors(-40, 40);
    calibrate_line_sensors(IR_EMITTERS_ON);
    delay_ms(20);
  }
  set_motors(0, 0);
  wait_for_button_release(button);
}   //code to follow a line
void drive()  {
  int last_proportional = 0;
  long integral = 0;
  while (1)
  { unsigned int sensors[5];
    unsigned int position = read_line(sensors, IR_EMITTERS_ON);
    int proportional = ((int)position) - 2000;   // Compute the derivative (change) and integral (sum) of the   // position. This code is borrowed from Pololu library for PID line following.
    int derivative = proportional - last_proportional;
    integral += proportional;
    // Remember the last position.
    last_proportional = proportional;   // Compute the difference between the two motor power settings,   //
    m1 - m2.  If this is a positive number the robot will turn   // to the left.  If it is a negative number, the robot will   // turn to the right, and the magnitude of the number determines   // the sharpness of the turn.
    int power_difference = proportional / 20 + integral / 10000 + derivative * 3 / 2; // Compute the actual motor settings.  We never set either motor   // to a negative value.
    const int max = 150; // the maximum speed
    if (power_difference > max)
      power_difference = max;
    if (power_difference < -max)
      power_difference = -max;
    if (power_difference < 0)
      set_motors(max + power_difference, max);
    else    set_motors(max, max - power_difference);
    if (sensors[1] < 100 && sensors[2] < 100 && sensors[3] < 100)
    { return;
    }
    else if (sensors[0] > 200 || sensors[4] > 200)    {
      // Found an intersection.
      return;
    }
  }
}
// code for turning the robot
void turn(char dir)
{ switch (dir)
  {
    case 'Left':
      set_motors(-100, 100);
      delay_ms(75);
      break;
    case 'Right':
      set_motors(100, -100);
      delay_ms(75);
      break;
    case 'Back':
      set_motors(100, -100);
      delay_ms(150);
      break;
    case 'Stop': //do nothing
      break;
  }
}
//code for solving the maze
void maze_solve()
{
  while (1)
  {
    drive();
    set_motors(100, 100);
    delay_ms(10);
    unsigned char found_left = 0;
    unsigned char found_straight = 0;
    unsigned char found_right = 0;
    unsigned int sensors[5];
    read_line(sensors, IR_EMITTERS_ON);
    if (sensors[0] > 100)
      found_left = 1;
    if (sensors[4] > 100)
      found_right = 1;
    set_motors(40, 40);
    delay_ms(200);
    read_line(sensors, IR_EMITTERS_ON);
    if (sensors[1] > 200 || sensors[2] > 200 || sensors[3] > 200)
      found_straight = 1;
    if (sensors[1] > 600 && sensors[2] > 600 && sensors[3] > 600)
      break;
    unsigned char dir = select_turn(found_left, found_straight, found_right);
    turn(dir);
  }
  while (1)
  {
    set_motors(0, 0);
  }
  //Smooth Acceleration/Deceleration
  unsigned long prevTime = get_ms();
  int currentSpeed = 0;
  int targetSpeed = 0;
  while (1)
  {
    if (get_ms() - prevTime >= 10)
    {
      prevTime = get_ms();
      if (currentSpeed < targetSpeed)
      {
        currentSpeed += acceleration;
        if (currentSpeed > targetSpeed)
          currentSpeed = targetSpeed;
      }
      if (currentSpeed > targetSpeed)
      {
        currentSpeed -= deceleration;
        if (currentSpeed < targetSpeed)
          currentSpeed = targetSpeed;
      }
      set_motors(currentSpeed);
    }   // rest of main loop goes here } Shared with Memoires for Android http://market.android.com/details?id=net.nakvic.dromoris http://sites.google.com/site/drodiary/
  }
}
}


