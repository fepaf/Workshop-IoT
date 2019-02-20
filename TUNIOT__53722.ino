/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

WiFiClient client;

char thingSpeakAddress[] = "api.thingspeak.com";
String thingtweetAPIKey = "CKA478D0ZON19PQS";
String tsData;

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("Começando");
   WiFi.begin("");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Conectado");
  if (client.connect("api.thingspeak.com",80)) {
    tsData = "api_key="+thingtweetAPIKey+"&status="+"Funfou IoT Ludus";
    client.print("POST /apps/thingtweet/1/statuses/update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(tsData.length());
    client.print("\n\n");
    client.print(tsData);
    Serial.println("Tweet Enviado");

  }

}


void loop()
{


}