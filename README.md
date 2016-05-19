SimpleSD
=========

Library for working with SD module

How use
-----------------------

**1. Connect joystick module to arduino**:


<img src="http://www.getmicros.net/wp-content/uploads/2014/01/arduino-and-sdcard_bb.png" height=200>

**2. Write code**:

```cpp
#include "SimpleSD.h"

SimpleSD* simpleSD = new SimpleSD(CS_PIN);
char* data;
if (!simpleSD->Init()) {
      data = simpleSD->ReadFile(FILE_NAME);
}
//................................
simpleSD->WriteFile(OTHER_FILE_NAME, data, true);
//................................
simpleSD->CopyFile(FILE_NAME, COPY_FILE_NAME)
```
