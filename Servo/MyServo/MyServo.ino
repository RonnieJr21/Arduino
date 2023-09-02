#include <Servo.h>
int left_pin = 24;
int right_pin = 23;
int servo = 5;

int led = 22;
Servo myservo;
void setup() {
  Serial.begin(9600);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  myservo.attach(5);


  // put your setup code here, to run once
}

void loop() {
  int degrees = myservo.read();
  Serial.println(digitalRead(23));
  Serial.println(digitalRead(24));
  
  if(digitalRead(23) == 1 && digitalRead(24) == 1){
    myservo.write(degrees);
  }
  else{
    while(digitalRead(23) == 0){
      degrees ++;
      Serial.println("23");
      myservo.write(degrees);
      digitalWrite(led, HIGH);
      delay(10);
  
    }
    while(digitalRead(24) == 0){
      degrees--;
      Serial.println("24");
      myservo.write(degrees);
      digitalWrite(led, HIGH);
      delay(10);
      

    }
    digitalWrite(led, LOW);
  }
  
  
  // put your main code here, to run repeatedly:

}
