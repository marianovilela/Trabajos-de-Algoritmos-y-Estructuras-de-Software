/*
Un namespace, no es más que una forma de crear un bloque, y que todas las funciones que estén dentro del mismo, estén asociadas a ese namespace (o espacio de nombres), 
al cual se le asigna un nombre para identificarlo.Para ser mas específicos, las palabras reservadas cout y cin están el namespace std (standard).
*/




/*En caso de que no declaremos el uso del namespace std cada vez que quisieramos usar cout, tendríamos que escribir*/
std::cout << "Hola mundo";

/*El modo correcto para la declaración del uso del namespace es:*/

#include <iostream>
 
usging namespace std;
 
int main()
{
    cout << "Hola mundo";
    return 0;
}
