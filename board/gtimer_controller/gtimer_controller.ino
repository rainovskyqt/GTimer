#include "enums.h"
#include "settings.h"

#define ON HIGH
#define OFF LOW

void ICACHE_RAM_ATTR swichMode();   //Необходимо для добавления прерывания

const int modeBtnPin = D8;
Settings _settings;

int _currentMode;

void setup() {
  Serial.begin(115200);

  setPins();
  loadLastMode();
  
  switchModeLED();  
  setupInterrupts();
}

void loadLastMode(){
  _currentMode = _settings.lastMode();
  switchModeLED();
}

void loop() {

}

void setPins(){
  for(int i = Mode::Single; i < Mode::Finish + 1; i++){
    pinMode(ModeLED[i], OUTPUT);
    digitalWrite(ModeLED[i], OFF);
  }
  pinMode(modeBtnPin, INPUT);
}

void setupInterrupts()    // При появлении сигнала на modeBtnPin вызывается функци stopParking
{
  attachInterrupt(digitalPinToInterrupt(modeBtnPin), swichMode, RISING);
}

void swichMode() {
  if(_currentMode < Mode::Finish){
    _currentMode++;
  } else {
    _currentMode = Mode::Single;
  }

  switchModeLED();
  _settings.setLastMode(_currentMode);
}

void switchModeLED(){
  for(int i = Mode::Single; i < Mode::Finish + 1; i++){
    digitalWrite(ModeLED[i], OFF);
  }
  digitalWrite(ModeLED[_currentMode], ON);
}