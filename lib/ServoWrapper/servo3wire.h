#pragma once
#include "motor.h"
#include "pingroup.h"

#define DEFAULT_DEGREES 50
#define DEFAULT_MAX_DEGREES 180
#define DEFAULT_MIN_DEGREES 0

#define FULL_CIRCLE_DEGREE 360
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))


namespace Generic{
class Servo:public Motor{
    private:
        PinGroup<int> pwmPin;
    protected:
        float maxDegrees;
        float minDegrees;
    public:
        Servo(const int &pwmPin);
        Servo(const int &pwmPin,const float &maxDegrees, const float &minDegrees);

        void DriveFWD()override;
        void DriveBWD()override;
        void DriveFWD(const int& dutyCyclePerc)override;
        //void DriveBWD(const int& dutyCyclePerc)override;
        void Brake()override;

        virtual void WriteDeg(const float& degrees);
        virtual void WriteRad2Deg(const float& radians);
};
};