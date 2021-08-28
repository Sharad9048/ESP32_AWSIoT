#include "awsFunction.h"
#include "myWiFiFunction.h"

int randomNumber;
String randomNumberString;
int count=1;
String countString;

#define WiFiSSID "SSID"
#define WiFiPWD "Password"


void setup() {

  /*
   * Enable Serial Printing
   */
  Serial.begin(115200);
  
  
  /*
   * Connecting To WiFi
   */
  connectToWiFi(WiFiSSID, WiFiPWD);

  

  /*
   * This function present in the header file called <"awsFunction.h">
   * Connection to AWS server
   */
  startAWSconnection();
  

  

}

void loop() {
  

  if(!mqttClient.connected()){
    reconnect();
  }
  mqttClient.loop();
  randomNumber = random(10);
  
  Serial.print("\nRandom Number: ");
  Serial.println(randomNumber);
  Serial.println("\n--------------------\n");
  

  sendJsonToAWS();
  count++;
  
  

  delay(5000);
}
/*
 * Function to convert data to json format
 */
void sendJsonToAWS()
{
  StaticJsonDocument<512> jsonDoc;
  char jsonBuffer[512];
  
  jsonDoc["Random_Number"] = randomNumber;
  
  jsonDoc["Count"] = String(count);
  serializeJson(jsonDoc, jsonBuffer);
  mqttClient.publish("getData", jsonBuffer);
  Serial.println(jsonBuffer);
}
