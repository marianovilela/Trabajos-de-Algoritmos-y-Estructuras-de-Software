#include "ListaSimple.h"
#include "Archivo.h"
#include <string>
using namespace std;

class Usuario
{
private:
	string nombre;
	ListaDE<Archivo> archivos;

public:
	Usuario(string nombre) 
	{
		this->nombre = nombre;
		archivos = ListaDE<Archivo>();
	}
	~Usuario() {}

	void agregarArchivo(string nuevoArchivo)
	{
		string auxNombre = nombre;
		//juan
		archivos.insFinal(Archivo(nuevoArchivo + ".txt"));
		auxNombre.append(".txt");
		//juan.txt
		ofstream archi(auxNombre);

		archi << nuevoArchivo << "\n";

		archi.close();
	}
	void borrarArchivo(int pos)
	{
		archivos.obtPos(pos).borrarArchivo();
		archivos.elimPos(pos);
	}
	string obtNombre()
	{
		return nombre;
	}
	ListaDE<Archivo> obtArchivos()
	{
		return archivos;
	}
};


/*
		usuarios.txt -> nombres de los usuarios
		xxx.txt->archivos, comentarios
		yyy.txt->archivos, comentarios
		archivos1.txt
		archivos2.txt
		archivos3.txt
		archivos4.txt
		*/

/*

erik -> 1 y 2
Controladora

nombres usuarios

archivos usuarios

Erik
archivo1 , dasdasdasdasd /
archivo2 , dasdasdasdasd /
archivo3 , dasdasdasdasd /
*
Juan
archivo4
archivo5

Registrar 
Usuarios



*/