#include <NewPing.h>

int trigger = 8;
int echo = 9;

int red = 25;
int green = 49;
int yellow = 47;

NewPing sonar(trigger, echo, 400);

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
  delay(50);

  // put your setup code here, to run once:
}

void loop()
{
  int distance = sonar.ping_cm();
  Serial.print("The distance is: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance > 0 && distance <= 50){
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);

  }
  if(distance > 50 && distance <= 200){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);

  }
  if(distance > 200 && distance <= 400){
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
  }
 
  delay(200);
  // put your main code here, to run repeatedly:
}
