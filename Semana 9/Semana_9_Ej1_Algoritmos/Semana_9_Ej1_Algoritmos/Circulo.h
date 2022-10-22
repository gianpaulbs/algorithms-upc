#pragma once
#include "Figura.h"

class Circulo : public Figura {
	private: short radio;
	public: 
		~Circulo() {}
		Circulo(short x, short y, short radio) : Figura(x, y) {
			this->radio = radio;
		}

		void Dibujar(Graphics^ g, Pen^ p) {
			g->DrawEllipse(p, this->x, this->y, this->radio * 2, this->radio * 2);
		}

		double Area() {
			return 3.14 * this->radio;
		}
};