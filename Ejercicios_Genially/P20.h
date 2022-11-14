
/*
OBJECT SLICING -> Segmentación de objetos
Ocurre cuando a un objeto de la clase base se le asigna un objeto de la clase
derivada, los atributos extra de la clase derivada se segmentaran para formar
el objeto de la clase base.
*/

#include <iostream>

class CBase {
protected:
	int n;
public:
	CBase() {}
	~CBase() {}
	virtual void mostrar() {}
};

class CDerivada : public CBase {
private:
	int x, y;
public:
	CDerivada() {}
	~CDerivada() {}
	void mostrar() {
		std::cout << x;
	}
};

void function() {
	CDerivada* d = new CDerivada();
	CBase* b = new CBase();
	b = d;

	delete b, d;
}