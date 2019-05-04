
#ifndef _Config_H__
#define _Config_H__

#include <Arduino.h>

class Config {
  private:
    const char* fileName = "/config.json";
    const char* ver = "0.0.1";
    const char* lang = "en";
    const char* chipid = "xx-xxxx";
  

  public:
    Config();
    ~Config();

    bool saveConfig();
    bool loadConfig();

    bool fileListing();

    String getVersion();
    String getChipid();
    String getLanguage();
    
    void setVersion(const char* var);
    void setLanguage(const char* var);
    
};



#endif
