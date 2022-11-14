
/*
Si bien todos los archivos se cierran al culminar un programa, es una buena práctica 
cerrarlos de manera manual para que al revisar el código se sepa cuando se dejo de 
utilizar un archivo.
*/


#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class ArchivosTexto {
public:
	ArchivosTexto() {}
	~ArchivosTexto() {}

	vector<string> leerDesdeArchivo(string rutaArchivo) {
		ifstream miArchivo(rutaArchivo);
		string linea;
		vector<string> resultado;

		if (miArchivo.fail()) {} //ERROR
		else {
			while (!miArchivo.eof()) {
				//Lee linea por linea, hasta \n
				getline(miArchivo, linea);
				resultado.push_back(linea);
			}
			miArchivo.close();
		}
		return resultado;
	}
	void grabarEnArchivo(string rutaArchivo, vector<string> datosAGrabar) {
		ofstream miArchivo(rutaArchivo);

		if (miArchivo.fail()) {} //ERROR
		else {
			for (int i = 0; i < datosAGrabar.size(); i++)
				miArchivo << datosAGrabar.at(i);
			miArchivo.flush();
			miArchivo.close();
		}
	}
};
