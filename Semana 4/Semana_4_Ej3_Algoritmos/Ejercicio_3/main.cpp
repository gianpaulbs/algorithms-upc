#include <iostream>

#include "Interfaz.h"
#include "Generador.h"

using namespace std;
using namespace System;

int main() {
	construir_ventana();

	Generador* generador = new Generador();
	generador->aviones_aleatorios();

	while (true) {
		generador->mostrar_aviones();
		_sleep(100);
	}
	
	system("pause>nul");
	return 0;
}