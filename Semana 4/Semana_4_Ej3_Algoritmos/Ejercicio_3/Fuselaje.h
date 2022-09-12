#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Fuselaje {
	private:
		short x, y;
		void cola() {
			Console::SetCursorPosition(x, y - 1); cout << "~~~";
			Console::SetCursorPosition(x - 2, y); cout << char(95);
			Console::SetCursorPosition(x - 1, y); cout << char(95);
			Console::SetCursorPosition(x, y); cout << char(124);
			Console::SetCursorPosition(x + 1, y); cout << char(95);
			Console::SetCursorPosition(x + 2, y); cout << char(95);
		}

		void cuerpo() { Console::SetCursorPosition(x, y + 1); cout << "O"; }

	public:
		~Fuselaje() {};
		Fuselaje(short x, short y) {
			this->x = x;
			this->y = y;
		}

		void setX(short x) { this->x = x; }
		void setY(short y) { this->y = y; }

		void dibujar() {
			/* 
			*    ~~~
			   --|--
				 O
			*/
			cola();
			cuerpo();
		}
};