#pragma once
#include "Usuario.h"
#include "ListaDoblementeEnlazada.h"
#include "ListaSimple.h"
#include <iostream>
#include <string.h>
#include <functional>

using namespace std;

class Controladora
{
private:
	unsigned int op;
	bool leer;
	bool archUsuario;
	ListaS<Usuario> usuarios;

public:
	Controladora() 
	{
		leer = false;
		archUsuario = false;
		usuarios = ListaS<Usuario>();
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
				system("pause");
				system("cls");
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
		archi << nombreUsuario << "\n";
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
				cout << "\nElija la opcion o el usuario: ";
				cin >> op;
				if (op == (usuarios.longitud())) 
				{
					system("pause");
					system("cls");
					menu();
					break;
				}
				else
				{
					archUsuario = true;
					mostrarArchivos(usuarios.obtPos(op));
				}
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
		if(archUsuario)
		{
			string auxUsuarios = usuario.obtNombre();
			auxUsuarios.append(".txt");
			string auxArchivos;

			ifstream archArchivos(auxUsuarios);
			while (archArchivos >> auxArchivos)
			{
				usuario.insertarArchivoFinal(auxArchivos, "");
			}
			archArchivos.close();
			
			archUsuario = false;
		}

		if (usuario.obtArchivos().longitud() != 0)
		{
			cout << "\tArchivos:\n";
			for (size_t i = 0; i < usuario.obtArchivos().longitud(); i++)
			{
				cout << i << ". " << usuario.obtArchivos().obtPos(i).obtNombre() << "\n";
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
					break;
				}
				else if (op == usuario.obtArchivos().longitud())
				{
					string auxNombre;
					string comentario;
					cout << "Nombra el Archivo, por favor: ";
					cin >> auxNombre;
					cout << "\nIngresa el comentario del archivo: ";
					cin.get();
					getline(cin, comentario);
					usuario.agregarArchivo(auxNombre, comentario);
					mostrarArchivos(usuario);
					break;
				}
				else if (op == usuario.obtArchivos().longitud() + 1)
				{
					system("pause");
					system("cls");
					menu();
					break;
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
				string auxComentario;
				cout << "Nombra el Archivo, por favor: ";
				cin >> auxNombre;
				cout << "\nIngresa el comentario del archivo: ";
				cin.get();
				getline(cin, auxComentario);
				usuario.agregarArchivo(auxNombre, auxComentario);
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
		cout << "1. Agregar Lista\n";
		cout << "2. Modificar Lista\n";
		cout << "3. Eliminar Archivo\n";
		cout << "4. Buscar por...\n";
		cout << "5. Volver al menu\n";
		cout << "Elija la opcion: ";
		cin >> op;
		switch (op)
		{
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
			archivo.agregarDatos(nombre, apellido, edad, dni);
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
			cout << "\nEstas seguro que quieres borrar este archivo? (1: Si, 2: No): ";
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
			break;
		case 4:
			system("pause");
			system("cls");
			buscarPor(opcionesBuscar(), archivo);
			break;
		case 5:
			system("pause");
			system("cls");
			menu();
			break;
		default:
			cout << "Elegiste algo que no esta en las opciones, por favor repite";
			system("pause");
			system("cls");
			opcionesArchivos(archivo);
			break;
		}
	}
	function<bool(string p)> opcionesBuscar()
	{
		string p;
		char l;
		cout << "\nBuscar por...\n";
		cout << "1. Igual a...\n";
		cout << "2. Inicia con...\n";
		cout << "3. Finaliza con...\n";
		cout << "4. Esta contenido en...\n";
		cout << "5. No esta contenido en...\n";
		cout << "6. Volver al menu\n";
		cout << "Elija la opcion: ";
		cin >> op;

		cout << "\nIngresa la palabra: ";
		cin >> p;

		if (op == 1)
		{
			auto a = [p](string palabra) -> bool {
				if (palabra == p)
					return true;
				return false;
			};
			return a;
		}
		else if (op == 2)
		{
			auto a = [p](string palabra) -> bool {
				int contador = 0;
				if (palabra.size() >= p.size())
				{
					for (size_t i = 0; i < p.size(); i++)
						if (palabra.at(i) == p.at(i))
							contador++;
					if (contador == p.size())
						return true;
					else
						return false;
				}
				else
					return false;
			};
			return a;
		}
		else if (op == 3)
		{
			auto a = [p](string palabra) -> bool {
				int contador = 0;
				if (palabra.size() >= p.size())
				{	//		p e r r o
					int j = palabra.size() - 1;
					for (int i = p.size() - 1; i >= 0; i--)
					{
						if (palabra.at(j) == p.at(i))
							contador++;
						j--;
					}
					if (contador == p.size())
						return true;
					else
						return false;
				}
				else
					return false;
			};
			return a;
		}
		else if (op == 4)
		{
			auto a = [p](string palabra) -> bool {
				int contador = 0;
				if (palabra.size() >= p.size())
				{
					if (palabra.find(p) == string::npos)
						return false;
					else
						return true;
				}
				else
					return false;
			};
			return a;
		}
		else if (op == 5)
		{
			auto a = [p](string palabra) -> bool {
				int contador = 0;
				if (palabra.size() >= p.size())
				{
					if (palabra.find(p) == string::npos)
						return true;
					else
						return false;
				}
				else
					return false;
			};
			return a;
		}
		else if (op == 6)
		{
			system("pause");
			system("cls");
			menu();
		}
		else
		{
			system("pause");
			system("cls");
			menu();
		}
	}

	void buscarPor(function<bool(string p)> f, Archivo arch)
	{
		string auxArch = arch.obtNombre();
		auxArch.append(".txt");
		string aux;
		ifstream archB(auxArch);

		ListaDE<string> coincidencias;

		while (archB >> aux)
		{
			if (f(aux))
				coincidencias.insFinal(aux);
		}
		
		if (coincidencias.longitud() > 0)
		{
			cout << "\nLas coincidencias son:\n";
			for (size_t i = 0; i < coincidencias.longitud(); i++)
			{
				cout << coincidencias.obtPos(i) << "\n";
			}
		}
		else
		{
			cout << "\nNo se encontro coincidencias\n";
		}
		cout << "\n1. Regresar al archivo";
		cout << "\n2. Regrasar al menu";
		cout << "\nIngrese la opcion: ";
		cin >> op;
		switch(op) {
		case 1:
			system("pause");
			system("cls");
			opcionesArchivos(arch);
			break;
		default:
			system("pause");
			system("cls");
			menu();
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
	}
};
