/*******************************************************
 *                                                     *
 *  CONTÉ FUNCIONS PER A GESTIONAR UNA QUA DE FLOATS   *
 *                                                     *
 *******************************************************/


/* Afegeix el float passat com a argument al darrera de la qua i incrementa la quantitat d'elements */
void afegirAQua(float x,float * qua, int * nelements, int llarg);
/* Retorna el primer element de la qua, l'elimina i decrementa la quantitat d'elements */
float treureDeQua(float * qua,int * nelements,int llarg);
/* retorna 1 si la qua es buida i 0 si no ho està */
int quaBuida(int nelements);
/* retorna 1 si la qua es plena i 0 si no ho està */
int quaPlena(int nelements,int llarg);
/* retorna l'element del index pasat com a argument sense eliminar-lo de la qua */
float obtenirElement(int index,float * qua ,int nelements );

