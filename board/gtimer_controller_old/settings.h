#include "EEPROM.h"

int modeAdress = 0;

class Settings{

  public:

  Settings() {};

    void setLastMode(int mode){
      EEPROM.begin(512);
      EEPROM.write(modeAdress, mode);
      EEPROM.commit();
      EEPROM.end();
    }

    int lastMode(){
      EEPROM.begin(512);
      int mode = EEPROM.read(modeAdress);
      EEPROM.end();
      return mode;
    }

};