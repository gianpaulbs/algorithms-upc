#include "conio.h"
#include "Generador.h"
#include "Interfaz.h"

using namespace System;

int main() {
	construir_ventana();
	srand(time(NULL));

	Nave* nave;
	Generador* generador = new Generador();

	while (true) {
		if (_kbhit()) {
			char tecla = getch();
			if (tecla == 'N') {
				nave = new Nave((rand() % (69 - 11 + 1) + 11), 25);
				generador->agregar_nave(nave);
			}
		}

		if (generador->naves_guardadas() > 0) {
			if(!generador->mostrar_naves()) break;
		}

		_sleep(100);
	}

	mostrar_final();
	delete nave, generador;

	system("pause>0");
	return 0;
}