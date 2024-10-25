#pragma once
#include "Adafruit_PWMServoDriver.h"
#include "servo3wire.h"
#include "ArduinoAbstract.h"

#define SERVOMIN  90 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  525 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define MICROSECONDS_LENGTH 1000000
namespace CustomArduino{
class ChannelPCA9685:public Generic::Servo,public ArduinoAbstarct{
    private:
        uint8_t channelIdx;
        Adafruit_PWMServoDriver* parent;
        int resolution = 4096; //bits in a pulse
        void ServoPulseCalculator(double pulse);
    public:
        friend class Generic::Servo;
        using Generic::Servo::Servo;

        void SetSpeed(const int& dutyCyclePerc)override;
        void Attach(Adafruit_PWMServoDriver* parent);
        void WriteDeg(const float& degrees)override;
        void SetUp()override;
        void Update()override;

        //TODO: see I can move pulse maker to servo base class
};

};