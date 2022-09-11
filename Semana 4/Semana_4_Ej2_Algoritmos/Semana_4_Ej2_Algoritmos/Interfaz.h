#pragma once
#include <iostream>
using namespace std;
using namespace System;

void borrar_mensaje_iniciar() {
	Console::SetCursorPosition(25, 17);
	cout << "                       ";

	Console::SetCursorPosition(31, 18);
	cout << "          ";
}

void mensaje_iniciar() {
	Console::SetCursorPosition(25, 17); 
	cout << "Presione G para iniciar";

	Console::SetCursorPosition(31, 18);
	cout << "la carrera";
}

void mensaje_ganador(short posicion) {
	Console::SetCursorPosition(25, 17); cout << "Gana el carro: " << posicion + 1;
}

void dibujar_meta() {
	for (int y = 1; y < 38; y++) {
		Console::SetCursorPosition(72, y); cout << (char) 179;
		y++;
	}
}

void construir_ventana() {
	Console::CursorVisible = false;
	Console::SetWindowSize(80, 20);
	dibujar_meta();
	mensaje_iniciar();
}