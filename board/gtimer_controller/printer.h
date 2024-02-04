#ifndef PRINTER_H
#define PRINTER_H

#include <ESP8266WiFi.h>

class Printer
{
  public:
    static void printMessage(String message);
    static void printMessageLine(String message);
};

#endif  // PRINTER_H
