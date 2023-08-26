#include <Arduino.h>

#define BLYNK_TEMPLATE_ID "TMPLkXp8LKre"
#define BLYNK_DEVICE_NAME "ROBOTIC ARM"
#define BLYNK_AUTH_TOKEN "j0th05kzShpaseDsYLvcamSAgViP7aap"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Servo.h>

// Your WiFi credentials. 
// Set password to "" for open networks.
char ssid[] = "PiHOME";
char pass[] = "87654321";
Servo CLAW, WRIST, SHOLDER, ELBOW, PALM, BASE;


byte posWRIST = 0;
byte posCLAW = 0;
byte posSHOLDER = 0;
byte posELBOW = 0;
byte posPalm = 0;
byte posBase = 0;

int servoSpeed = 5; // Increase for faster movement, decrease for slower movement

// Define a function to move the servo gradually
void moveServo(Servo &servo, byte &pos, int targetPos) {
  if (pos != targetPos) {
    if (pos < targetPos) {
      pos += servoSpeed; // Increment position for acceleration
      if (pos > targetPos) {
        pos = targetPos; // Ensure we don't overshoot the target
      }
    } else {
      pos -= servoSpeed; // Decrement position for deceleration
      if (pos < targetPos) {
        pos = targetPos; // Ensure we don't overshoot the target
      }
    }
    servo.write(pos);
    delay(15); // Adjust this delay as needed
  }
}


BLYNK_WRITE(V0) {
  int val = param.asInt();
  moveServo(CLAW, posCLAW, val);
}

BLYNK_WRITE(V1) {
  int val = param.asInt();
  moveServo(WRIST, posWRIST, val);
}

BLYNK_WRITE(V2) {
  int val = param.asInt();
  moveServo(SHOLDER, posSHOLDER, val);
}

BLYNK_WRITE(V3) {
  int val = param.asInt();
  moveServo(ELBOW, posELBOW, val);
}

BLYNK_WRITE(V4) {
  int val = param.asInt();
  moveServo(PALM, posPalm, val);
}

BLYNK_WRITE(V5) {
  int val = param.asInt();
  moveServo(BASE, posBase, val);
}


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  CLAW.attach(25);
  WRIST.attach(26);
  SHOLDER.attach(27);
  ELBOW.attach(14);
  PALM.attach(12);
  BASE.attach(23);
}

void loop()
{
  Blynk.run();
}
