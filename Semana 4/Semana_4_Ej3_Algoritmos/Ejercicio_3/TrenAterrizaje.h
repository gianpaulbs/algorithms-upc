#pragma once
#include <iostream>
using namespace std;
using namespace System;

class TrenAterrizaje {
	private:
		short x, y;
		void llanta_izquierda() { Console::SetCursorPosition(x - 1, y + 1); cout << 'o'; }
		void llanta_derecha() { Console::SetCursorPosition(x + 1, y + 1); cout << 'o'; }

	public:
		~TrenAterrizaje() {}
		TrenAterrizaje(short x, short y) {
			this->x = x;
			this->y = y;
		}

		void setX(short x) { this->x = x; }
		void setY(short y) { this->y = y; }

		void dibujar() {
			/* o  o */
			llanta_izquierda();
			llanta_derecha();
		}
};