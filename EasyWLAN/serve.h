/*
 *  serve.h
 *
 *  创建日期: 2022/10/23
 *  作者: Dr0ii
 *
 *  说明：此文件为STA基础配置 及 服务配置
 *
 */

#ifndef SERVE_H
#define SERVE_H

#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

#include "init.h"
#include "index.h"

ESP8266WebServer serve(80); // AP服务端口

// STA（客户端）- ESP8266所连接的热点
String STA_SSID;      // WiFi名称
String STA_PASSWORD;  // WiFi密码
String ScanResult; // SSID列表暂存

// 扫描附近SSID
void wifi_scan_again_ssid(int scanNum){
  ScanResult = "[";
  String type;
  String hidden;
  Serial.println("");
  Serial.println("");
  Serial.print("正在扫描附近WIFI热点：");
  for(int i = 0; i < scanNum; i++){
    WiFi.encryptionType(i) == ENC_TYPE_NONE ? type = "1" : type = "0";
    ScanResult += "{\"ssid\":\"" + WiFi.SSID(i) + "\"," + "\"dbm\":\"" + WiFi.RSSI(i) + "\"," + "\"type\":\"" + type + "\"},";
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

// 连接热点
void wifi_connecting(){
  int i = 0;
  Serial.println("接入热点中：");
  WiFi.begin(STA_SSID, STA_PASSWORD);
  for(size_t i = 0; i < 12; i++){
    if(WiFi.status() == WL_CONNECTED){
      Serial.println("");
      Serial.println("热点连接成功");
      serve.send(200, "text/plain", "{\"status\":true}");
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

// 首页回调函数
void www_configPage(){
  serve.send(200, "text/html", configPage);
  return;
}

// SSID列表回调函数
void www_getData(){
  serve.send(200, "text/plain", ScanResult);
  return;
}

// SSID列表刷新函数
void www_getNewData(){
  wifi_scan_again_ssid(WiFi.scanNetworks());
}

// 连接热点函数
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

// 服务初始化
void wifi_serve_init(){
  serve.begin();
  serve.on("/", www_configPage);
  serve.on("/getData", www_getData);
  serve.on("/getNewData", www_getNewData);
  serve.on("/ssidData", www_handleData);
  serve.onNotFound(www_configPage);
}

#endif