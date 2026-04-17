// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLfZnsZ08w"
#define BLYNK_DEVICE_NAME "DCmotor and Servo"
//#include <Servo.h>
//Servo myservo;
#define BLYNK_FIRMWARE_VERSION        "1.0.1"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
//#define BLYNK_DEBUG
//#define APP_DEBUG
#include <BlynkEdgent.h>
// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD

#define motor1 13  //D13
#define motor2 12  //D12



BlynkTimer timer2;


BLYNK_WRITE(V1)
{
  int motorClock = param.asInt(); // assigning incoming value from pin V1 to a variable
if (motorClock==1)
{
  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);
  }
  else
  {
     digitalWrite(motor1,LOW);
     digitalWrite(motor2,LOW); 
    }
}

BLYNK_WRITE(V2)
{
  int motorAnti = param.asInt(); // assigning incoming value from pin V1 to a variable
if (motorAnti==1)
{
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);
  }
  else
  {
     digitalWrite(motor1,LOW);
     digitalWrite(motor2,LOW); 
    }
}

BLYNK_WRITE(V3)
{
  int hold = param.asInt(); // assigning incoming value from pin V1 to a variable
 if (hold==1)
{
    //myservo.write(180);
     delay(15);
  }
}
BLYNK_WRITE(V4)
{
  int release1 = param.asInt(); // assigning incoming value from pin V1 to a variable
 if (release1==1)
{
    //myservo.write(0);
    delay(15);
  }
}


void setup()
{
  Serial.begin(115200);
//  myservo.attach(9); 
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  //During Starting all Relays should TURN OFF
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  BlynkEdgent.begin();
  // Setup a function to be called every 2 seconds
  timer2.setInterval(2000L, sendSensor);
}
void loop() {
    BlynkEdgent.run();
    timer2.run();
}
