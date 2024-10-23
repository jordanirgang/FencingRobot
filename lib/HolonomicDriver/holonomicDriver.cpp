#include "holonomicDriver.h"
#include "Arduino.h"

Generic::Holonomic::Holonomic()
{
}

Generic::Holonomic::Holonomic(Motor *sternPort, Motor *sternStarboard, Motor *aftPort, Motor *aftStarboard)
{
    this->sternPort = sternPort;
    this->sternStarboard = sternStarboard;
    this->aftPort = aftPort;
    this->aftStarboard = aftStarboard;
    Serial.println("build");
}

Generic::Holonomic::~Holonomic()
{
    //delete this->sternPort;
    //delete this->sternStarboard;
    //delete this->aftPort;
    //delete this->aftStarboard;
}


void Generic::Holonomic::DriveFWD()
{
    Serial.println("drive");
    this->sternPort->DriveFWD();
    this->aftPort->DriveFWD();

    this->sternStarboard->DriveFWD();
    this->aftStarboard->DriveFWD();
}

void Generic::Holonomic::DriveBWD()
{
    this->sternPort->DriveBWD();
    this->aftPort->DriveBWD();

    this->sternStarboard->DriveBWD();
    this->aftStarboard->DriveBWD();
}

void Generic::Holonomic::DriveLFT()
{
    this->sternPort->DriveFWD();
    this->aftPort->DriveBWD();

    this->sternStarboard->DriveBWD();
    this->aftStarboard->DriveFWD();    
}

void Generic::Holonomic::DriveRGT()
{
    this->sternPort->DriveBWD();
    this->aftPort->DriveFWD();

    this->sternStarboard->DriveFWD();
    this->aftStarboard->DriveBWD();  
}

void Generic::Holonomic::DriveFWDLFT()
{
    this->sternPort->DriveFWD();
    this->aftPort->Brake();

    this->sternStarboard->Brake();
    this->aftStarboard->DriveFWD();  

}

void Generic::Holonomic::DriveBWDLFT()
{
    this->sternPort->Brake();
    this->aftPort->DriveBWD();

    this->sternStarboard->DriveBWD();
    this->aftStarboard->Brake(); 
}

void Generic::Holonomic::DriveFWDRGT()
{
    this->sternPort->Brake();
    this->aftPort->DriveFWD();

    this->sternStarboard->DriveFWD();
    this->aftStarboard->Brake(); 
}

void Generic::Holonomic::DriveBWDRGT()
{
    this->sternPort->DriveBWD();
    this->aftPort->Brake();

    this->sternStarboard->Brake();
    this->aftStarboard->DriveBWD();  

}
