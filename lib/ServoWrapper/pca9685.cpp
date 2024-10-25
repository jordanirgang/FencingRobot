#include "pca9685.h"

//TODO:move to servo object
void CustomArduino::ChannelPCA9685::SetSpeed(const int &dutyCyclePerc)
{
    //using percentage, so 0-100
    float percent = dutyCyclePerc/100;
    this->parent->setPWM(this->channelIdx,0,this->resolution*percent);
}

void CustomArduino::ChannelPCA9685::Attach(Adafruit_PWMServoDriver *parent)
{
    this->parent = parent;
}

void CustomArduino::ChannelPCA9685::WriteDeg(const float& degrees){

    //convert degrees to percent
    int percent = static_cast<int>((degrees-this->minDegrees)/this->maxDegrees);
    SetSpeed(percent);
}

void CustomArduino::ChannelPCA9685::SetUp()
{
    //TODO:may not need this
}

void CustomArduino::ChannelPCA9685::Update()
{
    //TODO:may not need this

}
