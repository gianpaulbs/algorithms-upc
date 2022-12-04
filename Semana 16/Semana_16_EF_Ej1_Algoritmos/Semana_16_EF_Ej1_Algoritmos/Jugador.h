/* Jugador.h */
#pragma once
#include "Entidad.h"

class Jugador : public Entidad {
	public:
		Jugador(int width, int height) {
			this->width = width;
			this->height = height;

			// Cuantos pixeles se moveran
			this->dx = 2;
			this->dy = 2;

			// Posición del héroe
			this->x = 500;
			this->y = 300;

			// Índices del sprite
			this->idX_Sprite = 0;
			this->idY_Sprite = 0;
		}

		void Move(Graphics^ g, char key) {
			switch (key) {
				case 'A':
					if (x > 0) {
						direction = 'A';
						idX_Sprite = 0;
						x -= dx;
					}
					break;
				case 'D':
					if (x + width * 0.5 < g->VisibleClipBounds.Width) {
						direction = 'D';
						idX_Sprite = 1;
						x += dx;
					}
					break;
				case 'W':
					if (y > 0) {
						y -= dy;
					}
					break;
				case 'S':
					if (y + height * 0.5 < g->VisibleClipBounds.Height) {
						y += dy;
					}
					break;
			}
		}

		void Draw(Graphics^ g, Bitmap^ sprite) {
			Rectangle portionSprite = Rectangle(idX_Sprite * width, idY_Sprite * height, width, height + 90);
			Rectangle scaleSprite = Rectangle(x, y, width * 0.5, height * 0.5);
			g->DrawImage(sprite, scaleSprite, portionSprite, GraphicsUnit::Pixel);
		}

		//Rectangle getRectangle() { return Rectangle(x, y, width * 1.5, height * 1.5); }
		char getDirection() { return this->direction; }
		int getX() { return this->x; }
		int getY() { return this->y; }
};