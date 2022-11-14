/*
Un namespace, no es m�s que una forma de crear un bloque, y que todas las funciones que est�n dentro del mismo, est�n asociadas a ese namespace (o espacio de nombres), 
al cual se le asigna un nombre para identificarlo.Para ser mas espec�ficos, las palabras reservadas cout y cin est�n el namespace std (standard).
*/




/*En caso de que no declaremos el uso del namespace std cada vez que quisieramos usar cout, tendr�amos que escribir*/
std::cout << "Hola mundo";

/*El modo correcto para la declaraci�n del uso del namespace es:*/

#include <iostream>
 
usging namespace std;
 
int main()
{
    cout << "Hola mundo";
    return 0;
}
