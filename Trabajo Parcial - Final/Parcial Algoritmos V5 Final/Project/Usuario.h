//#include "ListaDoblementeEnlazada.h"
#include "ListaSimple.h"
#include "Archivo.h"
#include <string>
using namespace std;

class Usuario
{
private:
	string nombre;
	ListaS<Archivo> archivos;
public:
	Usuario(string n) 
	{
		nombre = n;
	}
	~Usuario() {}

	void insertarArchivoFinal(string nombre, string comentario)
	{
		archivos.insFinal(Archivo(nombre, comentario));
	}
	void cambiarComentario(int pos, string comentario)
	{
		archivos.obtPos(pos).cambComentario(comentario);
	}
	void agregarArchivo(string nuevoArchivo, string comentario)
	{
		string auxNombre = nombre;
		archivos.insFinal(Archivo(nuevoArchivo, comentario));
		auxNombre.append(".txt");
		ofstream archi(auxNombre, ofstream::app);

		archi << nuevoArchivo << "\n";

		archi.close();

		ofstream archCom(archivos.obtFinal().obtNomArchCom());
		archCom << comentario << "\n";
		archCom.close();
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
	ListaS<Archivo> obtArchivos()
	{
		return archivos;
	}
	Archivo obtArchivo(int pos)
	{
		return archivos.obtPos(pos);
	}
};
