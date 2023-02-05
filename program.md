---
layout: page
title: Coding
---

To build our bot we will need the following materials. In some cases we will be able to sustitute some of them but that wil depend on our budget and level of exepertise in order to handle those modifications.

```arduino
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
