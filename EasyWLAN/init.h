#ifndef INIT_H
#define INIT_H

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include "serve.h"

// AP（服务端）- Esp8266所开放的热点
#define AP_SSID "EasyWLAN"   // 名称
#define AP_PASSWORD ""       // 密码，空为不设置密码
#define AP_MAX_CLIENT 1      // 可接入数，最多4
IPAddress IP(2,2,2,2);       // 服务地址 （英文逗号隔开）
bool DNS = true;             // 是否启动DNS服务（接入热点自动弹出配网界面）
DNSServer dnsServe;

// 首次扫描附近SSID
void wifi_scan_ssid(int scanNum){
  ScanResult = "[";
  String type;
  String hidden;
  Serial.println("");
  Serial.print("正在扫描附近WIFI热点：");
  for(int i = 0; i < scanNum; i++){
    WiFi.encryptionType(i) == ENC_TYPE_NONE ? type = "1" : type = "0";
    ScanResult += "{\"ssid\":\"" + WiFi.SSID(i) + "\"," + "\"dbm\":\"" + WiFi.RSSI(i) + "\"," + "\"type\":\"" + type + "\"},";
    Serial.print(".");
  }
  Serial.println("");
  ScanResult += "{\"end\":\"true\"}]";
  Serial.print(ScanResult);
  Serial.println("");
  Serial.println("完成扫描");
  wifi_serve_init();
}

// AP服务初始化
void wifi_init(){
	WiFi.persistent(false);
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(IP, IP, IPAddress(255,255,255,0));
  WiFi.softAP(AP_SSID, AP_PASSWORD, 1, 0, AP_MAX_CLIENT);
  delay(300);
  Serial.println("");
  Serial.print("AP服务已启动，IP地址为： ");
  Serial.print(WiFi.softAPIP());
  Serial.println("");
  WiFi.scanNetworksAsync(wifi_scan_ssid);
}

// DNS服务初始化
void wifi_dns_init(){
  if(DNS){
    dnsServe.start((byte)53, "*", IP);
    Serial.println("");
    Serial.println("DNS服务已启动");
  };
  return;
}

#endif
