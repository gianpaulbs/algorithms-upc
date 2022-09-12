#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Nave {
	private:
		short x, y;
	public:
		~Nave() {};
		Nave(short x, short y) {
			this->x = x;
			this->y = y;
		}

		void setX(short x) { this->x = x; }
		void setY(short y) { this->y = y; }
		short getX() { return x; }
		short getY() { return y; }

		void borrar() {
			Console::SetCursorPosition(x, y); cout << " ";
		}

		void mover() {
			y = y - 1;
		}

		void dibujar() {
			Console::SetCursorPosition(x, y); cout << char(254);
		}
};