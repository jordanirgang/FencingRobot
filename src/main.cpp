#include <Arduino.h>
#include "ArduinoL289n.h"
#include "holonomicDriver.h"
#include "Adafruit_PWMServoDriver.h"
#include "SPI.h"

#include "pca9685.h"


//FWD SET
#define ALPHA_IN1 8
#define ALPHA_IN2 9
#define BETA_IN1 10
#define BETA_IN2 11

//BWD SET
#define CHARLIE_IN1 24
#define CHARLIE_IN2 22
#define DELTA_IN1 23
#define DELTA_IN2 25



CustomArduino::L289n* alphaM = new CustomArduino::L289n(ALPHA_IN1,ALPHA_IN2,12);
CustomArduino::L289n* betaM= new CustomArduino::L289n(BETA_IN1,BETA_IN2,12);
CustomArduino::L289n* charlieM= new CustomArduino::L289n(CHARLIE_IN1,CHARLIE_IN2,12);
CustomArduino::L289n* deltaM= new CustomArduino::L289n(DELTA_IN1,DELTA_IN2,30);
Generic::Holonomic chasis;

//handle arm
Adafruit_PWMServoDriver pwmDriver = Adafruit_PWMServoDriver();
CustomArduino::ChannelPCA9685 channel1(0,180,0);
uint8_t servonum = 0;

void driveWheels();
void driveWheelsB();
void chasisSquare();
void servoTest();
void setup() {
  // put your setup code here, to run once:
  alphaM->SetUp();
  betaM->SetUp();
  charlieM->SetUp();
  deltaM->SetUp();
  Serial.begin(9600);
  //alphaM.DriveFWD();*&
  chasis = Generic::Holonomic (alphaM,betaM,charlieM,deltaM);

  //pwm  driver setup
  pwmDriver.begin();
  pwmDriver.setOscillatorFrequency(27000000);
  pwmDriver.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  //channel setup
  channel1.Attach(&pwmDriver);
  
  //pwmDriver.setPWM(0,0,2048);


  
}

void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= SERVO_FREQ;   // Analog servos run at ~60 Hz updates
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("achasis drive");

  //chasis.DriveFWD();
  //delay(1000);
  //chasisSquare();

  //chasis.DriveFWDLFT();
  //delay(1000);
  //chasis.DriveBWDLFT();
  //delay(1000);
  ///chasis.DriveFWDRGT();
  //delay(1000);
  //chasis.DriveBWDRGT(); 
  
  servoTest();
  
  
}

void servoTest(){
  //need to write degrees
  for(int i = 0; i< 180;i++){
    channel1.WriteDeg(i);
    Serial.println(i);
    delay(10);
  }
   for(int i = 180; i> 0;i--){
    channel1.WriteDeg(i);
    Serial.println(i);
    delay(10);
  }  Serial.println(channel1.WhereIThinkIAm());
}

void chasisSquare(){
  chasis.DriveFWD();
  delay(1000);
  chasis.DriveLFT();
  delay(1000);
  chasis.DriveBWD();
  delay(1000);
  chasis.DriveRGT();
  delay(1000);
}

void driveWheels(){
  alphaM->DriveFWD();
  betaM->DriveFWD();
  charlieM->DriveFWD();
  deltaM->DriveFWD();
}

void driveWheelsB(){
  alphaM->DriveBWD();
  betaM->DriveBWD();
  charlieM->DriveBWD();
  deltaM->DriveBWD();
}

