#include "../lib/SimpleSD/src/SimpleSD.h"
#include <SimpleSD.h>
#include <string.h>


char* ORIGINAL_FILE_NAME = "data.csv";

void setup()
{
        Serial.begin(9600);
        SimpleSD* simpleSD = new SimpleSD(4);

        if (!simpleSD->Init()) {
                Serial.println("initialization failed!");
                return;
        }
        simpleSD->IsInit();
        char* result = simpleSD->ReadFile(ORIGINAL_FILE_NAME);

        Serial.print(result);

}

void loop()
{
}
