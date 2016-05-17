#include "SimpleSD.h"

const int SimpleSD::CS_PIN = 4;

bool SimpleSD::isAllowLog(){
        if(!this->writeLog_) {
                return false;
        }
        if(!this->isSerialInit_) {
                Serial.begin(9600);
                this->isSerialInit_ = true;
        }
        return true;
}

void SimpleSD::writeLog(char* log){
        if(!this->isAllowLog()) {
                return;
        }
        Serial.print(log);
}

void SimpleSD::writelnLog(char* log){
        if(!this->isAllowLog()) {
                return;
        }
        Serial.println(log);
}

void SimpleSD::writeLog(int number){
        if(!this->isAllowLog()) {
                return;
        }
        Serial.print(number);
}

void SimpleSD::writelnLog(int number){
        if(!this->isAllowLog()) {
                return;
        }
        Serial.println(number);
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
        this->writelnLog("Reading file");
        File file = SD.open(fileName);
        if(!file) {
                return "";
        }
        int fileSize = file.size();
        char* resultText = new char[fileSize+1];
        this->writeLog("File size: ");
        this->writelnLog(fileSize);
        int i = 0;
        while (file.available()) {
                char c = file.read();
                resultText[i++] = c;
                this->writeLog(c);
        }
        this->writelnLog("");
        resultText[i] = '\0';
        file.close();
        this->writelnLog("File is closed");
        return resultText;
}
bool SimpleSD::WriteFile(char* fileName, char* data, bool override){
    this->writelnLog("Writing to file");
        File file = SD.open(fileName, FILE_WRITE);
        if(!file) {
                return false;
        }
        this->writeLog("Data: ");
        this->writelnLog(data);
        file.println(data);
        file.close();
        this->writelnLog("File is closed");
        return true;
}
bool SimpleSD::CopyFile(char* orgFileName, char* copyFileName){
        char* data = this->ReadFile(orgFileName);
        return this->WriteFile(copyFileName, data, false);
}
