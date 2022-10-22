#pragma once
using namespace System::Drawing;

class Figura {
	protected:
		short x, y;
		bool visible;

	public:
		Figura(short x, short y) {
			this->x = x;
			this->y = y;
			this->visible = true;
		}

		virtual void Borrar(Graphics^ g) {}
		virtual void Mover(Graphics^ g) {}
		virtual void Dibujar(Graphics^ g) {}

		short getX() { return this->x; }
		short getY() { return this->y; }
		void setX(short x) { this->x = x; }
		void setY(short y) { this->y = y; }
		bool isVisible() { return visible; }
		void setVisible(bool visible) { this->visible = visible; }
};