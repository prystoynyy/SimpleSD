#include "../src/SimpleSD.h"
#include <SimpleSD.h>
#include <string.h>

/*
 *  Writing data to file
 */

char* FILE_NAME = "data.csv";
const int CS_PIN = 4;

void setup()
{
        Serial.begin(9600);
        SimpleSD* simpleSD = new SimpleSD(CS_PIN);
        if (!simpleSD->Init()) {
                Serial.println("Initialization failed!");
                return;
        }

        char data[] = {'F', 'O', 'R',' ', 'T', 'E', 'S', 'T'};
        if(simpleSD->IsInit()){
           bool isSuccessRecord = simpleSD->WriteFile(FILE_NAME, data, true);
           if(isSuccessRecord){
             Serial.println("Record is success");
           }
           else{
             Serial.println("Record is fail");
           }
        }
}

void loop()
{
}
