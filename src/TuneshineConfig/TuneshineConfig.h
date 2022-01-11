#ifndef TUNESHINE_CONFIG
#define TUNESHINE_CONFIG

#include <Arduino.h>

class GlobalConfig {
  public:
    String * deviceName;
};

class WifiConfig {
  public:
    String * ssid;
    String * password;
};

class TuneshineConfig
{
  public:
    GlobalConfig * getGlobalConfig();
    WifiConfig * getWifiConfig();
    TuneshineConfig() {
      _globalConfig = NULL;
      _wifiConfig = NULL;
    }
  private:
    GlobalConfig * _globalConfig;
    WifiConfig * _wifiConfig;
};

#endif
