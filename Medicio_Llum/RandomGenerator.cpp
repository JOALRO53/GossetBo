#include "RandomGenerator.h"
#include<stdlib.h>
#include<time.h>

/* Genera temps d'apagat entre 23 i 27 minuts en segons */
int generarTiempoApagado() 
{
  srand(time(NULL));
  return rand()%240000+1380000;//Entre 23 y 27 minuts (n-m)+n n = 1620 segons ; m = 1380 segons
}

/* Genera temps ences entre 20 y 24 minuts en segons */
int generarTiempoEncendido()
{
  srand(time(NULL));
  return rand()%240000+1440000;//Entre 20 y 24 minuts (n-m)+n n = 1440 segons ; m = 1200 segons
}

/* Genera Watts entre 170 y 190 */
float generarValor()
{
  srand(time(NULL));
  float vrand = rand()%2000+19000;
  return vrand/100.0f;
}

