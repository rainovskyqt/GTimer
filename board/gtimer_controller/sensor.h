#ifndef SENSOR_H
#define SENSOR_H

#include "SparkFun_VL53L1X.h"
#include <Wire.h>
#include "printer.h"

class Sensor : public SFEVL53L1X
{

  public:
  Sensor();

  bool start();
  bool calibrate();
  void startObserv();
  void stopObserv();
  bool triggered();

  private:
    int zeroDistance = 0;

};


#endif // SENSOR_H