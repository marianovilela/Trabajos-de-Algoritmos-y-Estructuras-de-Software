#include<iostream>
#include "Controladora.h"
using namespace std;

int main()
{
	Controladora* c = new Controladora();
	c->cargarDatos();
	c->menu();
	delete c;
	return 0;
}