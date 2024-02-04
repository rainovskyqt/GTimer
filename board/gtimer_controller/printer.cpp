#include "printer.h"

void Printer::printMessage(String message){
  Serial.print(message);
}

void Printer::printMessageLine(String message){
  Serial.println(message);
}
