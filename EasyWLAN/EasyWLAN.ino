
#include "init.h"
#include "serve.h"

void setup() {
  Serial.begin(115200);
  wifi_init();
  wifi_dns_init();
}

void loop() {
  serve.handleClient();
  if(DNS) dnsServe.processNextRequest();
  delay(10);
}
