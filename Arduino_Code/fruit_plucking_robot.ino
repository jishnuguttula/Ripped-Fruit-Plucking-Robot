/*
Project Title: Ripped Fruit Plucking Robot

Author: Jishnu Guttula

Description:
This project is an ESP32-based fruit plucking robot developed
for agricultural automation applications.

The system uses DC motors for robot movement, servo motors
for arm and gripper control, and an actuator mechanism for
lifting and positioning operations.

The robot is controlled through the Blynk IoT platform using
WiFi communication with ESP32.

Features:

* ESP32 WiFi control
* Blynk mobile app integration
* DC motor movement control
* Servo motor-based arm movement
* Actuator-based lifting mechanism
* IoT-enabled robotic automation

Technologies Used:
ESP32, Blynk, Servo Motors, Actuator, Arduino IDE,
Embedded Systems
*/


#define BLYNK_TEMPLATE_ID "TMPL3Cs_sxWXw"
#define BLYNK_TEMPLATE_NAME "RobotNew"
#define BLYNK_AUTH_TOKEN "cT-LMUNtrTy0TlafmT0kPpvt0WNpr1FQ"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h> // Corrected servo library

char auth[] = "cT-LMUNtrTy0TlafmT0kPpvt0WNpr1FQ";

// Motor Pins
#define MOTOR1A 5 //5
#define MOTOR1B 18 //18
#define MOTOR2A 19 //19
#define MOTOR2B 21 //21
#define MOTOR3A 13 //13
#define MOTOR3B 12 //12
#define MOTOR4A 14 //14
#define MOTOR4B 27 //27
#define PWMM 4

// Servo Pins
#define SERVO1_PIN 26
#define SERVO2_PIN 25
#define SERVO3_PIN 33

Servo servo1;
Servo servo2;
Servo servo3;

void setup()
{
  Serial.begin(9600);
  pinMode(PWMM, OUTPUT);
  analogWrite(PWMM, 130);


  pinMode(MOTOR1A, OUTPUT);
  pinMode(MOTOR1B, OUTPUT);
  pinMode(MOTOR2A, OUTPUT);
  pinMode(MOTOR2B, OUTPUT);
  pinMode(MOTOR3A, OUTPUT);
  pinMode(MOTOR3B, OUTPUT);
  pinMode(MOTOR4A, OUTPUT);
  pinMode(MOTOR4B, OUTPUT);

  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);

  digitalWrite(MOTOR1A, LOW);
  digitalWrite(MOTOR1B, LOW);
  digitalWrite(MOTOR2A, LOW);
  digitalWrite(MOTOR2B, LOW);
  digitalWrite(MOTOR3A, LOW);
  digitalWrite(MOTOR3B, LOW);
  digitalWrite(MOTOR4A, LOW);
  digitalWrite(MOTOR4B, LOW);

    #define BLYNK_AUTH_TOKEN "YOUR_TOKEN"
Blynk.begin(auth, "YOUR_WIFI_NAME", "YOUR_WIFI_PASSWORD");
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1)
{
  int y = param[0].asInt();

  // Forward and Backward Movement
  if (y > 200)
  {
    Serial.println("Moving Forward");
    digitalWrite(MOTOR3A, HIGH);
    digitalWrite(MOTOR3B, LOW);
    digitalWrite(MOTOR4A, HIGH);
    digitalWrite(MOTOR4B, LOW);
  }
  else if (y < 100)
  {
    Serial.println("Moving Backward");
    digitalWrite(MOTOR3A, LOW);
    digitalWrite(MOTOR3B, HIGH);
    digitalWrite(MOTOR4A, LOW);
    digitalWrite(MOTOR4B, HIGH);
  }
  else
  {
    Serial.println("Stop");
    digitalWrite(MOTOR3A, LOW);
    digitalWrite(MOTOR3B, LOW);
    digitalWrite(MOTOR4A, LOW);
    digitalWrite(MOTOR4B, LOW);
  }
}

BLYNK_WRITE(V2)
{
  int x = param[0].asInt();

  // Left and Right Movement
  if (x > 200)
  {
    Serial.println("Moving Right");
    digitalWrite(MOTOR3A, HIGH);
    digitalWrite(MOTOR3B, LOW);
    digitalWrite(MOTOR4A, LOW);
    digitalWrite(MOTOR4B, LOW);
  }
  else if (x < 100)
  {
    Serial.println("Moving Left");
    digitalWrite(MOTOR3A, LOW);
    digitalWrite(MOTOR3B, LOW);
    digitalWrite(MOTOR4A, HIGH);
    digitalWrite(MOTOR4B, LOW);
  }
  else
  {
    Serial.println("Stop");
    digitalWrite(MOTOR3A, LOW);
    digitalWrite(MOTOR3B, LOW);
    digitalWrite(MOTOR4A, LOW);
    digitalWrite(MOTOR4B, LOW);
  }
}

BLYNK_WRITE(V3)
{
  int z = param[0].asInt();

  // Up and Down Movement
  if (z > 200)
  {
    Serial.println("Moving Up");
    digitalWrite(MOTOR1A, HIGH);
    digitalWrite(MOTOR1B, LOW);
  }
  else if (z < 100)
  {
    Serial.println("Moving Down");
    digitalWrite(MOTOR1A, LOW);
    digitalWrite(MOTOR1B, HIGH);
  }
  else
  {
    Serial.println("Stop");
    digitalWrite(MOTOR1A, LOW);
    digitalWrite(MOTOR1B, LOW);
  }
}

BLYNK_WRITE(V4)
{
  int z = param[0].asInt();

  // Up and Down Movement
  if (z > 200)
  {
    Serial.println("Moving Up");
    digitalWrite(MOTOR2A, HIGH);
    digitalWrite(MOTOR2B, LOW);
  }
  else if (z < 100)
  {
    Serial.println("Moving Down");
    digitalWrite(MOTOR2A, LOW);
    digitalWrite(MOTOR2B, HIGH);
  }
  else
  {
    Serial.println("Stop");
    digitalWrite(MOTOR2A, LOW);
    digitalWrite(MOTOR2B, LOW);
  }
}

BLYNK_WRITE(V5)
{
  int angle1 = param.asInt();
  servo1.write(angle1);
  Serial.print("Servo 1 Angle: ");
  Serial.println(angle1);
}

BLYNK_WRITE(V6)
{
  int angle2 = param.asInt();
  servo2.write(angle2);
  Serial.print("Servo 2 Angle: ");
  Serial.println(angle2);
}

BLYNK_WRITE(V7)
{
  int angle3 = param.asInt();
  servo3.write(angle3);
  Serial.print("Servo 3 Angle: ");
  Serial.println(angle3);
}