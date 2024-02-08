#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor LeftMotor(1);
AF_DCMotor RightMotor(2);

Servo steeringServo;

void setup() {
  
  Serial.begin(9600);
  steeringServo.attach(9);

  LeftMotor.setSpeed(200);
  RightMotor.setSpeed(200);

  LeftMotor.run(RELEASE);
  RightMotor.run(RELEASE);
}

void Forward() {
  LeftMotor.setSpeed(200);
  RightMotor.setSpeed(200);
  LeftMotor.run(FORWARD);
  RightMotor.run(FORWARD);
  Serial.println("Moving Forward");
}

void Backward() {
  LeftMotor.setSpeed(200);
  RightMotor.setSpeed(200);
  LeftMotor.run(BACKWARD);
  RightMotor.run(BACKWARD);
  Serial.println("Moving Backward");
}

void Stop() {
  LeftMotor.setSpeed(0);
  RightMotor.setSpeed(0);
  LeftMotor.run(RELEASE);
  RightMotor.run(RELEASE);
  Serial.println("Stopping");
}

void TurnLeft(){
  steeringServo.write(0);
  Serial.println("Turning Left");
}

void TurnRight(){
  steeringServo.write(0);
  Serial.println("Turning Right");
}

void Straight(){
  steeringServo.write(0);
  Serial.println("steering straight");
}


void loop() {
  // Waits for Commands from the Serial port
  while(Serial.available() == 0){}
  String Command = Serial.readString();
  Command.trim();
  if(Command == "Move Forward") {
    Forward();
  }
  if(Command == "STOP"){
    Stop();
  }
  if(Command == "Move Backward"){
    Backward();
  }
  if(Command == "Turn Left"){
    TurnLeft();
  }
  if(Command == "Turn Right"){
    TurnRight();
  }
  if(Command == "Go Straight"){
    Straight();
  }
}
