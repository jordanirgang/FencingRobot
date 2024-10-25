#include "servo3wire.h"
#include <math.h>

Generic::Servo::Servo(const int &pwmPin)
{
    this->pwmPin.pin = pwmPin;
    this->pwmPin.value = DEFAULT_DEGREES;//keeping as degrees
    this->maxDegrees = DEFAULT_MAX_DEGREES;
    this->minDegrees = DEFAULT_MIN_DEGREES;
    this->speed = 1;
}

Generic::Servo::Servo(const int &pwmPin, const float &maxDegrees, const float &minDegrees)
{
    this->pwmPin.pin = pwmPin;
    this->pwmPin.value = DEFAULT_DEGREES;
    this->maxDegrees = maxDegrees;
    this->minDegrees = minDegrees;
    this->speed = 1;
}

void Generic::Servo::DriveFWD()
{
    this->pwmPin.value += this->speed;
    this->WriteDeg(this->pwmPin.value);
}

void Generic::Servo::DriveBWD()
{
    this->pwmPin.value -= this->speed;
    this->WriteDeg(this->pwmPin.value);
}

/*!
 *  @brief drive fwd fucntion that I'm still confused  on why I'm keeping
 *  @param dutyCyclePerc The percentage, given  out of 100 for the pwm wave to stay on
 *  TODO: this makes no sense I will fix or change class structure for efficincy
 */
void Generic::Servo::DriveFWD(const int &dutyCyclePerc)
{
    this->pwmPin.value = dutyCyclePerc;
    this->WriteDeg(this->pwmPin.value);
}

void Generic::Servo::Brake()
{
    //stay at this value
    this->WriteDeg(this->pwmPin.value);
}

/*!
 *  @brief main servo usage where degrees will be input, and transformed into percent
 *  @param degrees
 *  TODO: this makes no sense I will fix or change class structure for efficincy
 */
void Generic::Servo::WriteDeg(const float &degrees)
{
    this->pwmPin.value = max(this->maxDegrees, min(degrees, this->minDegrees));;
    int percent = static_cast<int>((degrees-this->minDegrees)/this->maxDegrees);
    //this.speed = percent
    this->SetSpeed(percent);
}

void Generic::Servo::WriteRad2Deg(const float &radians)
{  
    float deg = radians *M_PI/180 ;
    this->WriteDeg(static_cast<int>(deg) % FULL_CIRCLE_DEGREE);
}







