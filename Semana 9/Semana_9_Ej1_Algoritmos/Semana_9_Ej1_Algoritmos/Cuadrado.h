#pragma once
#include "Figura.h"
class Cuadrado : public Figura {
	private: short lado;
	public:
		~Cuadrado() {}
		Cuadrado(short x, short y, short lado) : Figura(x, y) {
			this->lado = lado;
		}

		void Dibujar(Graphics^ g, Pen^ p) {
			g->DrawRectangle(p, this->x, this->y, this->lado, this->lado);
		}

		double Area() {
			return lado * lado;
		}
};