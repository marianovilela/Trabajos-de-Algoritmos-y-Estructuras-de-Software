
/*
Utilice cout por medio de la librería "iostream" para facilitar el ejemplo.
*/

#include <iostream>
using namespace std;

class Ejem1{
    public:
    virtual void print()=0; //clase abstracta
};

int main(){
    Ejem1 obj = new Ejem1();//creando un objeto
}

// Saldra error porque en un funcion virtual(abstracta) no se puede crear objetos