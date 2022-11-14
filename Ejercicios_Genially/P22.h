
/*
Los constructores sirven para inicializar los atributos de las clases.
*/

#include <iostream>

class CClase {
private:
	int *n;
public:
	CClase(int n) { *this->n = n; }
	~CClase() {
		delete n;
	}

	void mostrar() {
		std::cout << *n;
	}
};

void function() {
	CClase* c = new CClase(12);
}