#include <WiFiServer.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>

#include "Medicio_Llum.h"
#include "Qua.h"
#include "WiFi_Credentials.h"
#include "RandomGenerator.h"



#define llarg 100

int watts = 0; // Contador de Watts 
int temps = 0; // Contador de temps en milisegons
int horas = 0; // Para contar horas

int tapagado = 0; //Tiempo apagado
int tencendido = 0; //Tiempo encendido
float wattsh = 0;

float * qua;
int nelements = 0;

float * quawh;
int nelementswh = 0;

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
  
  temps = millis();
  horas = millis();

  qua = (float*)malloc(sizeof(float)*llarg);
  for(int i = 0; i < llarg;i++)
    qua[i] = -1.0f;

  quawh = (float*)malloc(sizeof(float)*llarg);
  for(int i = 0; i < llarg;i++)
    quawh[i] = -1.0f;
    
  //tapagado = generarTiempoApagado() + millis();
  //Serial.print("Tiempo apagado: ");
  //Serial.println(tapagado);
  tencendido = generarTiempoEncendido()+millis();

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
//   SI tapagado NO ES CERO, COMPARA EL TIEMPO TRANSCURRIDO HASTA QUE ESTE ES IGUAL AL TIEMPO APAGADO, ENTONCES PONE A CERO Temps Y tapagado
//   Y GENERA UN VALOR PARA tencendido.
//   SI tencendido NO SES CERO, GENERA UN VALOR ALEATORIO DE Watts , LO METE EN LA CUA Y LO SUMA EN LA VARIABLE Wattsh, COMPARA EL TIEMPO TRANSCURRIDO Y
//   CUANDO tencendido ES IGUAL A temps, PONE AMBOS A CERO Y GENERA UN VALOR PARA tapagado
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
    if(millis()-temps >= tapagado)
    {
      Serial.println("Tiempo apagado cumplido");
      tencendido = generarTiempoEncendido()+millis();
      tapagado = 0;
      temps = millis();     
    }
    else
    {
      delay(10000);
     float w = 0;    
     Serial.print("Añadido a qua: ");
     Serial.println(w);
     afegirAQua(w,qua, &nelements,llarg);
    }
   }
   else if(tencendido > 0)
   {
    Serial.println("Encendido");
    if(millis()-temps >= tencendido)
    {
      tapagado = generarTiempoApagado();
      tencendido = 0;
      temps = millis();
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
//  COMPRUEBA SI horas A LLEGADO A 3600000 MILISEGUNDO
//  Y SI ES ASI, METE Wattsh EN quawh I PONE horas y wattsh a cero
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
//  COMPRUEBA SI ALGUNA DE LAS QUAS NO ESTA VACIA
//  Y SI ES ASI, SACA EL PRIMER VALOR Y LO SUBE A INFLUXDB
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

      
