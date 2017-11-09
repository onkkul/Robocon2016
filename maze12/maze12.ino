68
}
Serial.print(
  "
  \
n"
);
Serial.print(
  "
  \
n"
);
}
//=====Print LHW Function=====
void
PrintFFA()
{
  //=====Print
  -
  out t
  he FFA == == =
    x = 0;
  y = 0;
  while
  ((x < 11) && (i < 33))
  {
    Serial.print(FFA[y][x]);
    Serial.print(
      ' '
    );
    x++;
    if
    (x > 10)
    {
      Serial.print(
        "
        \
n"
      );
      y++;
      x = 0;
      if
      (y > 10)
      {
        x = 11;
      }
    }
  }
  Serial.print(
    "
    \
n"
  );
  Serial.print(
    "
    \
n"
  );
}
//=====stop Function=====
void
stop()
{
  //set the speed
  speed_L = 0;
  speed_R = 0;
}
//=====move straight Function=====
void
straight()
{
  move = 0;
  while
  (mov
      e < 9)
    //Read rensors
    left_sensor = analogRead(0);
  front_sensor = analogRead(1);
  right_sensor = analogRead(2);
  //set both motor high
  digitalWrite(dir_L, HIGH);
  digitalWrite(dir_R, HIGH);
  speed_L = 60;
  speed_R = 60;
  //mov
  e slightly to the left if the right sensor is near to the wall
  if
    (right_sensor > active)
    {
      speed_L = 0;
      speed_R = 60;
    }
  //move slightly to the right if the left sensor is near to the wall
  if
  (left_sensor > active)
  {
    speed_L = 60;
    speed_R = 0;
  }
  analogWrite(pwm_L, speed_L);
  analogWrite(pwm_R, speed_R);
  move++;
  delay(100);
  69
}
//=====turn let Function=====
void
turnLeft()
{
  //set the speed
  speed_L = 60;
  speed_R = 60;
  //set the direction
  digitalWri
  te(dir_L, LOW);
  digitalWrite(dir_R, HIGH);
  analogWrite(pwm_L, speed_L);
  analogWrite(pwm_R, speed_R);
  delay(600);
}
void
turnRight()
{
  //set the speed
  speed_L = 60;
  speed_R = 60;
  //set the direction
  digitalWrite(dir_L, HIGH);
  digital
  Write(dir_R, LOW);
  analogWrite(pwm_L, speed_L);
  analogWrite(pwm_R, speed_R);
  delay(600);
}
//=====u turn Function=====
void
uTurn()
{
  turnLeft();
  delay(1000);
}
//=====Remot control Function=====
void
RemoteControl()
{
  RC = 0;
  w
  hile
  (RC == 0)
  {
    if
    (irrecv.decode(&results))
      //wate for result
    {
      Serial.println(results.value, HEX);
      //print result
      irrecv.resume();
      if
      (results.value == 0xFFA25D) {
        RC = 1;
      }
      //if this kee pressed RC will be high
    }
  }
}
void
setup()
{
  Serial.begin(9600);
  // for serial monitor output
  irrecv.enableIRIn();
  // enable reciver
  //set the outputs pins
  pinMode(pwm_L, OUTPUT);
  pinMode(pwm_R, OUTPUT);
  pinMode(dir_L, OUTPUT);
  pinMode(dir_R, OUTPUT)
  ;
  delay(500);
  Serial.print(
    "
    \
n"
  );
  //=====MAZE Titel=====
  Serial.print(
    "MAZE"
  );
  Serial.print(
    "
    \
n"
  );
  PrintMaze();
  //Call Print Maze Function
  70
  //=====LHW Titel=====
  Serial.print(
    "Fill Flood Algorithem"
  );
  Serial.print('\t');
  current_value = FFA[yp][xp];
  PrintFFA();
  //Call Print FFA Function
  FFA[yp][xp] ='M';
    
    
}
void
loop()
{
  while
  (i < 40)
  {
    //Read rensors
    left_sensor = analogRead(0);
    front_sensor = analogRead(1);
    right_sensor = analogRead(2);
                   
    //set all cells values to any high number, just to compare
    S_value = 125;
    L_value = 125;
    R_value = 125;
    D_value = 125;
    //if the current direction is straight
    if
    (direc =='S')
    {
      if
      (front_sensor
          > wall_threshold) 
        FFA[yp
            -
            1][xp] ==
        '
        -
        '
      }
      //check
      front sensor
      else
      { FFA[yp
            -
            1][xp] ==
        ' '
      }
      if
      (left_sensor > wall_threshold) {
        FFA[yp][xp
                -
                1] ==
        '|'
      }
      //check left
      sensor
      else
      { FFA[yp][xp
                -
                1] ==
        ' '
      }
      if
      (right_sensor > wall_threshold) {
        FFA[yp][xp + 1
               ] ==
        '|'
      }
      //check
      right sensor
      else
      { FFA[yp][xp + 1] ==
        ' '
      }
      //only if there is no wall the cells values will be change to the fill flood
      value
      //else the cell value will be high 125
      if
      (FFA[yp
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      if
      (FFA[
            yp + 1][xp] ==
          ' '
      ) {
        D_value = FFA[yp + 2][xp];
      }
      if
      (FFA[yp][xp
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      //see if the robot needs to make a turn, and set the direction
      if
      (S_value <= L_valu
          e && S_value <= R_value && S_value != 125) {
        direc =
          'S'
          ;
      }
      else if
      (L_value <= S_value && L_value <= R_value && L_value != 125) {
        direc =
          'L'
          ;
        turnLeft();
      }
      //turn Left
      else if
      (R_value <= S_value && R_value <= L_value && R_value != 125) {
        direc =
          '
          R'
          ;
        turnRight();
      }
      //turn Right
      else
      { direc =
          'D'
          ; uTurn();
      }
      //u turn
    }
    //if the current direction is down
    else if
    (direc ==
        'D'
    )
    {
      if
      (front_sensor > wall_threshold) {
        FFA[yp + 1][xp] ==
        '
        -
        '
      }
      //check front sensor
      els
      e
      { FFA[yp + 1][xp] ==
        ' '
      }
      if
      (left_sensor > wall_threshold) {
        FFA[yp][xp + 1] ==
        '|'
      }
      //check left
      sensor
      else
      { FFA[yp][xp + 1] ==
        ' '
      }
      if
      (right_sensor > wall_threshold) {
        FFA[yp][xp
                -
                1] ==
        '|'
      }
      //check
      right sensor
      else
      { FFA[yp][xp
                -
                1] ==
        ' '
      }
      //only if there is no wall the cells values will be change to the fill flood
      value
      //else the cell value will be high 125
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_value = FFA[yp + 2][xp];
      }
      71
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      if
      (
        FFA[yp][xp
                -
                1] ==
        ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      if
      (FFA[yp
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      //see if the robot needs to make a turn, and set the direction
      if
      (D_value <= L_value && D_value <= R_value && D_value != 1
          25) {
        direc =
          'D'
          ;
      }
      else if
      (R_value <= D_value && R_value <= L_value && R_value != 125) {
        direc =
          'R'
          ;
        turnLeft();
      }
      //Turn Left
      else if
      (L_value <= D_value && L_value <= R_value && L_value != 125) {
        direc =
          'L'
          ;
        turnRight();
      }
      //Turn Right
      else
      { direc =
          'S'
          ; uTurn();
      }
      //u turn
    }
    //if the current direction is left
    else if
    (direc ==
        'L'
    )
    {
      if
      (front_sensor > wall_threshold) {
        FFA[yp][xp
                -
                1] ==
        '
        -
        '
      }
      //check front sensor
      else
      { FFA[yp][xp
                -
                1] ==
        ' '
      }
      if
      (l
          eft_sensor > wall_threshold) {
        FFA[yp + 1][xp] ==
        '|'
      }
      //check left
      sensor
      else
      { FFA[yp + 1][xp] ==
        ' '
      }
      if
      (right_sensor > wall_threshold) {
        FFA[yp
            -
            1][xp] ==
        '|'
      }
      //check
      right sensor
      else
      { FFA[yp
            -
            1][xp] ==
        ' '
      }
      //only if there is no wall the cells va
      lues will be change to the fill flood
      value
      //else the cell value will be high 125
      if
      (FFA[yp][xp
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      if
      (FFA[yp
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA
                  [yp
                   -
                   2][xp];
      }
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_value = FFA[yp + 2][xp];
      }
      //see if the robot needs to make a turn, and set the direction
      if
      (L_value <= S_value && L_value <= D_value && L_value != 125) {
        direc =
          'L'
          ;
      }
      else if
      (S_value <
          = L_value && S_value <= D_value && S_value != 125) {
        direc =
          'S'
          ;
        turnRight();
      }
      //Turn Right
      else if
      (D_value <= L_value && D_value <= S_value && D_value != 125) {
        direc =
          'D'
          ;
        turnLeft();
      }
      //Turn Left
      else
      { direc =
          'R'
          ; uTurn();
      }
      //u turn
    }
    else if
    (direc ==
        'R'
    )
    {
      if
      (front_sensor > wall_threshold) {
        FFA[yp][xp + 1] ==
        '
        -
        '
      }
      //check front sensor
      else
      { FFA[yp][xp + 1] ==
        ' '
      }
      if
      (left_sensor > wall_threshold) {
        FFA[yp
            -
            1][xp] ==
        '|'
      }
      //check left
      sensor
      else
      { FFA[yp_1][xp] ==
        ' '
      }
      if
      (right_sensor > wall_threshold) {
        FFA[yp + 1][xp] ==
        '|'
      }
      //check
      right sensor
      else
      { FFA[yp + 1][xp] ==
        ' '
      }
      //only if there is no wall the cells values will be change to the fill flood
      value
      //else the cell value will b
      e high 125
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      if
      (FFA[yp
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_value = FFA[yp + 2][xp];
      }
      if
      (FFA[yp][xp
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      //see if the robot needs to make a turn, and set the direction
      if
      (R_value <= S_value && R_value <= D_value && R_value != 125) {
        direc =
          'R'
          ;
      }
      else if
      (D_value <= R_value && D_value <= S_value && D_value != 125) {
        direc =
          'D'
          ;
        turnRight();
      }
      //T
      urn Right
      else if
      (S_value <= R_value && S_value <= D_value && S_value != 125) {
        direc =
          'S'
          ;
        turnLeft();
      }
      //Turn Left
      else
      { direc =
          'L'
          ; uTurn();
      }
      //u turn
    }
    72
    PrintFFA();
    //Call Print FFA
    Function
    if
    (xp == 3 && y
        p == 3) {
      i = 50;
    }
    //stop if reach the goal
    if
    (i != 50)
      //if not reaching
      the goal continue
    {
      //if the direction is straight, check if the value needs to be updated
      if
      (direc ==
      'S'
      )
      {
        if
        (S_value > current_va
        lue) {
          current_value = S_value + 1;
        }
        FFA[yp][xp] = current_value;
        yp = yp
             -
             2;
      }
      //if the direction is down, check if the value needs to be updated
      else if
      (direc ==
          'D'
      )
      {
        if
        (
          D_value > current_value) {
          current_value = D_value + 1;
        }
        FFA[yp][xp] = current_value;
        yp = yp + 2;
      }
      //if the direction is left, check if the value needs to be updated
      else if
      (direc ==
          'L'
      )
      {
        if
        (L_value > current_value) {
          current_value = L_value + 1;
        }
        FFA[yp][xp] = current_value;
        xp = xp
             -
             2;
      }
      //if the direction is right, check if the value needs to be updated
      else if
      (direc ==
          'R'
      )
      {
        if
        (R_value > current_value) {
          current_value = R_value + 1;
        }
        FFA[yp][xp] = current_value;
        xp = xp + 2;
      }
      //just to make the caracter M  visible  on the result
      current_va
      lue = FFA[yp][xp];
      //store the current value in this integer
      FFA[yp][xp] =
        'M'
        ;
      //replace it with "M"
      straight();
      //move straight
      //delay(1000);
      stop()
      delay(50);
      i++;
      //continue
    }
  }
  //shorten p
  ath proccess
  Serial.println(
    "=========================="
  );
  //return the "a" value
  FFA[3][3] =
    'a'
    ;
  delay(200);
  PrintFFA();
  //Call Print FFA Function
  Serial.println(
    "=========================="
  );
  i = 0;
  //count
  er set to 0
  //set the algoreithm to start from the centre
  xp = 3;
  yp = 3;
  while
  (i < 40)
  {
    /////////these will be used after, for making the robot return back to
    /////////start position by it self
    //Read rensors
    73
    //left_sens
    or = analogRead(0);
    //front_sensor = analogRead(1);
    //right_sensor = analogRead(2);
    //set all cells values to any high number, just to compare
    S_value = 125;
    L_value = 125;
    R_value = 125;
    D_value = 125;
    //if t
    he current direction is straight
    if
    (direc ==
        'S'
    )
    {
      //only if there is no wall the cells values will be change to the fill flood
      value
      //else the cell value will be high 125
      if
      (FFA[yp
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_value = FFA[yp + 2][xp];
      }
      if
      (FFA[yp][xp
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      //see if the robot needs to make a turn, and set the direction
      if
      (S
          _value <= L_value && S_value <= R_value && S_value != 125) {
        direc =
          'S'
          ;
      }
      else if
      (R_value <= S_value && R_value <= L_value && R_value != 125) {
        direc =
          'R'
          ;
      }
      else if
      (L_value <= S_value && L_value <= R_value && L_value != 125) {
        direc =
          'L'
          ;
      }
      else
      { direc =
          'D'
          ; U_turn = 1;
      }
    }
    else if
    (direc ==
        'D'
    )
    {
      //only if there is no wall the cells values will be change to the fill flood
      value
      //else the cell value will be high 125
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_value =
          FFA[yp + 2][xp];
      }
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      if
      (FFA[yp][xp
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      if
      (FFA[yp
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      //see if the robot needs to make a turn, and set the
      direction
      if
      (D_value <= L_value && D_value <= R_value && D_value != 125) {
        direc =
          'D'
          ;
      }
      else if
      (L_value <= D_value && L_value <= R_value && L_value != 125) {
        direc =
          'L'
          ;
      }
      else if
      (R_value <= D_value && R_value <= L_value && R_value !=
          125) {
        direc =
          'R'
          ;
      }
      else
      { direc =
          'S'
          ; U_turn = 1;
      }
    }
    else if
    (direc ==
        'L'
    )
    {
      //only if there is no wall the cells values will be change to the fill flood
      value
      //else the cell value will be high 125
      if
      (FFA[yp][x
               p
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      if
      (FFA[yp
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_value = FFA[yp + 2][xp];
      }
      //see if the robot need
      s to make a turn, and set the direction
      if
      (L_value <= S_value && L_value <= D_value && L_value != 125) {
        direc =
          'L'
          ;
      }
      else if
      (S_value <= L_value && S_value <= D_value && S_value != 125) {
        direc =
          'S'
          ;
      }
      else if
      (D_value <= R_value && D_value
          <= S_value && D_value != 125) {
        direc =
          'D'
          ;
      }
      else
      { direc =
          'R'
          ; U_turn = 1;
      }
    }
    else if
    (direc ==
        'R'
    )
    {
      //only if there is no wall the cells values will be change to the fill flood
      value
      //else the cell value will be high
      125
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      if
      (FFA[yp
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_value = FFA[yp + 2][xp];
      }
      if
      (FFA[yp][xp
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      //see
      if the robot needs to make a turn, and set the direction
      74
      if
        (R_value <= S_value && R_value <= D_value && R_value != 125) {
          direc =
            'R'
            ;
        }
        else if
        (D_value <= R_value && D_value <= S_value && D_value != 125) {
          direc =
            'D'
            ;
        }
        else if
        (S_valu
            e <= R_value && S_value <= D_value && S_value != 125) {
          direc =
            'S'
            ;
        }
        else
        { direc =
            'L'
            ; U_turn = 1;
        }
    }
    PrintFFA();
    //Call Print FFA Function
    if
    (xp == 1 && yp == 5) {
      i = 50;
    }
    total = 0;
    if
    (S_valu
        e == 125) {
      total = total + 1;
    }
    if
    (D_value == 125) {
      total = total + 1;
    }
    if
    (L_value == 125) {
      total = total + 1;
    }
    if
    (R_value == 125) {
      total = total + 1;
    }
    if
    (total < 2)
    {
      U_turn = 0;
    }
    if
    (direc ==
        'S'
    )
    {
      if
      (S_value < FFA[yp][xp] && U_turn == 0)
      {
        FFA[yp
            -
            2][xp] = FFA[yp][xp] + 1;
      }
      yp = yp
           -
           2;
    }
    else if
    (direc ==
        'D'
    )
    {
      if
      (D_value < FFA[yp][xp] && U_t
          urn == 0)
      {
        FFA[yp + 2][xp] = FFA[yp][xp] + 1;
      }
      yp = yp + 2;
    }
    else if
    (direc ==
        'L'
    )
    {
      if
      (L_value < FFA[yp][xp] && U_turn == 0)
      {
        FFA[yp][xp
                -
                2] = FFA
                     [yp][xp] + 1;
      }
      xp = xp
           -
           2;
    }
    else if
    (direc ==
        'R'
    )
    {
      if
      (R_value < FFA[yp][xp] && U_turn == 0)
      {
        FFA[yp][xp + 2] = FFA[yp][xp] + 1;
      }
      xp = xp + 2;
    }
    i++;
  }
  i = 0;
  PrintFFA();
  Serial.println(
    "=========================="
  );
  i = 0;
  xp = 1;
  yp = 5;
  direc =
    'S'
    ;
  FFA[yp][xp] =
    'X'
    ;
  while
  (i < 40)
  {
    //R
    ead rensors
    left_sensor = analogRead(0);
    front_sensor = analogRead(1);
    right_sensor = analogRead(2);
    S_value = 125;
    L_value = 125;
    R_value = 125;
    D_value = 125;
    if
    (direc ==
        'S'
    )
    {
      if
      (FFA[y
           p
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_value = FFA[yp + 2][xp];
      }
      if
      (FFA[yp][xp
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      if
      (S_value <= L_va
          lue && S_value <= R_value && S_value != 125) {
        direc =
          'S'
          ;
      }
      else if
      (L_value <= S_value && L_value <= R_value && L_value != 125) {
        direc =
          'L'
          ;
        turnLeft();
      }
      //turn left
      else if
      (R_value <= S_value && R_value <= L_value && R_value != 125) {
        direc =
          'R'
          ;
        turnRight();
      }
      //turn right
      else
      { direc =
          'D'
          ; uTturn();
      }
      //u turn
    }
    else if
    (direc ==
        'D'
    )
    {
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_value = FFA[yp + 2][xp];
      }
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      if
      (FFA[yp][xp
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      if
      (FFA[yp
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      if
      (D_value <= L_value && D_value <= R_value && D_value != 125) {
        direc =
          'D'
          ;
      }
      else if
      (R_value <= D_value && R_valu
          e <= L_value && R_value != 125) {
        direc =
          'R'
          ;
        turnLeft();
      }
      //turn left
      else if
      (L_value <= D_value && L_value <= R_value && L_value != 125) {
        direc =
          'L'
          ;
        turnRight();
      }
      //turn right
      else
      { direc =
          'S'
          ; uTturn();
      }
      //u turn
    }
    els
    e
    if
    (direc ==
        'L'
    )
    {
      if
      (FFA[yp][xp
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      if
      (FFA[yp
           -
           1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_val
        ue = FFA[yp + 2][xp];
      }
      if
      (L_value <= S_value && L_value <= D_value && L_value != 125) {
        direc =
          'L'
          ;
      }
      else if
      (S_value <= L_value && S_value <= D_value && S_value != 125) {
        direc =
          'S'
          ;
        turnRight();
      }
      //turn right
      else if
      (D_value <=
          L_value && D_value <= S_value && D_value != 125) {
        direc =
          'D'
          ;
        turnLeft();
      }
      //turn left
      else
      { direc =
          'R'
          ; uTturn();
      }
      //u turn
    }
    else if
    (direc ==
        'R'
    )
    {
      if
      (FFA[yp][xp + 1] ==
          ' '
      ) {
        R_value = FFA[yp][xp + 2];
      }
      if
      (F
          FA[yp
             -
             1][xp] ==
          ' '
      ) {
        S_value = FFA[yp
                      -
                      2][xp];
      }
      if
      (FFA[yp + 1][xp] ==
          ' '
      ) {
        D_value = FFA[yp + 2][xp];
      }
      if
      (FFA[yp][xp
               -
               1] ==
          ' '
      ) {
        L_value = FFA[yp][xp
                          -
                          2];
      }
      if
      (R_value <= S_value && R_value <= D_value && R_value != 125) {
        direc =
          'R'
          ;
      }
      else if
      (D_value <= R_value && D_value <= S_value && D_value != 125) {
        direc =
          'D'
          ;
        turnRight();
      }
      //turn right
      else if
      (S_value <= R_value && S_value <= D_value && S_value != 125) {
        direc =
          'S'
          ;
        turnLeft();
      }
      //turn left
      else
      { direc =
          'L'
          ; uTturn();
      }
      //u turn
    }
    if
    (i != 50)
    {
      if
      (direc ==
          'S'
      )
        76
      {
        yp = yp
        -
        2;
      }
      else if
      (direc ==
          'D'
      )
      {
        yp = yp + 2;
      }
      else if
      (direc ==
          'L'
      )
      {
        xp = xp
             -
             2;
      }
      else if
      (direc ==
          'R'
      )
      {
        xp = xp + 2;
      }
      FFA[yp][xp] =
        'X'
        ;
      i++;
      PrintFFA();
      //Cal
      l Print FFA Function
      straight();
      //move straight
      //delay(1000);
      stop()
      delay(50);
      if
      (xp == 3 && yp == 3) {
        i = 50;
      }
    }
  }
  i = 0;
  PrintFFA();
  //Call Print FFA Function
  while
  (1);
}
