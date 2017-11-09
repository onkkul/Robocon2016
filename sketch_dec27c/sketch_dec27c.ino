char select_turn(unsigned char found_left, unsigned char found_straight, unsigned char found_right)
{
  // Make a decision about how to turn.  The following code
  // implements a left-hand-on-the-wall strategy, where we always
  // turn as far to the left as possible.
  if(found_left)
    return 'L';
  else if(found_straight)
    return 'S';
  else if(found_right)
    return 'R';
  else
    return 'B';
} // end select_turn


// Path simplification.  The strategy is that whenever we encounter a
// sequence xBx, we can simplify it by cutting out the dead end.  For
// example, LBL -> S, because a single S bypasses the dead end
// represented by LBL.
void simplify_path()
{
  // only simplify the path if the second-to-last turn was a 'B'
  if(path_length < 3 || path[path_length-2] != 'B')
    return;

  int total_angle = 0;
  int i;
  for(i=1;i<=3;i++)
  {
    switch(path[path_length-i])
    {
      case 'R':
        total_angle += 90;
  break;
      case 'L':
  total_angle += 270;
  break;
      case 'B':
  total_angle += 180;
  break;
    }
  }

  // Get the angle as a number between 0 and 360 degrees.
  total_angle = total_angle % 360;

  // Replace all of those turns with a single one.
  switch(total_angle)
  {
    case 0:
  path[path_length - 3] = 'S';
  break;
    case 90:
  path[path_length - 3] = 'R';
  break;
    case 180:
  path[path_length - 3] = 'B';
  break;
    case 270:
  path[path_length - 3] = 'L';
  break;
  }

  // The path is now two steps shorter.
  path_length -= 2;
  
} // end simplify_path


// This function is called once, from the main loop
void MazeSolve()
{
  // Loop until we have solved the maze.
  while(1)
  {
    // FIRST MAIN LOOP BODY  
    follow_line();

    // Drive straight a bit.  This helps us in case we entered the
    // intersection at an angle.
    digitalWrite(dir_a, LOW);  
    analogWrite(pwm_a, 200);
    digitalWrite(dir_b, LOW);  
    analogWrite(pwm_b, 200);   
    delay(25); 

    // These variables record whether the robot has seen a line to the
    // left, straight ahead, and right, whil examining the current
    // intersection.
    unsigned char found_left=0;
    unsigned char found_straight=0;
    unsigned char found_right=0;
    
    // Now read the sensors and check the intersection type.
    line_position = qtrrc.readLine(sensorValues);

    // Check for left and right exits.
    if(sensorValues[0] < 200)
    found_left = 1;
    if(sensorValues[7] < 200)
    found_right = 1;

    // Drive straight a bit more - this is enough to line up our
    // wheels with the intersection.
    digitalWrite(dir_a, LOW);  
    analogWrite(pwm_a, 200);
    digitalWrite(dir_b, LOW);  
    analogWrite(pwm_b, 200);
    delay(drivePastDelay); 
  
    line_position = qtrrc.readLine(sensorValues);
    if(sensorValues[1] < 200 || sensorValues[2] < 200 || sensorValues[3] < 200 || sensorValues[4] < 200 || sensorValues[5] < 200 || sensorValues[6] < 200)
    found_straight = 1;

    // Check for the ending spot.
    // If all six middle sensors are on dark black, we have
    // solved the maze.
    if(sensorValues[1] < 600 && sensorValues[2] < 600 && sensorValues[3] < 600 && sensorValues[4] < 600 && sensorValues[5] < 600 && sensorValues[6] < 600)
  break;

    // Intersection identification is complete.
    // If the maze has been solved, we can follow the existing
    // path.  Otherwise, we need to learn the solution.
    unsigned char dir = select_turn(found_left, found_straight, found_right);

    // Make the turn indicated by the path.
    turn(dir);

    // Store the intersection in the path variable.
    path[path_length] = dir;
    path_length ++;

    // Simplify the learned path.
    simplify_path();
  }

  // Solved the maze!

  // Now enter an infinite loop - we can re-run the maze as many
  // times as we want to.
  while(1)
  {
    //  maybe you would like to add a blinking led or a beeper.
    //  we just have it waiting patiently to be placed back on the starting line.
    analogWrite(pwm_a, 0);  // stop both motors
    analogWrite(pwm_b, 0);
  
    // while(1){}; // uncomment this line to cause infinite loop to test if end was found if your robot never seems to stop

    // hold motors while robot is sitting on end point
    line_position = qtrrc.readLine(sensorValues);
    while(sensorValues[1] < 200 && sensorValues[2] < 200 && sensorValues[3] < 200 && sensorValues[4] < 200 && sensorValues[5] < 200 && sensorValues[6] < 200)
    {
      line_position = qtrrc.readLine(sensorValues);
      delay(50);
    }
 
    // hold until the start line is seen again when the robot has been placed there again
    while(1)
    {
      line_position = qtrrc.readLine(sensorValues);
      if(sensorValues[2] < 200 || sensorValues[3] < 200 || sensorValues[4] < 200 || sensorValues[5] > 200 && sensorValues[0] > 200 && sensorValues[1] > 200 && sensorValues[6] > 200 && sensorValues[7] > 200)
      break;
      delay(50);
    }
 
    // delay to give you time to let go of the robot
    delay(2000);

    // Re-run the now solved maze.  It's not necessary to identify the
    // intersections, so this loop is really simple.
    int i;
    for(i=0;i<path_length;i++)
    {
      // SECOND MAIN LOOP BODY  
      follow_line();

      // drive past intersection slightly slower and timed delay to align wheels on line
      digitalWrite(dir_a, LOW);  
      analogWrite(pwm_a, 200);
      digitalWrite(dir_b, LOW);  
      analogWrite(pwm_b, 200);
      delay(drivePastDelay); // tune time to allow wheels to position for correct turning

      // Make a turn according to the instruction stored in
      // path[i].
      turn(path[i]);
    }

    // Follow the last segment up to the finish.
    follow_line();

      // drive past intersection slightly slower and timed delay to align wheels on line
      digitalWrite(dir_a, LOW);  
      analogWrite(pwm_a, 200);
      digitalWrite(dir_b, LOW);  
      analogWrite(pwm_b, 200);
      delay(drivePastDelay); // tune time to allow wheels to position for correct turning
        
      // Now we should be at the finish!  Now move the robot again and it will re-run this loop with the solution again.  
 
  } // end running solved
  
}
