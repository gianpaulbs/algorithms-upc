/* Bomba.h */
#pragma once
using namespace System::Drawing;

class Bomba {
	private:
		int x, y, dx, dy;
		int width, height;
		int idX_Sprite, idY_Sprite;
		int directionBomberman;
		bool visibility;

	public:
		Bomba(int x, int y, int width, int height, int directionBomberman) {
			this->width = width;
			this->height = height;
			this->directionBomberman = directionBomberman;

			this->dx = 10;
			this->dy = 10;

			this->x = x;
			this->y = y;

			this->visibility = true;
		}

		void Move(Graphics^ g) {
			if (directionBomberman == 'A' && x >= 0) x -= dx;
			if (directionBomberman == 'D' && x + width * 0.2 <= g->VisibleClipBounds.Width) x += dx;
			if (directionBomberman == 'W' && y >= 0) y -= dy;
			if (directionBomberman == 'S' && y + height * 0.2 <= g->VisibleClipBounds.Height) y += dy;
		}

		void Draw(Graphics^ g, Bitmap^ sprite) {
			g->DrawImage(sprite, x, y, width * 0.2, height * 0.2);
		}

		Rectangle getRectangle() { return Rectangle(x, y, width * 0.2, height * 0.2); }

		void setVisibility(bool v) { visibility = v; }
		int getX() { return x; }
		int getY() { return y; }
		int getWidth() { return x + width * 0.2; }
		int getHeight() { return y + height * 0.2; }
		bool getVisibility() { return visibility; }
};