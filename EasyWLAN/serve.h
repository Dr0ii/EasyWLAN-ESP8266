
#ifndef SERVE_H
#define SERVE_H

#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

#include "init.h"
#include "index.h"

ESP8266WebServer serve(80);

// STA（客户端）
String STA_SSID;      //WiFi名称
String STA_PASSWORD;  //WiFi密码
String ScanResult;

void wifi_scan_again_ssid(int scanNum){
  ScanResult = "[";
  String type;
  String hidden;
  Serial.println("");
  Serial.println("");
  Serial.print("正在扫描附近WIFI热点：");
  for(int i = 0; i < scanNum; i++){
    WiFi.encryptionType(i) == ENC_TYPE_NONE ? type = "1" : type = "0";
    WiFi.isHidden(i) ? hidden = "0" : hidden = "1";
    ScanResult += "{\"ssid\":\"" + WiFi.SSID(i) + "\"," + "\"dbm\":\"" + WiFi.RSSI(i) + "\"," + "\"type\":\"" + type + "\"," +  "\"hidden\":\"" + hidden + "\"},";
    Serial.print(".");
  }
  Serial.println("");
  ScanResult += "{\"end\":true}]";
  Serial.print(ScanResult);
  Serial.println("");
  Serial.println("完成扫描");
  serve.send(200, "text/plain", ScanResult);
  return;
}

void wifi_connecting(){
  int i = 0;
  Serial.println("接入热点中：");
  WiFi.begin(STA_SSID, STA_PASSWORD);
  for(size_t i = 0; i < 12; i++){
    if(WiFi.status() == WL_CONNECTED){
      Serial.println("");
      Serial.println("热点连接成功");
      serve.send(200, "text/plain", "{\"status\":true}");
      test();
      return;
    }else{
      delay(500);
      Serial.print(".");
    }
  }
  Serial.println("");
  Serial.println("热点连接超时");
  serve.send(200, "text/plain", "{\"status\":false}");
  return;
}

void www_configPage(){
  serve.send(200, "text/html", configPage);
  return;
}

void www_getData(){
  serve.send(200, "text/plain", ScanResult);
  return;
}

void www_getNewData(){
  wifi_scan_again_ssid(WiFi.scanNetworks());
}

void www_handleData(){
  Serial.println("");
  Serial.print("SSID: ");
  Serial.print(serve.arg("ssid"));
  Serial.println("");
  Serial.print("密码: ");
  Serial.println(serve.arg("pwd"));
  STA_SSID = serve.arg("ssid");
  STA_PASSWORD = serve.arg("pwd");
  wifi_connecting();
}

void wifi_serve_init(){
  serve.begin();
  serve.on("/", www_configPage);
  serve.on("/getData", www_getData);
  serve.on("/getNewData", www_getNewData);
  serve.on("/ssidData", www_handleData);
  serve.onNotFound(www_configPage);
}

#endif