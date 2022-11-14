
/*
La herencia es la característica única del POO la cual permite que una clase derivada 
tenga los atributos de una clase base. En el caso de mi proyecto lo use cuando cree
una clase base llamada BaseMovimiento y herede sus atributos y métodos a distintas clases
derivadas, tales como "Aliados", "Lider", "Agentes", "Obstáculos", etc.Vale anotar que el 
tipo de herencia por defecto en C++, cuando no se especifica explicitamente ese campo, es la herencia privada,
*/

class BaseMovimiento {
protected:
	int x, y;

public:
	BaseMovimiento() {}
	~BaseMovimiento() {}

	void cambiarX(int x) { this->x = x; }
	void cambiarY(int y) { this->y = y; }

	int retornarX() { return x; }
	int retornarY() { return y; }

	void mover() {
		x++;
		y++;
	}
};

class CPersonaje : public BaseMovimiento {
private:
	int vida;
public:
	CPersonaje() : BaseMovimiento() {}
	~CPersonaje() {}

	void cambiarVida(int vida) { this->vida = vida; }

	int retornarVida() { return vida; }

	void mover() {
		x--;
		y--;
	}
};
