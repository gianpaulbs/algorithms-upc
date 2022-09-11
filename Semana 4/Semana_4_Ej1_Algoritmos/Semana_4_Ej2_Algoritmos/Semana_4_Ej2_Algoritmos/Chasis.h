#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Chasis {
	private:
		short x, y;

	public:
		~Chasis() {}
		Chasis(short x, short y) {
			this->x = x;
			this->y = y;
		}

		void setX(int x) { this->x = x; }
		void setY(int y) { this->y = y; }
		short getX() { return x; }
		short getY() { return y; }

		void dibujar() {
			Console::SetCursorPosition(x, y); cout << char(219);
			Console::SetCursorPosition(x + 1, y); cout << char(219);
			Console::SetCursorPosition(x + 2, y); cout << char(219);
			Console::SetCursorPosition(x + 3, y); cout << char(219);
		}
};