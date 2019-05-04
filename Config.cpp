
#include "Config.h"

#include <Arduino.h>
#include <ArduinoJson.h>
#include "FS.h"

bool Config::loadConfig() {
  if (!SPIFFS.exists(fileName)) {
    if (!saveConfig()) {
      return false;
    }
  }

  File configFile = SPIFFS.open(fileName, "r");
  
  if (!configFile) {
    Serial.println("Failed to open config file.");
    return false;
  }

  size_t size = configFile.size();
  if (size > 1024) {
    Serial.println("Config file size is too large.");
    return false;
  }

  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);


  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (!json.success()) {
    Serial.println("Failed to parse config file.");
    return false;
  }

  ver = json["version"];
  lang = json["language"];
  chipid = json["chipid"];

  Serial.print("version: ");
  Serial.println(ver);
  Serial.print("language: ");
  Serial.println(lang);
  Serial.print("chipid: ");
  Serial.println(chipid);

  return true;
}

bool Config::saveConfig() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["version"] = ver;
  json["language"] = lang;
  json["chipid"] = chipid;
  
  File configFile = SPIFFS.open(fileName, "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing.");
    return false;
  }

  json.printTo(configFile);
  return true;
}

bool Config::fileListing() {
  bool ret = false;

  String str = "";
  Dir dir = SPIFFS.openDir("/");

  while (dir.next()) {
    str +=  dir.fileName();
    str += " ...... ";
    str += dir.fileSize();
    str += "\r\n";
    ret = true;
  }
  Serial.print(str);
  return ret;
}

Config::Config() {

  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount file system.");
    return;
  }

//  if (!saveConfig()) {
//    Serial.println("Failed to save config.");
//  } else {
//    Serial.println("Config saved.");
//  }

  if (!loadConfig()) {
    Serial.println("Failed to load config.");
  } else {
    Serial.println("Config loaded.");
  }
  
}

Config::~Config() {
  SPIFFS.end();
}

String Config::getVersion() {
  return ver;
}

String Config::getChipid() {
  return chipid;
}

String Config::getLanguage() {
  return lang;
}

void Config::setVersion(const char* var) {
  ver = var;
}

void Config::setLanguage(const char* var) {
  lang = var;
}
