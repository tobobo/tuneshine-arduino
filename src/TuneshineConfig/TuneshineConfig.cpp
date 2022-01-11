#include <Arduino.h>
#include "TuneshineConfig.h"
#include "../secrets.h"

// Configuration object to be shared by many other objects—
// must be in the heap, correct?

GlobalConfig * TuneshineConfig::getGlobalConfig() {
  if (_globalConfig == NULL) {
    // globalConfig is an object, not a struct,
    // to allow for String members. Maybe I should
    // be using char arrays instead, but because this
    // might be coming from a database or user input,
    // I thought the Arduino String class might be more applicable.
    //
    // Maybe this is super wasteful but I figure that having a limited number
    // of Strings around for config wasn't going to break anything
    GlobalConfig * globalConfig = new GlobalConfig;
    String * deviceName = new String(secrets::deviceName);
    globalConfig->deviceName = deviceName;
    _globalConfig = globalConfig;
  }
  
  // Do I really need to have the return type here be a pointer?
  // It "feels" like I should be able to use the getter to
  // abstract away the pointer, and only refer to it internally
  // to this class, but I was seeing strange behavior when I
  // changed the return type of this function to GlobalConfig
  return _globalConfig;
  
  // Can passing by reference help with any of this or is that for
  // a different kind of circumstance?
}

WifiConfig * TuneshineConfig::getWifiConfig() {
  if (_wifiConfig == NULL) {
    WifiConfig * wifiConfig = new WifiConfig;
    String * ssid = new String(secrets::ssid);
    String * password = new String(secrets::password);
    wifiConfig->ssid = ssid;
    wifiConfig->password = password;
    _wifiConfig = wifiConfig;
  }

  return _wifiConfig;
}
