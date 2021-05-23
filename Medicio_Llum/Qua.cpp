#include <stdio.h>
#include"Qua.h"

/*******************************************************
 *                                                     *
 *  CONTÉ FUNCIONS PER A GESTIONAR UNA QUA DE FLOATS   *
 *                                                     *
 *******************************************************/

/* Afegeix el float passat com a argument al darrera de la qua i incrementa la quantitat d'elements */
void afegirAQua(float x,float * qua, int * nelements, int llarg)
{
  if(quaPlena(*nelements,llarg))
      return;
  qua[llarg-(*nelements)-1] = x;
  (*nelements)++;
}

/* Retorna el primer element de la qua, l'elimina i decrementa la quantitat d'elements */
float treureDeQua(float * qua ,int * nelements,int llarg)
{
  if(quaBuida(*nelements))
     return -2;
  float n = qua[llarg-1];
  (*nelements)--;
  return n;
}

/* retorna 1 si la qua es buida i 0 si no ho està */
int quaBuida(int nelements)
{
  return (nelements)?0:1;
}

/* retorna 1 si la qua es plena i 0 si no ho està */
int quaPlena(int nelements,int llarg)
{
  return (nelements == llarg)?1:0;
}

/* retorna l'element del index pasat com a argument sense eliminar-lo de la qua */
float obtenirElement(int index,float * qua,int nelements )
{
  if(quaBuida(nelements) || index > nelements-1 || index < 0)
      return -1;
  return qua[nelements-index];
}


