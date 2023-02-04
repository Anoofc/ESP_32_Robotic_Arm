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
Servo CLAW, WRIST, SHOLDER, ELBOW, servo5;


int posWRIST = 0;
int posCLAW = 0;
int posSHOLDER = 0;
int posELBOW = 0;

BLYNK_WRITE(V0)
{
  int val(param.asInt());
  while (posCLAW>val){
    CLAW.write(posCLAW);
    posCLAW--;              // tell servo to go to position in variable 'pos'
    delay(30);
  }
  while (posCLAW<val){
    CLAW.write(posCLAW);
    posCLAW++;              // tell servo to go to position in variable 'pos'
    delay(30);
  }
}
BLYNK_WRITE(V1)
{
  
  int val(param.asInt());
  while (posWRIST>val){
    WRIST.write(posWRIST);
    posWRIST--;              // tell servo to go to position in variable 'pos'
    delay(15);
  }
  while (posWRIST<val){
    WRIST.write(posWRIST);
    posWRIST++;              // tell servo to go to position in variable 'pos'
    delay(15);
  }
}

BLYNK_WRITE(V2)
{
  int val(param.asInt());
  while (posSHOLDER>val){
    SHOLDER.write(posSHOLDER);
    posSHOLDER--;              // tell servo to go to position in variable 'pos'
    delay(30);
  }
  while (posSHOLDER<val){
    SHOLDER.write(posSHOLDER);
    posSHOLDER++;              // tell servo to go to position in variable 'pos'
    delay(30);
  }
}

BLYNK_WRITE(V3)
{
  int val(param.asInt());
  while (posELBOW>val){
    ELBOW.write(posELBOW);
    posELBOW--;              // tell servo to go to position in variable 'pos'
    delay(30);
  }
  while (posELBOW<val){
    ELBOW.write(posELBOW);
    posELBOW++;              // tell servo to go to position in variable 'pos'
    delay(30);
  }
}
BLYNK_WRITE(V4)
{
  servo5.write(param.asInt());
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
  servo5.attach(12);
}

void loop()
{
  Blynk.run();
}
