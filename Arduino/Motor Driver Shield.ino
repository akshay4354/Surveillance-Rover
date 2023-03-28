#include<AFMotor.h>
AF_DCMotor mot1(1);
AF_DCMotor mot2(2);
AF_DCMotor mot3(3);
AF_DCMotor mot4(4);

int val;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int sense=840;
  val = analogRead(A0);

  if(val>=sense){
    front();
  }
  else{
    val=analogRead(A1);
    {
      if(val>=sense){
        back();  
      }
      else{
        val=analogRead(A2);
        if(val>=sense){
          left();
        }
        else{
          val=analogRead(A3);
          if(val>=sense){
            right();
          }
          else{
            Stop();
          }
        }
      }
    }
    
  }

}

void front(){
  mot1.setSpeed(255);
  mot2.setSpeed(255);
  mot3.setSpeed(255);
  mot4.setSpeed(255);

  mot1.run(FORWARD);
  mot2.run(FORWARD);
  mot3.run(FORWARD);
  mot4.run(FORWARD);
}

void back(){
  mot1.setSpeed(255);
  mot2.setSpeed(255);
  mot3.setSpeed(255);
  mot4.setSpeed(255);

  mot1.run(BACKWARD);
  mot2.run(BACKWARD);
  mot3.run(BACKWARD);
  mot4.run(BACKWARD);
}

void left(){
  mot1.setSpeed(255);
  mot2.setSpeed(255);
  mot3.setSpeed(255);
  mot4.setSpeed(255);

  mot1.run(FORWARD);
  mot2.run(FORWARD);
  mot3.run(BACKWARD);
  mot4.run(BACKWARD);
}
void right(){
  mot1.setSpeed(255);
  mot2.setSpeed(255);
  mot3.setSpeed(255);
  mot4.setSpeed(255);

  mot1.run(BACKWARD);
  mot2.run(BACKWARD);
  mot3.run(FORWARD);
  mot4.run(FORWARD);
}

void Stop()
{
  mot1.setSpeed(255);
  mot2.setSpeed(255);
  mot3.setSpeed(255);
  mot4.setSpeed(255);

  mot1.run(RELEASE);
  mot2.run(RELEASE);
  mot3.run(RELEASE);
  mot4.run(RELEASE);
}
