#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "nodemcu-6a1b8-default-rtdb.firebaseio.com"  //Change to your Firebase RTDB project ID e.g. Your_Project_ID.firebaseio.com
#define FIREBASE_AUTH "QYS2dqutizZpDTkLw9eAiKKW6XxyUGK1XPDIy1Zq" //Change to your Firebase RTDB secret password
#define WIFI_SSID "Omi2_4GHz"
#define WIFI_PASSWORD "9516110908"

//Define Firebase Data objects
FirebaseData firebaseData1;
FirebaseData firebaseData2;
String path = "/Position";

void setup()
{

    Serial.begin(115200);

    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    Serial.println();
    Serial.println();

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);

    if (!Firebase.beginStream(firebaseData1, path))
    {
        Serial.println("Could not begin stream");
        Serial.println("REASON: " + firebaseData1.errorReason());
        Serial.println();
    }
}

void loop()
{
    if (!Firebase.readStream(firebaseData1))
    {
        Serial.println();
        Serial.println("Can't read stream data");
        Serial.println("REASON: " + firebaseData1.errorReason());
        Serial.println();
    }

    if (firebaseData1.streamTimeout())
    {
        Serial.println();
        Serial.println("Stream timeout, resume streaming...");
        Serial.println();
    }

    if (firebaseData1.streamAvailable())
    {
        String str=firebaseData1.stringData().c_str();
        Serial.println(str);
        if(str.equals("Left"))
        {
          digitalWrite(D1,0);
          digitalWrite(D2,1);
        }
        else if(str.equals("Right"))
        {
          digitalWrite(D1,1);
          digitalWrite(D2,0);
        }
        else if(str.equals("Center"))
        {
          digitalWrite(D1,1);
          digitalWrite(D2,1);
        }
        else if(str.equals("Stop"))
        {
          digitalWrite(D1,0);
          digitalWrite(D2,0);
        }
    }

    
}
