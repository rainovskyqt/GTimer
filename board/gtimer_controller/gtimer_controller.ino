#include <ESP8266WiFi.h>
// #include <ESPAsyncTCP.h>

#include "enums.h"
#include "settings.h"
#include "printer.h"
#include "gwifi.h"
#include "sensor.h"

#define FIRMWARE_VERSION "0.0.1"

#define ON HIGH
#define OFF LOW

Settings _settings;
Mode _currentMode;

GWiFi* _gWifi;

const char* _ssid;
const char* _password;

IPAddress _localIP(192,168,4,1);
IPAddress _gateway(192,168,4,1);
IPAddress _subnet(255,255,255,0);
int _serverPort = 8008;

Sensor _distanceSensor;

bool _observe = false;
bool _started = false;

unsigned long _startTime;
unsigned long _time;
unsigned long _syncTime;     // Используется для синхронизации стартового и финишного датчиков
unsigned long _lastTrigged;
int _freezTime;

void setup() {
  Serial.begin(74480);
  delay(100);
  Printer::printMessage("Start load...");

  // _settings.setLastMode(Mode::Single);

  loadMode();
  loadWifiSettings();
  setupWifi();
  setupSensor();
  syncTime();

  _freezTime = _settings.freezTime();
  _lastTrigged = 0;

  Printer::printMessageLine("Loading complete");
}

void loadMode(){
  _currentMode = _settings.lastMode();
  Printer::printMessage("Current mode: ");
  Printer::printMessageLine((String)_currentMode);
}

void loadWifiSettings(){
  _ssid = _settings.ssid();
  _password = _settings.password();
  Printer::printMessage("Current ssid: ");
  Printer::printMessageLine(_ssid);
  Printer::printMessage("Current password: ");
  Printer::printMessageLine(_password);
}

void setupWifi(){
  _gWifi = new GWiFi(_localIP, _gateway, _subnet);
  _gWifi->startWifi(_currentMode, _ssid, _password);
}

void setupSensor(){
  _distanceSensor.start();
  _distanceSensor.startObserv();
  _distanceSensor.calibrate();
  _distanceSensor.stopObserv();
}

void syncTime(){
  if(_currentMode == Mode::Start){
    _syncTime = millis() - millis();;
  } else {
    _syncTime = 0;
  }
}

void startTimer(){
  _startTime = millis();
  _time = 0;
  _started = true;
  _lastTrigged = 0;

  Printer::printMessageLine("Start timer");
}

void stopTimer(){
  _lastTrigged = 0;
  _started = false;
  Printer::printMessageLine("Stop timer");

}

void loop() {
    if(!_observe){
    _distanceSensor.startObserv();
    _observe = true;
  }

  if(_distanceSensor.triggered()){
    if(_lastTrigged >= _freezTime){
      if(!_started){
        startTimer();
      } else {
        stopTimer();
      }
    }
  }

  if(_started){
    _time = millis() - _startTime + _syncTime;
    Printer::printMessage("Time:");
    Printer::printMessageLine(String(_time));
  }
  
  _lastTrigged++;
  delay(10);
}