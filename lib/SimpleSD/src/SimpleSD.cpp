#include "SimpleSD.h"

void SimpleSD::_writeLog(char* log){
        if(!this->_isSerialInit) {
                Serial.begin(9600);
        }
}

SimpleSD::SimpleSD(): SimpleSD::SimpleSD(4){}

SimpleSD::SimpleSD(int cs_pin){
        this->_cs_pin = cs_pin;
        this->_isInit = false;
        this->_isSerialInit = false;
        this->_isSerialInit =false;
}
bool SimpleSD::Init(){
        this->_isInit = SD.begin(this->_cs_pin);
        return SD.begin(this->_cs_pin);
}
void ShowLog();
void HideLog();
char* ReadFile(char* fileName);
bool WriteFile(char* fileName, char* data, bool override);
bool CopyFile(char* orgFileName, char* copyFileName);
