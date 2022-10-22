#pragma once
#include "Figura.h"

class Elipse : public Figura {
	private: short radio_a, radio_b;
	public:
		~Elipse() {}
		Elipse(short x, short y, short radio_a, short radio_b) : Figura(x, y) {
			this->radio_a = radio_a;
			this->radio_b = radio_b;
		}

		void Dibujar(Graphics^ g, Pen^ p) {
			g->DrawEllipse(p, this->x, this->y, this->radio_a * 2, this->radio_b * 2);
		}

		double Area() {
			return 3.14 * this->radio_a * this->radio_b;
		}
};