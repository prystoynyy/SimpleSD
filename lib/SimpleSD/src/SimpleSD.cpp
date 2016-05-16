#include "SimpleSD.h"

const int SimpleSD::CS_PIN = 4;

void SimpleSD::writeLog(char* log){
        if(!this->writeLog_) {
                return;
        }
        if(!this->isSerialInit_) {
                Serial.begin(9600);
                this->isSerialInit_ = true;
        }
        Serial.println(log);
}

SimpleSD::SimpleSD() : SimpleSD::SimpleSD(SimpleSD::CS_PIN){
}

SimpleSD::SimpleSD(int cs_pin){
        this->cs_pin_ = cs_pin;
        this->isInit_ = false;
        this->writeLog_ = false;
        this->isSerialInit_ =false;
}
bool SimpleSD::Init(){
        this->isInit_ = SD.begin(this->cs_pin_);
        return this->isInit_;
}

bool SimpleSD::IsInit(){
  return this->isInit_;
}

void SimpleSD::ShowLog(){
  this->writeLog_ = true;
}
void SimpleSD::HideLog(){
  this->writeLog_ = false;
}
char* SimpleSD::ReadFile(char* fileName){
  char* resultText = new char[255];
  return resultText;
}
bool WriteFile(char* fileName, char* data, bool override);
bool CopyFile(char* orgFileName, char* copyFileName);
