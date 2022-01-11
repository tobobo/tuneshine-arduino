#ifndef NET_CONNECTION_MANAGER
#define NET_CONNECTION_MANAGER

#include <functional>
#include <Arduino.h>
#include "../TuneshineConfig/TuneshineConfig.h"

typedef std::function<void()> EventHandler;

class NetConnectionManager
{
public:
  void begin();
  void initialize();
  void onNetworkInit(EventHandler handler);
  TuneshineConfig * getConfig();
  NetConnectionManager(TuneshineConfig * tuneshineConfig) {
    this->_networkInitHandler = NULL;
    this->_tuneshineConfig = tuneshineConfig;
  }
private:
  EventHandler _networkInitHandler;
  TuneshineConfig * _tuneshineConfig;
};

#endif
