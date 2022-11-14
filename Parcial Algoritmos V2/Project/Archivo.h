#pragma once
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "ListaDoblementeEnlazada.h"
using namespace std;

struct Datos {
	string nombre;
	string apellido;
	short edad;
	int dni;
};

class Archivo
{
private:
	string archivo;
	ListaDE<Datos> cont;
public:
	Archivo(string archivo)
	{
		this->archivo = archivo;
	}
	~Archivo() {}
	void leerArchivo()
	{
		ifstream archi(archivo);
		Datos d;
		while (archi >> d.nombre >> d.apellido >> d.edad >> d.dni) {
			cont.insFinal(d);
		}
		archi.close();
	}
	
	void agregarArchivo(string nombre, string apellido, short edad, int dni)
	{
		ofstream archi(archivo);

		archi << nombre << " ";
		archi << apellido << " ";
		archi << edad << " ";
		archi << dni << "\n";

		archi.close();

		Datos aux;

		aux.nombre = nombre;
		aux.apellido = apellido;
		aux.edad = edad;
		aux.dni = dni;

		cont.insFinal(aux);
	}

	void modificarArchivo(string nombre, string apellido, short edad, int dni, int pos)
	{
		Datos aux;

		aux.nombre = nombre;
		aux.apellido = apellido;
		aux.edad = edad;
		aux.dni = dni;

		cont.modPos(aux, pos);

		remove(archivo.c_str());

		ofstream archi(archivo);

		for (size_t i = 0; i < cont.longitud(); ++i)
		{
			archi << cont.obtPos(i).nombre << " ";
			archi << cont.obtPos(i).apellido << " ";
			archi << cont.obtPos(i).edad << " ";
			archi << cont.obtPos(i).dni << "\n";
		}

		archi.close();
	}
	void borrarArchivo()
	{
		remove(archivo.c_str());
	}
};
/*

3 menu:
usuarios
archivos
open archivos


MENU:
 
1. Registrar usuarios
2. Ver usuarios
3. Exit

1. 
2. 

Elija el usuario:

Archivos:

1. 
2.
3.

4. Regresar al Menu

Elija el archivo:

1 listas
		 2 asdsad
		 3

		eleja una de las opciones:
		1. agregar
		2. modificar
		3. borrar archivo
		4. Buscar->filtros
		5. regresar

*/
/*
int deletediary()
{
	string searchfilename;
	cout<<"\nPlease enter the filename to be searched\n";
	cin>>searchfilename;
	searchfilename.append(".txt");
	fileread.open(searchfilename.c_str());
	if(!fileread){
		cout<<"\nERROR :Either you didn't enter an invalid date or you entered an date with no entry\n\n";
		A :
		cout<<"Continue to search? (y/n)\n";
		if(getch()=='y')
		{
			modifydiary();
		}
		else if(getch()=='n')
		{
			menuview();
		}
		else
		{
			cout<<"Enter Correct Option\n";
			goto A;
		}
	}
	else{
		system("cls");
		int i;
		B :
		cout<<"Are you sure you want to remove this diary entry? (y/n)";
		if(getch()=='y')
		{
			remove(searchfilename.c_str());
		}
		else if(getch()=='n')
		{
			menuview();
		}
		else
		{
			cout<<"Enter Correct Option\n";
			goto B;
		}
		cout<<"INFO :Deleted!!!";
		system("pause");
		menuview();
	}


	}
};*/


/*
class Datos
{

}
leer
string cadena;
	int tempdatos;\

	ifstream configuracion("archivo"+"[i]"+".txt");
	while (configuracion >> nombre >> apellido >> edad >> dni) {
		lista.insertar(New Datos(nombre, apellido, edad, dni));


		 

	}

	configuracion.close();

struct Datos
{
	string nombre;
	string apellido
	short edad;
	int dni;
}

New Datos("adsasd","-",15)

nombre - edad

[nombre apellido edad dni]
getNombre()
{
return
}

comentarios
*/

/*

*/

//[nombre apellido edad dni]

//to_stringNombre

//lista para adsasdasd
