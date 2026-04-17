
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLfZnsZ08w"
#define BLYNK_DEVICE_NAME "DCmotor and Servo"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
#define APP_DEBUG
// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7
#include "BlynkEdgent.h"
//#include <Servo.h>
//Servo myservo;
#include <ESP32Servo.h> 
Servo myservo;  // create servo object to control a servo
int servoPin = 5;      // GPIO pin used to connect the servo control (digital out)
#define motor1 13  //D13
#define motor2 12  //D12
int hold=0;
int release1=0;
int val=0;
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
  hold = param.asInt(); // assigning incoming value from pin V1 to a variable
 if (hold==1)
{
    myservo.write(180);
    Serial.println("hold on");
     delay(100);
  }
}
BLYNK_WRITE(V4)
{
  release1 = param.asInt(); // assigning incoming value from pin V1 to a variable
 if (release1==1)
{
  
    myservo.write(20);
    delay(100);
    Serial.println("Release");
  }
}


BLYNK_WRITE(V5)
{
  val=param.asInt();
  if (val>0){
   myservo.write(val);
   Serial.println(val);
   delay(200);
  }
}











void setup()
{
  Serial.begin(115200);
  delay(100);


  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);// Standard 50hz servo
  myservo.attach(servoPin);   // attaches the servo on pin 18 to the servo object
                                         // using SG90 servo min/max of 500us and 2400us
                                         // for MG995 large servo, use 1000us and 2000us,
                                         // which are the defaults, so this line could be
                                         // "myservo.attach(servoPin);" 
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  //During Starting all Relays should TURN OFF
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();


  
}
