#pragma once
#include "Usuario.h"
#include "ListaDoblementeEnlazada.h"
#include <iostream>

using namespace std;

class Controladora
{
private:
	unsigned int op;
	ListaDE<Usuario> usuarios;

public:
	Controladora() {}
	~Controladora() {}

	void menu()
	{
		cout << "\tMENU\n";
		cout << "1. Registrar Usuario\n";
		cout << "2. Mostrar Usuarios\n";
		cout << "3. Salir\n";
		cout << "Elija la opcion: ";
		cin >> op;
		switch(op)
		{
			case 1: 
				registrarUsuario();
				break;
			case 2: 
				mostrarUsuarios();
				break;
			case 3:
				break;
			default:
				cout << "Elegiste algo que no esta en las opciones, por favor repite";
				system("pause");
				system("cls");
				menu();
				break;
		}
	}

	void registrarUsuario()
	{
		string nombreUsuario;

		cout << "Ingrese el nombre del nuevo usuario: ";
		cin >> nombreUsuario;

		usuarios.insFinal(nombreUsuario);

		ofstream archi("Usuarios.txt");

		archi << nombreUsuario <<  "\n";
		
		archi.close();

		system("pause");
		system("cls");
		menu();
	}

	void mostrarUsuarios() 
	{
		/*ifstream archi("Usuarios.txt");
		string auxNombre;*/
		//int conteo = 0;

		cout << "\tUsuarios:\n";

		/*for (size_t i = 0; archi >> auxNombre; ++i)
			cout << i + 1 << auxNombre << "\n";*/
		for (size_t i = 0; i < usuarios.longitud(); i++)
			cout << i << ". " << usuarios.obtPos(i).obtNombre() << "\n";

		/*while (archi >> auxNombre)
		{
			cout << conteo  << ". " << auxNombre << "\n";
			++conteo;
		}*/

		op = usuarios.longitud();
		while (op >= usuarios.longitud())
		{
			cout << "\nElija el usuario: ";
			cin >> op;
		}
		
		cout << "\n";
		system("pause");
		system("cls");
		mostrarArchivos(usuarios.obtPos(op));
	}

	void mostrarArchivos(Usuario usuario)
	{
		cout << "\tArchivos:\n";

		for (size_t i = 0; i < usuarios.longitud(); i++)
			cout << i << ". " << usuarios.obtPos(i).obtNombre() << "\n";
		
		op =usuario.obtArchivos().longitud();
		while (op >= usuario.obtArchivos().longitud())
		{
			cout << "\nElija el archivo: ";
			cin >> op;
		}

		cout << "\n";
		system("pause");
		system("cls");

		//opcionesArchivos(usuario.obtArchivos().obtPos(op));
	}

	/*void opcionesArchivos(Archivo archivo)
	{
		cout << "\tOpciones\n";
		cout << "1. Mostrar Archivo\n";
		cout << "2. Modificar Archivo\n";
		cout << "3. Eliminar Archivo\n";
		cout << "Elija la opcion: ";
		cin >> op;
		switch (op)
		{
		case 1:
			archivo.leerArchivo();
			break;
		case 2:
			
			break;
		case 3:

			break;
		default:
			cout << "Elegiste algo que no esta en las opciones, por favor repite";
			system("pause");
			system("cls");
			opcionesArchivos();
			break;
		}
	}*/

	void cargarDatos()
	{
		ifstream archUsuarios("Usuario.txt");
		string auxUsuarios;
		while (archUsuarios >> auxUsuarios)
		{
			usuarios.insFinal(Usuario(auxUsuarios));
		}
		archUsuarios.close();

		string auxArchivos;

		for (size_t i = 0; i < usuarios.longitud(); ++i)
		{
			auxUsuarios = usuarios.obtPos(i).obtNombre();
			auxUsuarios.append(".txt");
			ifstream archArchivos(auxUsuarios);
			while (archUsuarios >> auxArchivos)
			{
				usuarios.obtPos(i).obtArchivos().insFinal(Archivo(auxArchivos));
				usuarios.obtPos(i).obtArchivos().obtFinal().leerArchivo();
			}
		}
	}
};
