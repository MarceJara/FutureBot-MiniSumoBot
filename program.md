---
layout: page
title: Coding

#TODOs:
#- Explain more the code used.
#- Show the video of demostration.

---
To control our robot and make it win, we will need to tell it so. In that case, we will need to program its movements and actions. Below, you will see the code to make the combat robot work.


First, we need to define the variables and tools we will use to run our program.
```c++
const int AIN1 = 12;
const int AIN2 = 3;
const int BIN1 = 4;
const int BIN2 = 5;
const int STBY = 6;
const int PWMA = 9;
const int PWMB = 10;
const int Trig = 7;
const int Echo = 8;
const int LED = 11;
float time;
float distance;

enum direction{ CLOCKWISE, COUNTERCLOCKWISE };

// Headers
void stop_after(int time_delay = 0);
void set_motor_speed(int speed = 150);
```

Then, we have to configure and set how the arduino should perform.
```c++
void setup(){
    // Configuration for motor driver ports
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);

    // Configuration for ultrasonic port
    pinMode(Trig, OUTPUT);
    pinMode(Echo, INPUT);
    pinMode(LED, OUTPUT);

    digitalWrite(STBY, HIGH);
    digitalWrite(Trig, LOW);

    // Mandatory initial delay
    digitalWrite(LED, HIGH);
    delay(5000);
    digitalWrite(LED, LOW);

    set_motor_speed(200);
}
```

Next, we will program the actions that the robot will execute when turn on.
```c++
void loop(){
    // Calculation of distance by ultrasonic sensor
    digitalWrite(Trig, HIGH);
    delayMicroseconds(20);
    digitalWrite(Trig, LOW);
    time = pulseIn(Echo, HIGH);
    distance = time * 0.017175;

    // Action logic
    rotate(CLOCKWISE);
    if (distance < 25)
    {
    stop_after(0);
    delay(150);
    forward();
    stop_after(200);
    }
}
```

Finally, we have to define the functions that we used in loop to make it work.
```c++
void reverse(){
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);

    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
}

void forward(){
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);

    set_motor_speed(200);
}

void stop_after(int time_delay){
    delay(time_delay);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
}

void rotate(direction dir){
    digitalWrite(AIN1, dir ? HIGH : LOW);
    digitalWrite(AIN2, dir ? LOW : HIGH);

    digitalWrite(BIN1, dir ? LOW : HIGH);
    digitalWrite(BIN2, dir ? HIGH : LOW);

    set_motor_speed(100);
}

void set_motor_speed(int speed){
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
}
```
