#include <Servo.h>
Servo servoMain; // Define our Servo
int trigpin = 3;
int echopin = 5;
int distance;
float duration;
float cm;

void setup()
{
Serial.begin(9600);
servoMain.attach(11); // servo on digital pin 11
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
}

void loop()
{
digitalWrite(trigpin, LOW);
delay(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
duration = pulseIn(echopin, HIGH);
cm = (duration/58.82);
distance = cm;
Serial.print("Distance: ");
Serial.println(distance);

if(distance<40 && distance>0)
{
servoMain.write(180); // Turn Servo back to center position (180 degrees)
delay(300);
}

else{
servoMain.write(0);
delay(50);
}

}
