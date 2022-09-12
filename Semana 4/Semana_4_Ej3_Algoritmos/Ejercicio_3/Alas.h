#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Alas {
	private:
		short x, y;
		void ala_izquierda() {
			Console::SetCursorPosition(x - 2, y + 1); cout << char(196);
			Console::SetCursorPosition(x - 3, y + 1); cout << char(196);
			Console::SetCursorPosition(x - 4, y + 1); cout << char(196);
		}

		void ala_derecha() {
			Console::SetCursorPosition(x + 2, y + 1); cout << char(196);
			Console::SetCursorPosition(x + 3, y + 1); cout << char(196);
			Console::SetCursorPosition(x + 4, y + 1); cout << char(196);
		}

	public:
		~Alas() {}
		Alas(short x, short y) {
			this->x = x;
			this->y = y;
		}

		void setX(short x) { this->x = x; }
		void setY(short y) { this->y = y; }

		void dibujar() {
			/* ---   --- */
			ala_izquierda();
			ala_derecha();
		}
};