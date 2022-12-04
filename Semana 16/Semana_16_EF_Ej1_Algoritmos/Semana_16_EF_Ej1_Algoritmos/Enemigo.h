/* Enemigo.h */
#pragma once
#include <iostream>
#include "Entidad.h"

class Enemigo : public Entidad {
	private: 
		bool visibility;
		int vidas;
	public:
		~Enemigo() {}
		Enemigo(int width, int height) {
			// Dimensiones del personaje en bitmap
			this->width = width;
			this->height = height;

			// Cuantos pixeles se moveran
			this->dx = 5;
			this->dy = 0;

			// Posición del enemigo
			this->x = rand() % 900;
			this->y = rand() % 500;

			// Índices del sprite
			this->idX_Sprite = 0;
			this->idY_Sprite = 1;
			
			/* Vidas */
			vidas = 4;
		}

		void Move(Graphics^ g) {
			if (x + width * 0.5 > g->VisibleClipBounds.Width || x < 0) dx *= -1;

			if (dx > 0) idY_Sprite = 0;
			else idY_Sprite = 2;

			x -= dx;

			idX_Sprite++;
			if (idX_Sprite > 3) idX_Sprite = 0;
		}

		void Draw(Graphics^ g, Bitmap^ sprite) {
			Rectangle portionSprite = Rectangle(idX_Sprite * width, idY_Sprite * height, width - 35, height);
			Rectangle scaleSprite = Rectangle(x, y, width * 0.5, height * 0.5);
			g->DrawImage(sprite, scaleSprite, portionSprite, GraphicsUnit::Pixel);
			//g->DrawRectangle(gcnew Pen(Color::Aqua), x, y, width * 0.5, height * 0.5);
		}

		Rectangle getRectangle() { return Rectangle(x, y, width * 0.5, height * 0.5); }
		void setVisibility(bool visibility) { this->visibility = visibility; }
		bool getVisibility() { return this->visibility; }
		int getVidas() { return this->vidas; }
		void restarVidas() {
			if (vidas == 0) return;
			vidas--;
		}
};