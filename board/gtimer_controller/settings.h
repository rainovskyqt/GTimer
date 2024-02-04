#ifndef SETTINGS_H
#define SETTINGS_H

#include "EEPROM.h"

#define MODE 0
#define SSID 4

class Settings{

  public:

    Settings() {
      loadSettings();
    };

    void loadSettings(){
      EEPROM.begin(512);

      // EEPROM.get(SSID, _ssid);
      EEPROM.get(MODE, _mode);

      EEPROM.end();
    }

    Mode lastMode(){
      return _mode;
    }

    void setLastMode(Mode mode){
      _mode = mode;
      EEPROM.begin(512);
      EEPROM.put(MODE, _mode);
      EEPROM.commit();
      EEPROM.end();
    }

    const char* ssid(){
      return _ssid;      
    }

    const char* password(){
      return _password;
    }

    const int freezTime(){
      return _freezTime;
    }

  private:
    Mode _mode;
    const char* _ssid = "Gtimer";
    const char* _password = "Gtimer123";
    const int _freezTime = 50;
};

#endif //SETTINGS_H