#include "RandomGenerator.h"
#include<stdlib.h>
#include<time.h>

/* Genera tiempo apagado entre 23 y 27 minutos en segundos */
int generarTiempoApagado() 
{
  srand(time(NULL));
  return rand()%240000+1380000;//Entre 23 y 27 minutos (n-m)+n n = 1620 segundos ; m = 1380 segundos
}

/* Genera tiempo encendido entre 20 y 24 minutos en segundos */
int generarTiempoEncendido()
{
  srand(time(NULL));
  return rand()%240000+1440000;//Entre 20 y 24 minutos (n-m)+n n = 1440 segundos ; m = 1200 segundos
}

/* Genera Watios entre 170 y 190 */
float generarValor()
{
  srand(time(NULL));
  float vrand = rand()%2000+19000;
  return vrand/100.0f;
}

