#pragma once
#include "FrmFiguras.h"

using namespace System::Drawing;

class Figura {
	protected: short x, y;
	public:
		~Figura() {}
		Figura(short x, short y) {
			this->x = x;
			this->y = y;
		}

		virtual void Dibujar(Graphics^ g, Pen^ p) {}
		virtual double Area() { return 0.0; }
};