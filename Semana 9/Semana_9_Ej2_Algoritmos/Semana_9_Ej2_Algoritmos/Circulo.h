#pragma once
#include "Figura.h"

class Circulo : public Figura {
	private: short diametro, dx;
	public:
		Circulo(short x, short y, short diametro) : Figura(x, y) {
			this->diametro = diametro;
			this->dx = 10;
		}

		void Borrar(Graphics^ g) {
			g->DrawEllipse(gcnew Pen(Color::White), x, y, diametro, diametro);
			//g->DrawRectangle(gcnew Pen(Color::White), x, y, diametro, diametro);
		}

		void Mover(Graphics^ g) {
			if (x + dx < 1 || x + dx > g->VisibleClipBounds.Width - 35)
				dx = dx * -1;

			x += dx;
		}
		
		void Dibujar(Graphics^ g) {
			g->DrawEllipse(gcnew Pen(Color::Red), x, y, diametro, diametro);
			//g->DrawRectangle(gcnew Pen(Color::Black), x, y, diametro, diametro);
		}

		Rectangle getRectangle() {
			return Rectangle(x, y, diametro, diametro);
		}
};