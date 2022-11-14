#include<iostream>
#include<conio.h>

using namespace std;
using namespace System;

template <typename T>
class Nodo {
private:
	T dato;
	Nodo* pSgte;
	Nodo* pAnt;
public:
	Nodo(T _dato) {
		pSgte = nullptr;
		pAnt = nullptr;
		dato = _dato;
	}

	T getDato() { return dato; }
	Nodo* getSgte() { return pSgte; }
	Nodo* getAnt() { return pAnt; }

	void setSgte(Nodo* nuevo) { pSgte = nuevo; }
	void setAnt(Nodo* nuevo) { pAnt = nuevo; }
	
};

template <typename T>
class Lista {
private:
	Nodo<T>* head;
	Nodo<T>* tail;
	int size;
public:
	Lista() {
		head = nullptr;
		size = 0;
	}

	Nodo<T>* getHead() { return head; }
	int getSize() { return size; }

	void push(T dato) {
		Nodo<T>* nuevo = new Nodo<T>(dato);
		if (head == nullptr) {
			head = nuevo;
			tail = nuevo;
		}
		else {
			Nodo<T>* aux = tail;
			
			aux->setSgte(nuevo);
			nuevo->setAnt(aux);

			nuevo->setSgte(head);
			head->setAnt(nuevo);
			tail = nuevo;
		}
		size++;
	}

	T eliminar_pos(int p) {
		int pos = 0;
		Nodo<T>* aux = head;
		T datoElim;
		while (aux != tail) {
			if (pos == p) {
				datoElim = aux->getDato();
				aux->getAnt()->setSgte(aux->getSgte());
				aux->getSgte()->setAnt(aux->getAnt());
				delete aux;
				break;
			}
			aux = aux->getSgte();
			pos++;
		}
		return datoElim;
	}

	T pop() {
		Nodo<T>* aux = tail;
		T datoElim;
		
		datoElim = aux->getDato();
		aux->getAnt()->setSgte(head);
		head->setAnt(aux->getAnt());
		tail = aux->getAnt();
		delete aux;
		size--;
		return datoElim;
	}

	void imprimir_lista() {
		Nodo<T>* aux = head;
		while (aux != tail) {
			cout<<aux->getDato()<<", ";
			aux = aux->getSgte();
		}
		cout << aux->getDato();
	}
	void _imprimir_recursivo(Nodo<T>*aux) {
		if (aux == tail) {
			cout << aux->getDato();
			return;
		}
		cout << aux->getDato() << ", ";
		_imprimir_recursivo(aux->getSgte());
	}

	void imprimir_recursivo() {
		_imprimir_recursivo(head);
		
	}

	int pos_dato(T buscar) {
		Nodo<T>* aux = head;
		int pos = 0;
		while (aux != tail) {
			if (aux->getDato() == buscar) {
				return pos;
			}
			aux = aux->getSgte();
			pos++;
		}
		if (aux->getDato() == buscar) {
			return pos;
		}
		return -1;
	}

	/*
			
	*/
};
class DNI
{
public:
	DNI(string nombre = " ", string fecha = " ", int dni = 0) :nombre(nombre), fecha(fecha), dni(dni) {}
	~DNI() {}

private:
	string nombre, fecha;
	int dni;
}; 
void ejemplo1() {
	Lista<DNI*> lista;
	lista.push(new DNI("Mariano","26/09/2001",73511595));
	lista.imprimir_lista();

}
int main() {
	ejemplo1();
	/*Lista<int>* lista = new Lista<int>();

	lista->push(20);
	lista->push(2);
	lista->push(5);
	lista->push(15);

	lista->imprimir_lista();
	cout << endl;
	//cout << lista->pop();
	//cout << endl;
	//lista->imprimir_lista();
	//cout << endl;
	//int p_5 = lista->pos_dato(5);
	//cout << "Posicion de Numero 5: " << p_5<<endl;

	//cout << lista->eliminar_pos(p_5)<<endl;
	lista->imprimir_recursivo();
	*/
	_getch();
	return 0;
}