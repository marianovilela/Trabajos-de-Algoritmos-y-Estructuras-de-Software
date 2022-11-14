#include<iostream>
#include<conio.h>

using namespace std;

void imprimir_cuadrado_for(int lado) {
	for (int i = 0; i < lado; i++) {
		for (int j = 0; j < lado; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

/*
void _imprimir_cuadrado(int lado,int h) {
	if (lado == h) {
		return;
	}
	_imprimir_linea(lado, 0);
	cout << endl;
	_imprimir_cuadrado(lado, h + 1);
}

void imprimir_cuadrado(int lado) {
	_imprimir_cuadrado(lado, 0);
}
*/

void _imprimir_linea(int lado, int l) {
	if (lado == l) {
		return;
	}
	cout << "*";
	_imprimir_linea(lado, l + 1);
	cout << endl;
}



void _imprimir_linea(int lado, int l) {
	if (lado == l) {
		return;
	}
	cout << "*";
	_imprimir_linea(lado, l + 1);
	cout << endl;
	
}

void imprimir_linea(int lado) {
	_imprimir_linea(lado, 0);
}


int main() {
	imprimir_linea(2);
	_getch();
	return 0;
}