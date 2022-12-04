/* Bomba.h */
#pragma once
#include "Entidad.h"

class Bomba : public Entidad {
	private:
		int directionBomberman;
		bool visibility;

	public:
		Bomba(int x, int y, int width, int height, int directionBomberman) {
			this->width = width;
			this->height = height;
			this->directionBomberman = directionBomberman;

			this->dx = 0;
			this->dy = 0;

			this->x = x;
			this->y = y;

			this->visibility = true;
		}

		void Draw(Graphics^ g, Bitmap^ sprite) {
			g->DrawImage(sprite, x, y, width * 0.3, height * 0.3);
			//g->DrawRectangle(gcnew Pen(Color::Aqua), x, y, width * 0.3, height * 0.3);
		}

		Rectangle getRectangle() { return Rectangle(x, y, width * 0.3, height * 0.3); }

		void setVisibility(bool v) { visibility = v; }
		int getX() { return x; }
		int getY() { return y; }
		int getWidth() { return x + width * 0.2; }
		int getHeight() { return y + height * 0.2; }
		bool getVisibility() { return visibility; }
};