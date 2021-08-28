#ifndef awsFunction
#define awsFunction

#include <ArduinoJson.h>
#include <MQTTClient.h>
#include <WiFiClientSecure.h>


#include "myCertificateData.h"

WiFiClientSecure espClient = WiFiClientSecure();
MQTTClient mqttClient = MQTTClient();

/*
 * Name if the thing to be connected in AWS IoT Core
 */
#define ThingName "ESP32"

/*
 * The end point can be found in <"settings"> menu in AWS IoT
 */
#define endPoint "xxxxxxxxxxxxxx-ats.iot.ap-south-1.amazonaws.com"

/*
 * Name of the topic on which data is published
 */
#define topicName "getData"


bool startAWSconnection(){
  espClient.setCACert(AmazonRootCA);
  espClient.setCertificate(AWScertificate);
  espClient.setPrivateKey(AWSprivateKey);

  mqttClient.begin(endPoint, 8883, espClient);
  
  while (!mqttClient.connect(ThingName)) {
    Serial.println(".");
    delay(100);
  }
  if(!mqttClient.connected()){
    return false;
  }
  return true;
}
/*
 * If the device is not connecting to the server then test the server with a python code
 * If the data recieved sucessfuly the check the following 
 * 1. WiFi connection and internet connectivity
 * 2. END point URL
 * 3. Thing Name
 * 4. Re-entry your rootCA, certificates and key data
 */
bool reconnect(){
  int retries = 0;
  while (!mqttClient.connect(ThingName) && retries < 15){
    retries++;
  }
  if(!mqttClient.connected()){
    Serial.println("Test the server with your python code\nthen recheck your code");
    return false;
  }
  return true;
}



#endif
