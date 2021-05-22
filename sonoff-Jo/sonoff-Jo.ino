
#include "const.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Declaració d'objectes WiFi
WiFiClient espClient;
PubSubClient client(espClient);


///////////////////////////////
//
// Conexió a la xarxa WiFi
//
////////////////////////////////////////
//
void setup_wifi()
{
  delay(10);
  Serial.println();
  Serial.print("Conexió a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  randomSeed(micros());
  Serial.println("");
  Serial.println("Conectat a WiFi");
  Serial.println("Direcció IP: ");
  Serial.println(WiFi.localIP());
}
// Fi setup_wifi


///////////////////////////
// 
// Funció de reconexió després de desconexió del servidor MQTT
//
/////////////////////////////////
//
void reconecta()
{
  if (!client.connected()) {
    Serial.print("Intent de conexió MQTT...");
    // Creació d'un random client ID
    String clientId = "placa";
    clientId += String(random(0xffff), HEX);
    // Intent de conexió amb exit
    if (client.connect(clientId.c_str(),mqtt_user,mqtt_pwd))
    {
      Serial.println("connectat");
      // Subscripció al Topic per rebre missatges 
      client.subscribe(funcTopic);
      // Enviament d'un missatge de ACK de conexió OK al topic d'ACK
      client.publish(funcTopic, "¡Hola des de sonoff!");     
    } 
    else // En cas de fallada del intent de conexió
    {
      Serial.print("fallada, rc=");
      Serial.print(client.state());
      Serial.println(" Nou intent dintre  d'uns segons");
    }
  }
}
// Fin reconecta()


////////////////////////////////
//
// Funció de callback a l'arribada d'un missatge
//
/////////////////////////////////
//
void incomingSub(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Missatge rebut: [");
  Serial.print(topic);
  Serial.print("] ");
  String missatge = "";
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    missatge += (char)payload[i];
  }
  if(missatge == "ON")
     digitalWrite(12,HIGH);
  else if(missatge == "OFF")
     digitalWrite(12,LOW);
  Serial.println();
}
// Fi callback()


//////////////////////////
//
//  Inicialització del pin de lectura, el wifi , el client mqtt
//  i el Timer
//
/////////////////////////////////////
//
void setup() {
  // Assignació del pin 12 com de lectura amb mode pull up
  pinMode(12,INPUT_PULLUP); 
  // Inicialització del wifi i sel client mqtt
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(incomingSub);
}


void loop()
{ 
  if (!client.connected())
     reconecta();
    
}


