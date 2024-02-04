#include "sensor.h"

Sensor::Sensor()
{
}

bool Sensor::start()
{
  Printer::printMessage("Start sensor...");

  Wire.begin();

  if (begin() != 0) //Begin returns 0 on a good init
  {
    Printer::printMessageLine("error");
    while (1)
      ;
  }

  Printer::printMessageLine("online!");
  return true;
}

bool Sensor::calibrate()
{
  startRanging();

  while (!checkForDataReady())
  {
    delay(1);
  }

  zeroDistance = getDistance() - 10; //Get the result of the measurement from the sensor
  clearInterrupt();
  stopRanging();

  Printer::printMessage("Calibrated distance: ");
  Printer::printMessageLine(String(zeroDistance));

  return true;
}

void Sensor::startObserv()
{
  Printer::printMessageLine("Start observe");
  startRanging(); //Write configuration bytes to initiate measurement
}

void Sensor::stopObserv()
{
  stopRanging();
  Printer::printMessageLine("Stop observe");
}

bool Sensor::triggered()
{
  while (!checkForDataReady())
  {
    delay(1);
  }

  int distance = getDistance();

  clearInterrupt();

  return distance < zeroDistance;
}