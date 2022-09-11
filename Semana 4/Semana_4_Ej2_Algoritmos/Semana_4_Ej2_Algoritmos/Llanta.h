#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Llanta {
	private:
		short x, y, forma;
	public:
		~Llanta() {}
		Llanta(short x, short y, short forma) {
			this->x = x;
			this->y = y;
			this->forma = forma;
		}

		short getX() { return x; }
		short getY() { return y; }
		void setX(int x) { this->x = x; }
		void setY(int y) { this->y = y; }

		void dibujar() {
			Console::SetCursorPosition(x, y); cout << char(forma);
		}
};