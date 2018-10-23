//A program that turns a LED on when you touch a piece of tin foil.

//Import a library from the Arduino folder
#include <CapacitiveSensor.h>

//Select the two pins that will act as a capacitor
CapacitiveSensor capSensor = CapacitiveSensor(4,2);
CapacitiveSensor capSensor2 = CapacitiveSensor(8,7);

//Insert the minimum value provided by the sensor to detect the touch
int threshold = 800; const int buzzerPin = 12; const int LED = 11;


void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(LED, OUTPUT);
}


void loop() {
  //Read the sensor value
  long sensorValue1 = capSensor.capacitiveSensor(30);
  long sensorValue2 = capSensor2.capacitiveSensor(30);
  Serial.println(sensorValue1);
  
  //Touch detected
  if (sensorValue1 > threshold) {
   //Turn on the led
    tone(buzzerPin, 600);
    digitalWrite(LED,HIGH);
  }
  //Touch undetected
  else if(sensorValue2 > threshold) {
   //Turn on the led
    tone(buzzerPin, 400);
    digitalWrite(LED,HIGH);
  }
  //Touch undetected
  else {
    //Turn off the led
   noTone(buzzerPin);
   digitalWrite(LED,LOW);
   }

}

