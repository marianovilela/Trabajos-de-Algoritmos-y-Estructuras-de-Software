
/*
Utilice string por medio de la librería "string" para facilitar el ejemplo.
*/

#include <string>

class String{
private:
    char* s;
    int size;
 
public:
    String(char*); // constructor
    ~String(); // destructor
};
 
String::String(char* c){
    size = strlen(c);
    s = new char[size + 1];
    strcpy(s, c);
}
String::~String(){ 
    delete[] s; 
}

/*
el destructor es una función miembro de instancia que se invoca automáticamente 
cada vez que un objeto va a ser destruido.

un destructor se crea y usa generalmente cuando la función termina, el programa 
termina, un bloque que contiene variables locales termina o se llama un operador 
de eliminación

el destructor predeterminado funciona bien, a menos que hayamos asignado memoria 
o puntero dinámicamente en la clase. Cuando una clase contiene un puntero a la 
memoria asignada en la clase, debemos escribir un destructor para liberar esa 
memoria como en el ejemplo, antes de que se destruya la instancia de la clase. 
Esto debe hacerse para evitar pérdidas de memoria.
*/