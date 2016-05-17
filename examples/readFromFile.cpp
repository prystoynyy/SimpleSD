#include "../src/SimpleSD.h"
#include <SimpleSD.h>
#include <string.h>

/*
 *  Reading data from file to char* variable
 *  and send her to Serial
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
        if(simpleSD->IsInit()) {
                char* result = simpleSD->ReadFile(FILE_NAME);
                Serial.print(result);
        }
}

void loop()
{
}
