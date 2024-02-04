#include "gwifi.h"
#include "printer.h"

GWiFi::GWiFi(IPAddress localIp, IPAddress getaway, IPAddress subnet)
{
  _localIP = localIp;
  _gateway = getaway;
  _subnet = subnet;
};

bool GWiFi::startWifi(Mode mode, const char* ssid, const char* password)
{
  Printer::printMessageLine("Setup wifi...");
  switch (mode) {
    case Mode::Finish:{
      return startClient(ssid, password);
    }
    default:
      return startAP(ssid, password);
  }
  Printer::printMessage("Setup Wi-Fi complite");
}

bool GWiFi::startAP(const char* ssid, const char* password)
{
  Printer::printMessage("Start AP...");

  if (!WiFi.softAPConfig(_localIP, _gateway, _subnet)){
    Serial.println("Error AP Config");
    return false;
  }

  WiFi.mode(WIFI_AP);
  if (!WiFi.softAP(ssid, password)){
    Printer::printMessage("Error AP");
    return false;
  }
  Printer::printMessageLine("Ok");
  Printer::printMessage("Soft-AP IP address: ");
  Printer::printMessageLine(WiFi.softAPIP().toString());

  return true;
}

bool GWiFi::startClient(const char* ssid, const char* password)
{
  Printer::printMessage("Start Wi-Fi client...");

  WiFi.begin(ssid, password);
    
  int timeout = 5000;
  while (WiFi.status() != WL_CONNECTED){
    delay(250);
    Printer::printMessage(".");
    if (!timeout--)
      return false;
  }

  Printer::printMessageLine("Ok");

  return true;
}