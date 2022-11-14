
/*
Hice uso de la liber�a "vector", ya que, era m�s c�modo trabajar con vectores de 
esta librer�a en vez de crear clases de arreglos. Adem�s, sus funciones eran sencillos
de aprender y manejar.
*/

#include <vector>
using namespace std;

class BaseMovimiento {
protected:
	int x, y;
	int dx, dy;
public:
	BaseMovimiento() {}
	~BaseMovimiento() {}

	void cambiarX(int nuevo) { x = nuevo; }
	void cambiarY(int nuevo) { y = nuevo; }
	void cambiarDx(int nuevo) { dx = nuevo; }
	void cambiarDy(int nuevo) { dy = nuevo; }

	int retornarX() { return x; }
	int retornarY() { return y; }
	int retornarDx() { return dx; }
	int retornarDy() { return dy; }

};

class Agente : public BaseMovimiento {
private:
	int vidas;
public:
	Agente() { vidas = 3; }
	~Agente() {}

	void cambiarVidas(int vidas) { this->vidas = vidas; }
	int retornarVidas() { return vidas; }
};

class Controladora {
private:
	vector<Agente*> agentes;
public:
	Controladora() { agentes = vector<Agente*>(); }
	~Controladora() {}

	void agregarAgente() { agentes.push_back(new Agente()); }
};