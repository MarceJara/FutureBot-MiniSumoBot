const int AIN1 = 2;
const int AIN2 = 3;
const int BIN1 = 4;
const int BIN2 = 5;
const int STBY = 6;
const int PWMA = 9;// 7;
const int PWMB = 10;//8;
const int Trig = 7;//9;
const int Echo = 8;//10;
const int LED = 11;
const int IR_DO = 12;
const int IR_AO = A1;

float time;
float distance;
int out_of_bounds;

enum direction
{
  CLOCKWISE,
  COUNTERCLOCKWISE
};

// Headers
void stop_after(int time_delay = 0);
void set_motor_speed(int speed = 60);

void setup()
{
  Serial.begin(9600);
  // Configuration for motor driver ports
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  set_motor_speed();

  // Configuration for ultrasonic port
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(LED, OUTPUT);

  // Configuration for IR sensor ports
  pinMode(IR_DO, INPUT);
  pinMode(IR_AO, INPUT);

  digitalWrite(STBY, HIGH);
  digitalWrite(Trig, LOW);

  // Mandatory initial delay
  digitalWrite(LED, HIGH);
  delay(5000);
  digitalWrite(LED, LOW);

  // Enable interruptions
  interrupts();
  attachInterrupt(digitalPinToInterrupt(IR_DO), avoid_bounds, LOW);
}

void loop()
{
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

void avoid_bounds(void)
{
  rotate(CLOCKWISE);
  stop_after(150);
  forward();
  stop_after(1000);
}

void reverse()
{
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void forward()
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);

  set_motor_speed(80);
}

void stop_after(int time_delay)
{
  delay(time_delay);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void rotate(direction dir)
{
  digitalWrite(AIN1, dir ? HIGH : LOW);
  digitalWrite(AIN2, dir ? LOW : HIGH);

  digitalWrite(BIN1, dir ? LOW : HIGH);
  digitalWrite(BIN2, dir ? HIGH : LOW);

  set_motor_speed(50);
}

void set_motor_speed(int speed)
{
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
}

// USE WHEN PWM NOT AVAILABLE
// void rotate_steps(sentido dir, int time_delay)
// {
//   digitalWrite(AIN1, dir ? HIGH : LOW);
//   digitalWrite(AIN2, dir ? LOW : HIGH);

//   digitalWrite(BIN1, dir ? LOW : HIGH);
//   digitalWrite(BIN2, dir ? HIGH : LOW);

//   delay(time_delay);
//   stop_after(0);
//   delay(time_delay);
// }
