#include <iostream>
#include <conio.h>

#include "Interfaz.h"
#include "Generador.h"

using namespace std;

int main() {
	construir_ventana();

	Cuadrado* cuadrado;
	Generador* generador = new Generador();

	while (true) {
		if (_kbhit()) {
			char tecla = getch();
			switch (tecla) {
				case 'a': 
					cuadrado = new Cuadrado(1, 1, (rand() % (5 - 1 + 1) + 1));
					generador->agregar_cuadrado(cuadrado);
					break;
				case 'c': generador->recolorear_cuadrados(); break;
				case 'e': generador->eliminar_cuadrado(0); break;
			}
		}

		if (generador->cuadrados_guardados() > 0)
			generador->mostrar_cuadrados();

		_sleep(100);
	}

	delete cuadrado, generador;

	system("pause>nul");
	return 0;
}