#ifndef myWiFiFunction
#define myWiFiFunction
#include <WiFi.h>

bool connectToWiFi(const char* WIFI_SSID,const char* WIFI_PASSWORD)
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Only try 15 times to connect to the WiFi
  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 15){
    delay(500);
    Serial.print(".");
    retries++;
  }

  // If we still couldn't connect to the WiFi, go to deep sleep for a minute and try again.
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("\nFailed to Connect");
    esp_sleep_enable_timer_wakeup(1 * 60L * 1000000L);
    esp_deep_sleep_start();
    return false;
  }
  Serial.println("\nConnected to WiFi\n");
  Serial.println("=======================================================================");
  return true;
}

bool isWiFiCinnected(){
  return WiFi.status() == WL_CONNECTED;
}

#endif
