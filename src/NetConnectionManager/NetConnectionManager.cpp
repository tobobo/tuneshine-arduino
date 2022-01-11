#include <WiFi.h>
#include <ESPmDNS.h>
#include "NetConnectionManager.h"

void NetConnectionManager::initialize()
{
  TuneshineConfig * config = getConfig();
  WifiConfig * wifiConfig = config->getWifiConfig();
  WiFi.begin(wifiConfig->ssid->c_str(), wifiConfig->password->c_str());

  if (_networkInitHandler != NULL)
  {
    _networkInitHandler();
  }

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  if (!MDNS.begin(config->getGlobalConfig()->deviceName->c_str()))
  {
    Serial.println("Error starting mDNS");
    return;
  }

  Serial.println(WiFi.localIP());

  // idle
  // TODO: check connection status here?
  while (1)
  {
    delay(1000);
  }
}

void NetConnectionManager::begin()
{
  xTaskCreate(
      [](void *pNetConnectionManager)
      {
        NetConnectionManager netConnectionManager = *((NetConnectionManager *)pNetConnectionManager);
        netConnectionManager.initialize();
      },
      "netConnectionManager",
      8192 * 2,
      this,
      1,
      NULL);
};

TuneshineConfig * NetConnectionManager::getConfig() {
  return this->_tuneshineConfig;
}

void NetConnectionManager::onNetworkInit(EventHandler handler)
{
  this->_networkInitHandler = handler;
}
