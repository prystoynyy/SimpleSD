/*
 * SimpleSD - A tool for working with SD module for Arduino
 * By Vasyl Prystoynyy
 */

#ifndef __SimpleSD_H__
#define __SimpleSD_H__

#include <SPI.h>
#include <SD.h>


//Class for working with SD module.
class SimpleSD {
private:
        const static int CS_PIN;
        int cs_pin_;
        bool writeLog_;
        bool isInit_;
        bool isSerialInit_;
        void writeLog(char* log);
        void writelnLog(char* log);
        void writeLog(int number);
        void writelnLog(int number);
        bool isAllowLog();
public:
        SimpleSD();
        SimpleSD(int cs_pin);
        bool Init();
        bool IsInit();
        void ShowLog();
        void HideLog();
        char* ReadFile(char* fileName);
        bool WriteFile(char* fileName, char* data, bool override);
        bool CopyFile(char* orgFileName, char* copyFileName);
};
#endif
