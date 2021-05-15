#include "Medicio_Aigua_Jo.h"
#include "Qua.h"

#define llarg 100

int canvis = 0; // Contador dels pulsos enviats pel sensor
int temps = 0; // Contador de temps en milisegons
int medicionsbuffer = 0; //Contador per registrar el nombre de medicions que hi ha al buffer

float * qua;
int nelements = 0;

///////////////////////////
//
//  DEFINICIO DE LES TASQUES , PIN DE LECTURA I
//  INICIALITZACIÓ DE VARIABLES
//
/////////////////////////////////
//
void setup()
{
  Serial.begin(112500);
  Serial.println(__FILE__); 
  delay(1000);
  pinMode(pin,INPUT_PULLUP);
  temps = millis();

  qua = (float*)malloc(sizeof(float)*llarg);
  for(int i = 0; i < llarg;i++)
    qua[i] = -1.0f;
 
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
                    NULL);            /* Task handle. */
                     
 
}

void loop(){} // Sense utilitat en aquest programa


//////////////////////////////
//
//  RETORNA TRUE SI HI HA TENSIO AL PIN 
//  DE NOMBRE PASAT COM A ARGUMENT I FALSE
//  EN CAS CONTRARI
//
//////////////////////////////
//
boolean btensio(int npin) 
{
  if (digitalRead(npin))
    return false;
  return true;
}
 

/////////////////////////////
//
//   COMPROBA SI HA HAGUT UN CANVI DE ESTAT
//   AL PIN ON EL DISPOSITIU ENVIA PULSOS I
//   AUGMENTA EL COMPTADOR EN CAS AFIRMATIU
//
////////////////////////////////////
//
void taskOne( void * parameter )
{
  static boolean bPinTeTensio = false;
  while(true)
  {    
    boolean bEstatActualPin = btensio(pin);
    if(bEstatActualPin != bPinTeTensio)
    {
       canvis++;
       Serial.println("Canvi");       
   }
   bPinTeTensio = bEstatActualPin;
   vTaskDelay(10);
  }
  vTaskDelete( NULL );
}

///////////////////////////////////
//
//  COMPROBA EL TEMPS I QUAN ARRIBA AL LAPSE ESTABLERT
//  FICA A LA QUA EL VALOR DELS LLITRES QUE HAN PASSAT PEL
//  SENSOR EN EL LAPSE ESTABLERT, DESPRÉS REINICIA
//  ELS CONTADORS DE TEMPS I PULSOS
//
/////////////////////////////
//
void taskTwo( void * parameter)
{
  while(true)
  {
    if((millis() - temps) >= lapse) // 10 segons
    {
      Serial.println("Lapse");
      float llitres = (float)canvis / (float)pulsosllitre;      
      afegirAQua(llitres,qua,&nelements,llarg);      
      char cadenacanvis[16];
      sprintf(cadenacanvis, "%d", canvis);
      char cadenalapse[16];
      sprintf(cadenalapse,"%d",lapse/1000);      
      char cadenallitres[16];
      sprintf(cadenallitres,"%f",llitres);      
      String a="Pulsos: " + String(cadenacanvis) + " en: " + String(cadenalapse) + " segons" + " Llitres: " + cadenallitres;      
      Serial.println(a);      
      for(int i = llarg-1; i  > llarg-nelements-1; i--)
      {
        char cadenaqua[16];
        sprintf(cadenaqua,"%f",qua[i]);      
        Serial.println(cadenaqua);
      }           
      temps = millis();
      canvis = 0;
    }
     vTaskDelay(10);
  }  
  vTaskDelete( NULL );
}

///////////////////////////////////
//
//  COMPROBA QUE LA QUA NO ESTIGUI BUIDA, I 
//  SI ES AIXÍ, TREU EL PRIMER VALOR DE LA QUA
//  PER ENVIAR-LO A INFLUXDB
//
/////////////////////////////
//
void taskThree( void * parameter)
{
  float valor = -1.0;
  while(true)
  {
    if(! quaBuida(nelements))
    {
      valor =  treureDeQua(qua,&nelements,llarg);
      char cadenavalor[16];
      sprintf(cadenavalor,"%f",valor);      
      Serial.println("Valor: " + String(cadenavalor));
    }
     vTaskDelay(10);
  }
  vTaskDelete( NULL );
}
      
