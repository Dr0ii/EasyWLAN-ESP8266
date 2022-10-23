/*
 *  EasyWLAN.ino
 *
 *  创建日期: 2022/10/23
 *  作者: Dr0ii
 *
 *  附件包含：index.h   init.h   serve.h
 *
 *  其他：
 *  1. AP基础配置 及 DNS基础配置 → init.h
 *  2. STA基础配置 及 服务配置 → serve.h
 *  3. 页面代码 → index.h
 *
 */


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
