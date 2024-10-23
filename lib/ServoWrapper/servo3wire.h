#pragma once
#include "motor.h"
#include "pingroup.h"

PinGroup<float> pwmControll;


namespace Generic{
class Servo:Motor{
    private:
        PinGroup<int> pwmPin;
    public:
        Servo(const int &pwmPin);

        void DriveFWD();
        void DriveBWD();
        void DriveFWD(const int& dutyCyclePerc);
        void DriveBWD(const int& dutyCyclePerc);
        void Brake();

        void Write2Deg(const int& degrees);
};
};