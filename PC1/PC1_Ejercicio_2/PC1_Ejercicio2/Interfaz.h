#pragma once
#include <iostream>

using namespace std;
using namespace System;

void mostrar_final() {
	Console::Clear();
	Console::SetCursorPosition(25, 13);
	cout << char(173) << "Las naves llegaron a su meta!";
}

void mostrar_meta() {
	for (int x = 10; x <= 70; x++) {
		Console::SetCursorPosition(x, 5); cout << char(220);
	}
}

void construir_ventana() {
	Console::CursorVisible = false;
	Console::SetWindowSize(80, 30);

	mostrar_meta();
}