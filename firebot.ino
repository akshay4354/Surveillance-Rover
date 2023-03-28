#include <Servo.h>


#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
const int rs=13;
const int fs=9;
const int ls=2;
bool fire=false;
char command;
Servo name_servo;                  // Define any servo name

int servo_position = 0 ;


void setup()
{   pinMode(fs,INPUT);
 pinMode(rs,INPUT);
 pinMode(ls,INPUT);
  Serial.begin(9600);name_servo.attach (10);  
   //myservo.write(90);//Set the baud rate to your Bluetooth module.
   
}

void loop(){
  int fval=digitalRead(fs);
 int rval=digitalRead(rs);
  int lval=digitalRead(ls);
  if(fval==1 && lval==1 &&rval==1)
  {
    Serial.println("no fire");
    int sensi=1023;
    int v=analogRead(A0);
    Serial.println(v);
    if (v>=sensi)
    {
      Serial.println("forward");
      forward();
      
    }else
    {
      v=analogRead(A1);
      if(v>=sensi){
        Serial.println("back");
        back();
      }else{
        v=analogRead(A2);
        if(v>=sensi){
          Serial.println("left");
          left();
        }else{
          v=analogRead(A3);
          if (v>=sensi){
            Serial.println("right");
            right();
          }else{
            Serial.println("stop");
            Stop();
          }
        }
      }
    }
  
  }
  else if(fval==0)
  {
    Serial.println("fs");
   forward();
   fire=true;
  }
  else if(lval==0)
  {
   left();
   
  }
  else

  {
   
    right();
     
  }
  delay(300);
  while(fire==true)
  {
    putoff();
  }
}
void putoff()
  {
    delay(500);
    Stop();
    for (servo_position = 50; servo_position <=180; servo_position +=1){

    name_servo.write(servo_position);
    delay(10);
  }

  for (servo_position=180; servo_position >= 50; servo_position -=1){

    name_servo.write(servo_position);
    delay(10);
  }
   name_servo.write(90);
     fire=false;
  }
void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(255);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
