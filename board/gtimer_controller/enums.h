#ifndef ENUMS_H
#define ENUMS_H


#include <map>

// Режим в котором работает контролер
enum Mode {
  Single = 1,   // Одиночный
  Start,        // Стоит на страте
  Finish        //Стоит на финише
};

// Статус устройства

enum Status{
  BOOT = 1,
  WAIT,
  READY,
  ERROR,
  CALIBRATE
};

#endif  // ENUMS_H