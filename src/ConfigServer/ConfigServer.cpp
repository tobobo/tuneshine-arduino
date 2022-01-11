#include <ESPAsyncWebServer.h>
#include "ConfigServer.h"

AsyncWebServer server(80);

void ConfigServer::begin() {
  
  Serial.println("Server starting...");

  server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello World");
  });

  server.begin();
}
