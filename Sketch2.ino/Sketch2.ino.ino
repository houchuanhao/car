#include "Servo.h"
int left_on = 16;
int left_back = 17;
int right_on = 14;
int right_back = 15;
int Trig = 8;
int Echo = 9;
int change = 0;
int middleDistance = 30;
int rightDistance = 0;
int leftDistance = 0;
Servo myServo;
void LeftForword()
{
  digitalWrite(left_back, LOW);
  digitalWrite(left_on, HIGH);
}
void LeftBack()
{
  digitalWrite(left_on, LOW);
  digitalWrite(left_back, HIGH);

}
void RightForword()
{
  digitalWrite(right_back, LOW);
  digitalWrite(right_on, HIGH);
}
void RightBack()
{
  digitalWrite(right_back, HIGH);
  digitalWrite(right_on, LOW);
}
void forword()
{
  LeftForword();
  RightForword();
}
void left()
{
  LeftBack();
  RightForword();
}
void right()
{
  LeftForword();
  RightBack();
}
void back()
{
  LeftBack();
  RightBack();
}
void stop()
{
  digitalWrite(left_on, 0);
  digitalWrite(left_back, 0);
  digitalWrite(right_on, 0);
  digitalWrite(right_back, 0);

}
float get_cm()
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  int cm = pulseIn(Echo, HIGH) / 58.0; //
  cm = (int(cm * 100.0)) / 100.0; //
  return cm;
}

void setup()
{

  /* add setup code here */
  //Serial.begin(9600);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  myServo.attach(10);
  myServo.write(90);
  delay(1000);
  /*
  left();
  delay(5000);
  right();
  delay(5000);
  back();
  delay(5000);
  forword();
  delay(5000);
  */


}
void loop()
{
  forword();
  int x=myServo.read();
  if (x != 90)
  {
    myServo.write(90);
    delay(500);
  }
  middleDistance = get_cm();
  if (middleDistance <= 30)
  {
    stop();
    delay(500);
    myServo.write(5);
    delay(1000);
    rightDistance = get_cm();
    //delay(1000);
    myServo.write(175);
    delay(1000);
    leftDistance = get_cm();
    myServo.write(90);
    delay(1000);
    if (leftDistance < 30 && rightDistance<30)
    {
      back();
      delay(1000);
    }
    if (rightDistance > leftDistance)
    {
      right();
      delay(350);
    }
    else  
    {
      left();
      delay(350);
    }
  }
  else
    forword();
}
