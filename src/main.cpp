#include <Arduino.h>
#include "NetConnectionManager/NetConnectionManager.h"
#include "ConfigServer/ConfigServer.h"
#include "TuneshineConfig/TuneshineConfig.h"

void setup()
{
  Serial.begin(115200);

  TuneshineConfig * tuneshineConfig = new TuneshineConfig();

  NetConnectionManager netConnectionManager(tuneshineConfig);
  ConfigServer configServer;

  netConnectionManager.onNetworkInit([&configServer]()
                                     { configServer.begin(); });

  netConnectionManager.begin();
}

void loop() {}
