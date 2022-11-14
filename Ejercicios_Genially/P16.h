
/*
Utilice el Polimorfismo al modificar las funciones de mi clase base (BaseMovimiento) en
mis clases derivadas "Lider", "Aliados", etc.
Por ejemplo, la clase BaseMovimiento poseía un método denominado "mover", el cual se 
modifico en las clases derivadas antes mencionadas. Por un lado, el movimiento de la 
clase "Lider" era por medio de las teclas, así que se añadieron parámetros. Por otro lado,
el movimiento de los "Aliados" era automático así que se creo un algoritmo para ello.
*/

// Clase BaseMovimiento

#include <string>
using namespace std;
using namespace System::Drawing;

class BaseMovimiento {
protected:
	int x, y;
	//Coordenadas
	int dx, dy;
	//Velocidades
	int w, h;
	//w -> width (ancho)
	//h -> height (alto)
	int fila, columna;
	int maxFil, maxCol;
	float zoom;
public:
	BaseMovimiento() {}
	~BaseMovimiento() {}

	void mover(Graphics^ g) {}
	void mostrar(Graphics^ g, Bitmap^ bmp) {
		Rectangle porcion = Rectangle(columna * w, fila * h, w, h);
		Rectangle zoom = Rectangle(x, y, w * this->zoom, h * this->zoom);
		g->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
	}

	void cambiarX(int nuevo) { x = nuevo; }
	void cambiarY(int nuevo) { y = nuevo; }
	void cambiarDx(int nuevo) { dx = nuevo; }
	void cambiarDy(int nuevo) { dy = nuevo; }
	void cambiarW(int nuevo) { w = nuevo; }
	void cambiarH(int nuevo) { h = nuevo; }
	void cambiarFila(int nuevo) { fila = nuevo; }
	void cambiarColumna(int nuevo) { columna = nuevo; }
	void cambiarMaxFil(int nuevo) { maxFil = nuevo; }
	void cambiarMaxCol(int nuevo) { maxCol = nuevo; }
	void cambiarZoom(float nuevo) { zoom = nuevo; }

	int retornarX() { return x; }
	int retornarY() { return y; }
	int retornarDx() { return dx; }
	int retornarDy() { return dy; }
	int retornarW() { return w; }
	int retornarH() { return h; }
	int retornarFila() { return fila; }
	int retornarColumna() { return columna; }
	int retornarMaxFil() { return maxFil; }
	int retornarMaxCol() { return maxCol; }
	float retornarZoom() { return zoom; }

	Rectangle retornarRectangulo() {
		return Rectangle(x, y, w * zoom, h * zoom);
	}
};

// Clase Lider

class Lider : public BaseMovimiento {
private:
	bool invocar;
	//sera true si esta cerca de un habitante
	int habitanteAsistir;
	//el indice del habitante al cual se encuentra cerca y le mandara un aliado a asistirlo
	int tipoPoder;
	//indica que poder posee
	bool poderActivo;
	//mientras tenga un poder no podra usar (colisionar con) otro
	time_t inicioPoder;
	//duracion del poder
public:
	Lider() {
		zoom = 1.5;
		invocar = false;
		poderActivo = false;
		tipoPoder = 0;
	}
	~Lider() {}

	void mover(Graphics^ g, char i) {
		switch (i) {
		case 'A':
			if (x - dx >= 0) {
				x -= dx;
				fila = 1;
			}
			break;
		case 'D':
			if (x + dx + w * zoom <= g->VisibleClipBounds.Width) {
				x += dx;
				fila = 2;
			}
			break;
		case 'W':
			if (y - dy >= 0) {
				y -= dy;
				fila = 3;
			}
			break;
		case 'S':
			if (y + dy + h * zoom <= g->VisibleClipBounds.Height) {
				y += dy;
				fila = 0;
			}
			break;
		}
		columna++;
		if (columna >= maxCol) columna = 0;
	}
	void mostrar(Graphics^ g, Bitmap^ bmpNormal, Bitmap^ bmpAzul, Bitmap^ bmpAmarillo) {
		Rectangle porcion = Rectangle(columna * w, fila * h, w, h);
		Rectangle zoom = Rectangle(x, y, w * this->zoom, h * this->zoom);

		//Mientras tenga un poder no podra usar (colisionar con) otro
		if (!poderActivo)
			g->DrawImage(bmpNormal, zoom, porcion, GraphicsUnit::Pixel);
		else {
			if (tipoPoder == 1)
				g->DrawImage(bmpAmarillo, zoom, porcion, GraphicsUnit::Pixel);
			else
				g->DrawImage(bmpAzul, zoom, porcion, GraphicsUnit::Pixel);
		}
	}

	void cambiarInvocar(bool nuevo) { invocar = nuevo; }
	bool retornarInvocar() { return invocar; }
	void cambiarHabitAsistir(int nuevo) { habitanteAsistir = nuevo; }
	int retornarHabitAsistir() { return habitanteAsistir; }
	void cambiarTipoPoder(int nuevo) { tipoPoder = nuevo; }
	int retornarTipoPoder() { return tipoPoder; }
	void cambiarPoderActivo(int nuevo) { poderActivo = nuevo; }
	bool retornarPoderActivo() { return poderActivo; }
	void cambiarInicioPoder(time_t nuevo) { inicioPoder = nuevo; }
	time_t retonarInicioPoder() { return inicioPoder; }
};