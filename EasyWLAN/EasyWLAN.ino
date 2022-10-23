#include "init.h" //引入初始化头文件init.h
#include "serve.h" //引入服务头文件serve.h

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
