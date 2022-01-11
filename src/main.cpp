#include <Arduino.h>
#include "NetConnectionManager/NetConnectionManager.h"
#include "ConfigServer/ConfigServer.h"
#include "TuneshineConfig/TuneshineConfig.h"

void setup()
{
  Serial.begin(115200);

  TuneshineConfig * tuneshineConfig = new TuneshineConfig();
  Serial.println("str from main");
  Serial.println(tuneshineConfig->getWifiConfig()->ssid->c_str());

  NetConnectionManager netConnectionManager(tuneshineConfig);
  ConfigServer configServer;

  netConnectionManager.onNetworkInit([&configServer]()
                                     { configServer.begin(); });

  netConnectionManager.begin();
}

void loop() {}
