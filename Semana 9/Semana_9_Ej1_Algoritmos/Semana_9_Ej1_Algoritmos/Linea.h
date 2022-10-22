#pragma once
#include "Figura.h"

class Linea : public Figura {
	private: short x2, y2;
	public:
		~Linea() {}
		Linea(short x, short y, short x2, short y2) : Figura(x, y) {
			this->x2 = x2;
			this->y2 = y2;
		}

		void Dibujar(Graphics^ g, Pen^ p) {
			g->DrawLine(p, this->x, this->y, this->x2, this->y2);
		}
};