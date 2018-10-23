//A program that turns a LED on when you touch a piece of tin foil.

//Import a library from the Arduino folder
#include <CapacitiveSensor.h>

//Select the two pins that will act as a capacitor
CapacitiveSensor capSensor = CapacitiveSensor(4,2);

//Insert the minimum value provided by the sensor to detect the touch
int threshold = 800; const int ledPin = 12; const int ledPinRed = 13;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
}


void loop() {
  //Read the sensor value
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);
  
  //Touch detected
  if (sensorValue > threshold) {
   //Turn on the led
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPinRed, LOW);
  }
  //Touch undetected
  else {
    //Turn off the led
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPinRed, HIGH);
  }
  delay(10);
}

