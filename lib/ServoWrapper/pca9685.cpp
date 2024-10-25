#include "pca9685.h"
#include "Arduino.h"

// TODO:move to servo object
void CustomArduino::ChannelPCA9685::SetSpeed(const int &dutyCyclePerc)
{
    //using percentage, so 0-100
    double ratio = static_cast<double>(dutyCyclePerc) /100;
    uint16_t percent = static_cast<uint16_t>((SERVOMAX-SERVOMIN)*ratio + SERVOMIN);
    
    this->parent->setPWM(this->channelIdx,0,percent);
}

void CustomArduino::ChannelPCA9685::Attach(Adafruit_PWMServoDriver *parent)
{
    this->parent = parent;
}

void CustomArduino::ChannelPCA9685::WriteDeg(const float& degrees){

    //convert degrees to percent
    float percent = ((degrees-this->minDegrees)/this->maxDegrees);
    SetSpeed(static_cast<int>(percent*100));
}

void CustomArduino::ChannelPCA9685::SetUp()
{
    //TODO:may not need this
}

void CustomArduino::ChannelPCA9685::Update()
{
    //TODO:may not need this

}
