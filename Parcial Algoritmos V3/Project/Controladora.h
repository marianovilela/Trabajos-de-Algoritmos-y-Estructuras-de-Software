#pragma once
#include "Usuario.h"
#include "ListaDoblementeEnlazada.h"
#include <iostream>

using namespace std;

class Controladora
{
private:
	unsigned int op;
	bool leer;
	ListaDE<Usuario> usuarios;

public:
	Controladora() 
	{
		leer = false;
		usuarios = ListaDE<Usuario>();
	}
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

		ofstream archi("Usuarios.txt", ofstream::app);
		archi << nombreUsuario <<  "\n";
		
		archi.close();

		system("pause");
		system("cls");
		menu();
	}

	void mostrarUsuarios() 
	{
		if (usuarios.longitud() != 0) 
		{
			cout << "\tUsuarios:\n";

			for (size_t i = 0; i < usuarios.longitud(); ++i) 
			{
				cout << i << ". " << usuarios.obtPos(i).obtNombre() << "\n";
				if (i == (usuarios.longitud() - 1)) 
					cout << i + 1 << ". Regresar\n";
			}

			op = usuarios.longitud() + 1;

			while (op > usuarios.longitud())
			{
				cout << "\nElija el usuario: ";
				cin >> op;
				if (op == (usuarios.longitud())) 
				{
					system("pause");
					system("cls");
					menu();
				}
				else 
					mostrarArchivos(usuarios.obtPos(op));
			}
		}
		else {
			cout << "Actualmente no existe ningun usuario\n";
			system("pause");
			system("cls");
			menu();
		}
	}

	void mostrarArchivos(Usuario usuario)
	{
		
		string auxUsuarios = usuario.obtNombre();
		auxUsuarios.append(".txt");
		string auxArchivos;
		ifstream archArchivos(auxUsuarios);
		while (archArchivos >> auxArchivos)
		{
			usuario.insertarArchivoFinal(auxArchivos);
		}
		archArchivos.close();

		if (usuario.obtArchivos().longitud() != 0)
		{
			cout << "\tArchivos:\n";

			for (size_t i = 0; i < usuario.obtArchivos().longitud(); i++)
			{
				cout << i << ". " << usuario.obtArchivos().obtPos(i).obtNombre() << "\n";
				//usuario.obtArchivos().obtPos(i).mostrarDatos();
				if (i == (usuario.obtArchivos().longitud() - 1))
				{
					cout << i + 1 << ". Agregar Archivo\n";
					cout << i + 2 << ". Volver al menu\n";
				}
			}

			op = usuario.obtArchivos().longitud() + 1;

			while (op >= usuario.obtArchivos().longitud())
			{
				int lon = usuario.obtArchivos().longitud();
				cout << "\nElija la opcion o el archivo: ";
				cin >> op;
				if (op < usuario.obtArchivos().longitud())
				{
					system("pause");
					system("cls");
					leer = true;
					opcionesArchivos(usuario.obtArchivos().obtPos(op));
				}
				else if (op == usuario.obtArchivos().longitud())
				{
					string auxNombre;
					cout << "Nombra el Archivo, por favor: ";
					cin >> auxNombre;
					usuario.agregarArchivo(auxNombre);
					mostrarArchivos(usuario);
				}
				else if (op == usuario.obtArchivos().longitud() + 1)
				{
					system("pause");
					system("cls");
					menu();
				}
			}
		}
		else
		{
			//agregar un archivo
			cout << "Actualmente no existe ningun archivo\n";
			cout << "1. Agregar archivo\n";
			cout << "2. Volver al menu\n";
			cout << "Elija la opcion: ";
			cin >> op;

			if (op == 1)
			{
				string auxNombre;
				cout << "Nombra el Archivo, por favor: ";
				cin >> auxNombre;
				usuario.agregarArchivo(auxNombre);
				mostrarArchivos(usuario);
			}
			else
			{
				system("pause");
				system("cls");
				menu();
			}
		}
	}		

	void opcionesArchivos(Archivo archivo)
	{
		string nombre;
		string apellido;
		short edad;
		int dni;
		int pos;
		if (leer == true)
		{
			leer = false;
			archivo.leerArchivo();
		}
		
		archivo.mostrarDatos();

		cout << "\tOpciones\n";
		//cout << "1. Mostrar Lista\n";
		cout << "1. Agregar Lista\n";
		cout << "2. Modificar Lista\n";
		cout << "3. Eliminar Archivo\n";
		cout << "4. Buscar por...\n";
		cout << "Elija la opcion: ";
		cin >> op;
		switch (op)
		{
		/*
		case 1:
			archivo.leerArchivo();
			archivo.mostrarDatos();
			break;
		*/
		case 1:
			cout << "Por favor ingrese la lista de datos: \n";
			cout << "Nombre: ";
			cin >> nombre;
			cout << "\nApellido: ";
			cin >> apellido;
			cout << "\nEdad: ";
			cin >> edad;
			cout << "\nDNI: ";
			cin >> dni;
			archivo.agregarArchivo(nombre, apellido, edad, dni);
			opcionesArchivos(archivo);
			break;
		case 2:
			cout << "\nPor favor ingrese en que posicion de la lista quisieras modificar: ";
			cin >> pos;
			cout << "\nAhora ingresa los datos que quisieras que la lista tenga: ";
			cout << "\nNombre: ";
			cin >> nombre;
			cout << "\nApellido: ";
			cin >> apellido;
			cout << "\nEdad: ";
			cin >> edad;
			cout << "\nDNI: ";
			cin >> dni;
			archivo.modificarArchivo(nombre, apellido, edad, dni, pos);
			opcionesArchivos(archivo);
			break;
		case 3:
			cout << "\nEstas seguro que quieres borrar este archivo? (1: Si, 2: No)";
			cin >> pos;
			if(pos == 1)
			{
				archivo.borrarArchivo();
				system("pause");
				system("cls");
				menu();
			}
			else if (pos == 2) opcionesArchivos(archivo);
			else{
				cout << "\nHas ingresado un numero no valido\n";
				opcionesArchivos(archivo);
			}
		case 4:

		default:
			cout << "Elegiste algo que no esta en las opciones, por favor repite";
			system("pause");
			system("cls");
			opcionesArchivos(archivo);
			break;
		}
	}

	void cargarDatos()
	{
		ifstream archUsuarios("Usuarios.txt");
		string auxUsuarios;
		while (archUsuarios >> auxUsuarios)
		{
			usuarios.insFinal(Usuario(auxUsuarios));
		}

		/*
		
		erik
		sebastian
		juan
		etc

		*/

		archUsuarios.close();

		string auxArchivos;

		auxUsuarios = "";

		//for (size_t i = 0; i < usuarios.longitud(); i++)
		//{

		//	auxUsuarios = usuarios.obtPos(i).obtNombre();
		//	
		//	auxUsuarios.append(".txt");
		//	/*
		//	erik.txt
		//	*/
		//	ifstream archArchivos(auxUsuarios);
		//	/*
		//	archivo1
		//	*/
		//	while (archArchivos >> auxArchivos)
		//	{//	erik sebastian juan
		//	//nombre, archivo
		//	//archivo[archivo(auxarchivos)]
		//	//
		//		//usuarios.obtPos(i).obtArchivos().insFinal(Archivo(auxArchivos));
		//		usuarios.obtPos(i).insertarArchivoFinal(auxArchivos);
		//		//usuarios.obtPos(i).obtArchivos().obtFinal().leerArchivo();
		//		/*
		//		juan perez 12 2819301
		//		*/			
		//	}

		//	archArchivos.close();
		//}
	}
};
