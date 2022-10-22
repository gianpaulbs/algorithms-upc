#pragma once
#include "Figura.h"

class Rectangulo : public Figura {
	private: short lado_1, lado_2;
	public:
		~Rectangulo() {}
		Rectangulo(short x, short y, short lado_1, short lado_2) : Figura(x, y) {
			this->lado_1 = lado_1;
			this->lado_2 = lado_2;
		}

		void Dibujar(Graphics^ g, Pen^ p) {
			g->DrawRectangle(p, this->x, this->y, this->lado_1, this->lado_2);
		}

		double Area() {
			return this->lado_1 * this->lado_2;
		}
};