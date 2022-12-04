/* Bomberman.h */
#pragma once
using namespace System::Drawing;

class Bomberman {
	private:
		int x, y, dx, dy;
		int width, height;
		int idX_Sprite, idY_Sprite;
		char direction;

	public:
		Bomberman(int width, int height) {
			// Dimensiones del personaje en bitmap
			this->width = width;
			this->height = height;

			// Cuantos pixeles se moveran
			this->dx = 2;
			this->dy = 2;

			// Posición del héroe
			this->x = 10;
			this->y = 10;

			// Índices del sprite
			this->idX_Sprite = 0;
			this->idY_Sprite = 2;
		}

		void Move(Graphics^ g, char key) {
			switch (key) {
			case 'A':
				if (x > 0) {
					direction = 'A';
					idY_Sprite = 3;
					x -= dx;
				}
				break;
			case 'D':
				if (x + width * 1.5 < g->VisibleClipBounds.Width) {
					direction = 'D';
					idY_Sprite = 1;
					x += dx;
				}
				break;
			case 'W':
				if (y > 0) {
					direction = 'W';
					idY_Sprite = 0;
					y -= dy;
				}
				break;
			case 'S':
				if (y + height * 1.5 < g->VisibleClipBounds.Height) {
					direction = 'S';
					idY_Sprite = 2;
					y += dy;
				}
				break;
			}

			idX_Sprite++;
			if (idX_Sprite > 6) idX_Sprite = 0;
		}

		void Draw(Graphics^ g, Bitmap^ sprite) {
			Rectangle portionSprite = Rectangle(idX_Sprite * width, idY_Sprite * height, width, height);
			Rectangle scaleSprite = Rectangle(x, y, width * 1.5, height * 1.5);
			g->DrawImage(sprite, scaleSprite, portionSprite, GraphicsUnit::Pixel);
		}

		Rectangle getRectangle() { return Rectangle(x, y, width * 1.5, height * 1.5); }
		char getDirection() { return this->direction; }
		int getX() { return this->x; }
		int getY() { return this->y; }
};