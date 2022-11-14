#pragma once
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <filesystem>
#include "ListaSimple.h"
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
	string nomArchivo;
	string nomArchCom;
	string comentario;
	ListaS<Datos> cont;
public:
	Archivo(string n, string c)
	{
		nomArchivo = n;
		c = comentario;
		nomArchCom = nomArchivo + "com.txt";
	}
	~Archivo() {}
	void leerArchivo()
	{
		ifstream archCom(nomArchCom);
		string auxCom;
		getline(archCom, auxCom);
		comentario = auxCom;
			
		string aux = nomArchivo;
		aux.append(".txt");
		ifstream archi(aux);
		Datos d;
		while (archi >> d.nombre >> d.apellido >> d.edad >> d.dni) {
			cont.insFinal(d);
		}
		archi.close();
	}
	
	void agregarDatos(string nombre, string apellido, short edad, int dni)
	{
		string auxN = nomArchivo;
		auxN.append(".txt");
		ofstream archi(auxN, ofstream::app);

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

		//remove(nomArchivo.c_str());
		string auxnomA = nomArchivo;
		auxnomA.append(".txt");
		ofstream archi(auxnomA);

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
		string aux = nomArchivo;
		aux.append(".txt");
		remove(aux.c_str());
	}
	
	string obtNombre()
	{
		return nomArchivo;
	}
	string obtNomArchCom()
	{
		return nomArchCom;
	}
	string obtComentario()
	{
		return comentario;
	}
	void cambComentario(string c)
	{
		comentario = c;
	}

	void mostrarDatos() 
	{
		if (cont.longitud() == 0)
		{
			cout << "Comentario del archivo:\n";
			cout << comentario << "\n\n";
			cout << "El archivo no contiene nada\n\n";
		}
		else
		{
			cout << "Comentario del archivo:\n";
			cout << comentario << "\n\n";
			for (size_t i = 0; i < cont.longitud(); i++)
			{
				cout << "Lista # " << i << ": ";
				cout << cont.obtPos(i).nombre << " ";
				cout << cont.obtPos(i).apellido << " ";
				cout << cont.obtPos(i).edad << " ";
				cout << cont.obtPos(i).dni << "\n";
			}
			cout << "\n";
		}
	}
};
