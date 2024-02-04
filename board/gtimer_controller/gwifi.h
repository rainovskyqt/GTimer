#ifndef GWIFI_H
#define GWIFI_H

#include <ESP8266WiFi.h>
#include "enums.h"

class GWiFi{

  public:
    GWiFi(IPAddress localIp, IPAddress getaway, IPAddress subnet);
    bool startWifi(Mode mode, const char* ssid, const char* password);

  private:
    IPAddress _localIP;
    IPAddress _gateway;
    IPAddress _subnet;

  bool startAP(const char* ssid, const char* password);
  bool startClient(const char* ssid, const char* password);

};

#endif // GWIFI_H