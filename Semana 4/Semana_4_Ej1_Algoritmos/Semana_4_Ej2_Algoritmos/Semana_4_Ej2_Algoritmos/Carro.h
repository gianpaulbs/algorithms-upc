#pragma once
#include "Llanta.h"
#include "Chasis.h"

class Carro {
	private:
		float x, dx;
		short y;
		Llanta** llantas;
		Llanta* llanta;
		Chasis* chasis;

	public:
		~Carro() {}
		Carro(float x, short y) {
			this->x = x;
			this->y = y;
			
			dx = 0.1 + (float)rand() / RAND_MAX;

			llantas = new Llanta * [4];

			llanta = new Llanta(x, y, 223);
			llantas[0] = llanta;

			llanta = new Llanta(x + 2, y, 223);
			llantas[1] = llanta;

			llanta = new Llanta(x, y + 2, 220);
			llantas[2] = llanta;

			llanta = new Llanta(x + 2, y + 2, 220);
			llantas[3] = llanta;

			chasis = new Chasis(x, y + 1);
		}

		void borrar() {
			Console::SetCursorPosition(x, y); cout << "    ";
			Console::SetCursorPosition(x, y + 1); cout << "    ";
			Console::SetCursorPosition(x, y + 2); cout << "    ";
			Console::SetCursorPosition(x, y + 3); cout << "    ";
		}

		void mover() {
			x += dx;
			llantas[0]->setX(x);
			llantas[1]->setX(x + 2);
			llantas[2]->setX(x);
			llantas[3]->setX(x + 2);

			chasis->setX(x);
		}

		void dibujar() {
			for (int i = 0; i < 4; i++) {
				llantas[i]->dibujar();
			}

			chasis->dibujar();
		}

		float getX() { return (int) x; }
};