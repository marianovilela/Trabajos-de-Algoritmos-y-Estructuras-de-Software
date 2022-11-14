
/*
Utilice malloc por medio de la librería "stdlib.h" para la asignacion de memoria.
*/

#include<stdlib.h>

void ejem1()  {
int *dato_simple;
dato_simple = (int *) malloc (1*sizeof(int));
}
//reserva memoria para 1 dato int.


void ejem2()  {
int *dato_simple;
dato_simple = (int *) malloc (3*sizeof(int));
}
//reserva memoria para 3 datos int.