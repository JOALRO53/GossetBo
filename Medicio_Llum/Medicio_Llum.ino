#include <WiFi.h>
#include <WiFiUdp.h>
#include "Qua.h"
#include "WiFi_Credentials.h"
#include "RandomGenerator.h"


#define llarg 100


float * qua;
int nelements = 0;

float * quawh;
int nelementswh = 0;


int tempsanterior = 0; // Per registrar el temps passat en milisegons
int horas = 0; // Para contar horas

int tapagado = 0; //Temps apagat
int tencendido = 0; //Temps ences

float watts = 0; // Comptador de Watts 
float wattsh = 0; // Comptador de WattsH


WiFiUDP udp;

///////////////////////////
//
//  CREACIÓ DE LES TASQUES I INICIALITZACIÓ DE VARIABLES
//
/////////////////////////////////
//
void setup()
{
  Serial.begin(112500);
  Serial.println(__FILE__); 
  delay(1000);
  
  tempsanterior = millis();
  horas = millis();

  qua = (float*)malloc(sizeof(float)*llarg);
  for(int i = 0; i < llarg;i++)
    qua[i] = -1.0f;

  quawh = (float*)malloc(sizeof(float)*llarg);
  for(int i = 0; i < llarg;i++)
    quawh[i] = -1.0f;
    
  tencendido = generarTiempoEncendido();

  xTaskCreate(
                    taskOne,          /* Task function. */
                    "TaskOne",        /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL);            /* Task handle. */
 
  xTaskCreate(
                    taskTwo,          /* Task function. */
                    "TaskTwo",        /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL);            /* Task handle. */

 xTaskCreate(
                    taskThree,        /* Task function. */
                    "TaskThree",      /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL);

 xTaskCreate(
                    taskFour,         /* Task function. */
                    "TaskFour",       /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL);            /* Task handle. */                    
 
}

void loop(){} // Sense utilitat en aquest programa

 

/////////////////////////////
//
//   SI tapagado NO ES ZERO, COMPARA EL TEMPS TRANSCURREGUT FINS QUE AQUEST ES IGUAL AL TEMPS D'APAGAT, LLAVORS POSA A ZERO Temps I tapagado
//   P GENERA UN VALOR PER A tencendido.
//   SI tencendido NO ES ZERO, GENERA UN VALOR ALEATORI DE Watts , EL FICA A LA CUA Y LO SUMA EN LA VARIABLE Wattsh, COMPARA EL TEMPS TRANSCURREGUT I
//   QUAN tencendido ES IGUAL A temps, POSA TOTS DOS A ZERO I GENERA UN VALOR PER A tapagado
//
////////////////////////////////////
//
void taskOne( void * parameter )
{
  
  while(true)
  {    
   if(tapagado > 0)
   {
    Serial.println("Apagado");
    if((millis()-tempsanterior) >= tapagado)
    {
      Serial.println("Temps apagat complert");
      tencendido = generarTiempoEncendido();
      tapagado = 0;
      tempsanterior = millis();     
    }
    else
    {
     delay(10000);
     float w = 0;    
     Serial.print("Afegit a cua: ");
     Serial.println(w);
     afegirAQua(w,qua, &nelements,llarg);
    }
   }
   else if(tencendido > 0)
   {
    Serial.println("Ences");
    if(millis()-tempsanterior >= tencendido)
    {
      tapagado = generarTiempoApagado();
      tencendido = 0;
      tempsanterior = millis();
    }
    else
    {
     delay(10000);
     float w = generarValor();
     wattsh += w;
     Serial.print("Añadido a qua: ");
     Serial.println(w);
     afegirAQua(w,qua, &nelements,llarg);
    }
   }
   vTaskDelay(10);
  }
  
  vTaskDelete( NULL );
}

///////////////////////////////////
//
//  COMPROVA SI horas A ARRIVAT A 3600000 MILISEGONS
//  I SI ES AIXI, FICA Wattsh EN quawh I POSA horas y wattsh A ZERO
//
/////////////////////////////
//
void taskTwo( void * parameter)
{
  while(true)
  {
    if((millis() - horas) >= 3600000)
    {
      Serial.println("Hora");
      afegirAQua(wattsh,quawh,&nelementswh,llarg);      
      char cadenawattsh[16];
      sprintf(cadenawattsh, "%d", wattsh);
      String a="WattsH: " + String(cadenawattsh);
      Serial.println(a);      
      horas = millis();
      wattsh = 0;
    }
     vTaskDelay(10);
  }  
  vTaskDelete( NULL );
}

///////////////////////////////////
//
//  COMPROBA SI ALGUNA DE LES QUAS NO ESTA BUIDA
//  I SI ES AIXI, TREU EL PRIMER VALOR Y EL PUJA A INFLUXDB
//
/////////////////////////////
//
void taskThree( void * parameter)
{
  
  float valor = -1.0;
  String linia;
  
  while(true)
  {
    delay(1000);
    if(! quaBuida(nelements))
    {
      valor =  treureDeQua(qua,&nelements,llarg);
      char cadenavalor[16];
      sprintf(cadenavalor,"%f",valor);      
      linia = "consumllum watts=" + String(cadenavalor); //Taula (consumE), camp (watts) i valor
      Serial.println(linia);
      // Enviament del packet a influxDB
      Serial.println("Enviant UDP packet...");
      udp.beginPacket(host, port);
      udp.print(linia);
      udp.endPacket(); 
      vTaskDelay(10);          
    }
    else if(! quaBuida(nelementswh))
    {
      valor =  treureDeQua(quawh,&nelementswh,llarg);
      char cadenavalor[16];
      sprintf(cadenavalor,"%f",valor);      
      linia = "consumllum wattsH=" + String(cadenavalor); //Taula (consumE), camp (wattsH) i valor
      Serial.println(linia);
      // Enviament del packet a influxDB
      Serial.println("Enviant UDP packet...");      
      udp.beginPacket(host, port);
      udp.print(linia);
      udp.endPacket(); 
      vTaskDelay(10);     
    }    
  }  
  vTaskDelete( NULL );
}

///////////////////////////////
//
// Conexió a la xarxa WiFi
//
////////////////////////////////////////
//
void taskFour( void * parameter)
{
  
  delay(10);
  Serial.println();
  Serial.print("Conexió a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    vTaskDelay(10);
  }
  
  randomSeed(micros());
  Serial.println("");
  Serial.println("Conectat a WiFi");
  Serial.println("Direcció IP: ");
  Serial.println(WiFi.localIP());
  
  vTaskDelete( NULL );
}

      
