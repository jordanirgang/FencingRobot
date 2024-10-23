#pragma once
#include "motor.h"

namespace Generic{
class Holonomic{
    protected:
        Motor *sternPort;
        Motor *sternStarboard;
        Motor *aftPort;
        Motor *aftStarboard;

    public:
    Holonomic();
    Holonomic(Motor *sternPort,Motor *sternStarboard,Motor *aftPort,Motor *aftStarboard);
    ~Holonomic();
    void DriveFWD();
    void DriveBWD();
    void DriveLFT();
    void DriveRGT();
    void DriveFWDLFT();
    void DriveBWDLFT();
    void DriveFWDRGT();
    void DriveBWDRGT();



};
};