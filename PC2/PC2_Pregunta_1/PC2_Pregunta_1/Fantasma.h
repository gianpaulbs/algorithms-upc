/* Fantasma.h */
#pragma once
#include <iostream>

using namespace System::Drawing;

class Fantasma {
	private:
		int x, y, dx, dy;
		int width, height;
		int idX_Sprite, idY_Sprite;
		bool visibility;

	public:
		~Fantasma() {}
		Fantasma(int width, int height) {
			this->width = width;
			this->height = height;

			this->x = rand() % 700;
			this->y = rand() % 400;
			this->dx = 5;
			this->dy = 0;

			this->idX_Sprite = 0;
			this->idY_Sprite = 1;

			this->visibility = true;
		}

		void Move(Graphics^ g) {
			if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0) dx *= -1;
			if (dx > 0) idY_Sprite = 1;
			else idY_Sprite = 0;

			x -= dx;

			idX_Sprite++;
			if (idX_Sprite > 2) idX_Sprite = 0;
		}

		void Draw(Graphics^ g, Bitmap^ sprite) {
			Rectangle portionSprite = Rectangle(idX_Sprite * width, idY_Sprite * height, width, height);
			Rectangle scaleSprite = Rectangle(x, y, width * 1.0, height * 1.0);
			g->DrawImage(sprite, scaleSprite, portionSprite, GraphicsUnit::Pixel);
		}

		Rectangle getRectangle() { return Rectangle(x, y, width * 1.0, height * 1.0); }
		void setVisibility(bool visibility) { this->visibility = visibility; }
		bool getVisibility() { return this->visibility; }
};