#pragma once
#include <iostream>

using namespace std;
using namespace System;

void pista_aterrizaje() {
	for (int x = 0; x < 169; x++) {
		Console::SetCursorPosition(x, 49); cout << char(177);
	}
}

void construir_ventana() {
	Console::CursorVisible = false;
	Console::SetWindowSize(169, 50);

	pista_aterrizaje();
}
