
#include "Pulsacio_const.h"
#include <SimpleTimer.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Declaració d'objectes WiFi
WiFiClient espClient;
PubSubClient client(espClient);
SimpleTimer timer; //Timer per executar les tasques periòdiques

int timerPUBSUB, timerRECON; //Id's de les tasques periodiques del timer
int estatBoto = 0; // Per a monitorar el estat del botó

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
      client.subscribe(inTopic);
      // Enviament d'un missatge de ACK de conexió OK al topic d'ACK
      client.publish(hiTopic, "¡Hola des de la placa!");
      // Desactivar la tasca de reconexió
      timer.disable(timerRECON);
    } 
    else // En cas de fallada del intent de conexió
    {
      Serial.print("fallada, rc=");
      Serial.print(client.state());
      Serial.println(" Nou intent dintre  d'uns segons");
    }
  }
}


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
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
// Fi callback()


// Fin reconecta()

///////////////////////////////
// 
//  Comproba la conexió, i si no està conectat, activa la tasca de reconexió.
//  Si està conectat, envia l'estat del botó
//
/////////////////////////////////////////
//
void gestionaPubSub()
{   
  if (!client.connected() && !timer.isEnabled(timerRECON))
    timer.enable(timerRECON);
  else
  {
    comprobaBoto();
    char estat[2];
    sprintf(estat, "%d", estatBoto);
    // Enviament del missatge amb l'estat del botó al topic d'estat
    client.publish(EstatTopic, estat);
    client.loop();
  }
}
// Fi gestionaPubSub()


/////////////////////////////////
//
//  Comproba l'estat del botó i canvia el valor
//  de la variable en consequencia
//
//////////////////////////////////////
//
void comprobaBoto()
{
  if(digitalRead(12) == 1)
  {
    estatBoto = 0;
    Serial.println("Botó no premut");    
  }
  else
  {
    Serial.println("Botó premut");
    estatBoto = 1;
  }
}


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
  
  //Assignació de les tasques periodiques i els seus temps al timer
  timerRECON = timer.setInterval(PERIODO_RECON, reconecta);
  timerPUBSUB = timer.setInterval(PERIODO_PUBSUB, gestionaPubSub);
  //Desactivar la tasca de reconexió una vegada conectat
  timer.disable(timerRECON);
}


void loop()
{ 
  timer.run(); // mantenir el timer en marxa
}


