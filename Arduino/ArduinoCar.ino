#include <SoftwareSerial.h>
SoftwareSerial SUART(11, 10); //SRX, STX

//STATUS: DETECTION IS WORKING

void setup()
{
  Serial.begin(9600);
  SUART.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(1, INPUT);
}

void Stop() {
  digitalWrite(2,LOW);
  analogWrite(5,0);
  digitalWrite(4,HIGH);
  analogWrite(6,0);
}

void Move_Backward(int speed) {
  digitalWrite(2,LOW);
  analogWrite(5,speed);
  digitalWrite(4,HIGH);
  analogWrite(6,speed);
}

void Rotate_Left(int speed) {
  digitalWrite(2,LOW);
  analogWrite(5,speed);
  digitalWrite(4,LOW);
  analogWrite(6,speed);
}

void Rotate_Right(int speed) {
  digitalWrite(2,HIGH);
  analogWrite(5,speed);
  digitalWrite(4,HIGH);
  analogWrite(6,speed);
}

void Move_Forward(int speed) {
  digitalWrite(2,HIGH);
  analogWrite(5,speed);
  digitalWrite(4,LOW);
  analogWrite(6,speed);
}

void loop()
{
  char y;
  if (SUART.available()!=0)
  {
    char y = SUART.read();
    Serial.println(y);
    switch (y) {
      case 'P': // Pedestrian Sign
        Move_Forward(45);
        break;
      case 'G': // GO
        Move_Forward(85);
        break;
      case 'S': // STOP SIGN
        Stop();
        break;
      case 'U': // U-TURN SIGN
        Rotate_Left(80);
        break;
      case 'N': //NULL
        Stop();
        break;
      case 'R': //RIGHT TURN SIGN
        Rotate_Right(60);
        break;
      case 'T':
        Stop();
        break;
    }
  }
}