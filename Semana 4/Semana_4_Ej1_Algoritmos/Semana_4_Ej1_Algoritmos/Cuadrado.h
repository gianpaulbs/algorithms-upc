#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Cuadrado {
	private:
		short x, y, color;

	public:
		~Cuadrado() {}
		Cuadrado(short x, short y, short color) {
			this->x = x;
			this->y = y;
			this->color = color;
		}

		void setX(short x) { this->x = x; }
		void setY(short y) { this->y = y; }
		void setColor(short color) { this->color = color; }
		short getX() { return x; }
		short getY() { return y; }

		void colorear() {
			switch (color) {
				case 1: Console::ForegroundColor = ConsoleColor::Red; break;
				case 2: Console::ForegroundColor = ConsoleColor::Blue; break;
				case 3: Console::ForegroundColor = ConsoleColor::Cyan; break;
				case 4: Console::ForegroundColor = ConsoleColor::Green; break;
				case 5: Console::ForegroundColor = ConsoleColor::Magenta; break;
			}
		}

		void borrar() {
			Console::SetCursorPosition(x, y); cout << " ";
			Console::SetCursorPosition(x + 1, y); cout << " ";
			Console::SetCursorPosition(x, y + 1); cout << " ";
			Console::SetCursorPosition(x + 1, y + 1); cout << " ";
		}

		void mover() {
			if (x < 47 && y == 1) {
				x++;
			}
			else if (y < 27 && x != 1) {
				y++;
			}
			else if (x == 1 && y <= 27) {
				y--;
			}
			else if(x <= 47 && y != 0) {
				x--;
			}
		}

		void dibujar() {
			colorear();
			Console::SetCursorPosition(x, y); cout << char(219);
			Console::SetCursorPosition(x + 1, y); cout << char(219);
			Console::SetCursorPosition(x, y + 1); cout << char(219);
			Console::SetCursorPosition(x + 1, y + 1); cout << char(219);
		}
};