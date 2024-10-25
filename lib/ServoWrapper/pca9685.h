#pragma once
#include "Adafruit_PWMServoDriver.h"
#include "servo3wire.h"
#include "ArduinoAbstract.h"

namespace CustomArduino{
class ChannelPCA9685:public Generic::Servo,public ArduinoAbstarct{
    private:
        int channelIdx;
        Adafruit_PWMServoDriver* parent;
        int resolution = 4096; //bits in a pulse
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