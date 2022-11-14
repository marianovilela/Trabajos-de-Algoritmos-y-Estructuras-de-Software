#include<iostream>
#include "Controladora.h"
using namespace std;

int main()
{
	Controladora* c = new Controladora();
	c->cargarDatos();
	c->menu();
	/*Usuario u("juan");

	ListaDE<Usuario> users;

	users.insFinal(Usuario("p"));
	cout << users.obtPos(0).obtNombre();

	u.agregarArchivo("e");
	cout << u.obtNombre();*/

	//delete c;
	return 0;
}


/*

nombre

*/