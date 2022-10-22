#pragma once
#include "Figura.h"
#include <math.h>

class Triangulo : public Figura {
	private: short lado, dy;
	public:
		Triangulo(short x, short y, short lado) : Figura(x, y) {
			this->lado = lado;
			this->dy = 10;
		}

		void Borrar(Graphics^ g) {
			Point p1 = Point(x, y);
			Point p2 = Point(x + lado, y);
			Point p3 = Point((x + (x + lado)) / 2, y + (sqrt(3) * lado / 2));
			cli::array<Point>^ points = { p1, p2, p3, p1 };
			g->DrawLines(gcnew Pen(Color::White), points);
			//g->DrawRectangle(gcnew Pen(Color::White), x, y, lado, (sqrt(3) * lado / 2));
		}

		void Mover(Graphics^ g) {
			if (y + dy < 1 || y + dy > g->VisibleClipBounds.Height - 35)
				dy = dy * -1;

			y += dy;
		}

		void Dibujar(Graphics^ g) {
			Point p1 = Point(x, y);
			Point p2 = Point(x + lado, y);
			Point p3 = Point((x + (x + lado)) / 2, y + (sqrt(3) * lado / 2));
			cli::array<Point>^ points = { p1, p2, p3, p1 };
			g->DrawLines(gcnew Pen(Color::Green), points);
			//g->DrawRectangle(gcnew Pen(Color::Black), x, y, lado, (sqrt(3) * lado / 2));
		}

		Rectangle getRectangle() {
			return Rectangle(x, y, lado, (sqrt(3) * lado / 2));
		}
};