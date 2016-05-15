#include <SPI.h>
#include <SD.h>

class SimpleSD{
private:
  int _cs_pin;
  bool _writeLog;
  bool _isInit;
  bool _isSerialInit;
  void _writeLog(char* log);
public:
  SimpleSD();
  SimpleSD(int cs_pin);
  bool Init();
  void ShowLog();
  void HideLog();
  char* ReadFile(char* fileName);
  bool WriteFile(char* fileName, char* data, bool override);
  bool CopyFile(char* orgFileName, char* copyFileName)
}
