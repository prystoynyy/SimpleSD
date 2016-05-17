#include "../src/SimpleSD.h"
#include <SimpleSD.h>
#include <string.h>

/*
 *  Make copy of file
 */

char* FILE_NAME = "data.csv";
char* COPY_FILE_NAME = "copy-data.csv";
const int CS_PIN = 4;

void setup()
{
        Serial.begin(9600);
        SimpleSD* simpleSD = new SimpleSD(CS_PIN);
        if (!simpleSD->Init()) {
                Serial.println("Initialization failed!");
                return;
        }
        if(simpleSD->IsInit()){
           bool isSuccessCopy = simpleSD->CopyFile(FILE_NAME, COPY_FILE_NAME);
           if(isSuccessCopy){
             Serial.println("Copying is success");
           }
           else{
             Serial.println("Copying is fail");
           }
        }
}

void loop()
{
}
