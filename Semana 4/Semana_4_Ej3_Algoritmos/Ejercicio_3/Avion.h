#pragma once
#include "Alas.h"
#include "Fuselaje.h"
#include "TrenAterrizaje.h"

using namespace std;
using namespace System;

class Avion {
	private:
		float x, y, dx, dy;
		short intervalo, movimiento, limIzq, limDer;
		Alas* alas;
		Fuselaje* fuselaje;
		TrenAterrizaje* trenAterrizaje;

	public:
		~Avion() {}
		Avion(short x, short y) {
			this->x = x;
			this->y = y;
			this->limDer = x + 15;
			this->limIzq = x - 15;
			this->intervalo = 0;

			this->dx = 0.1 + (float)rand() / RAND_MAX;
			this->dy = 0.3 + (float)rand() / RAND_MAX;

			alas = new Alas(x, y);
			fuselaje = new Fuselaje(x, y);
			trenAterrizaje = new TrenAterrizaje(x, y);
		}

		short getY() { return y; }

		void borrar() {
			Console::SetCursorPosition(x - 4, y); cout << "         ";
			Console::SetCursorPosition(x - 4, y + 1); cout << "         ";
		}

		void mover() {
			y += dy;

			if(intervalo == 0)
				movimiento = rand() % (2 - 1 + 1) + 1;

			switch (movimiento)
			{
				case 1:
					if (x - 6 > limIzq) x -= dx;
					else {
						x += dx;
						movimiento = 2;
					}

					break;
				case 2: 
					if (x + 5 < limDer) x += dx;
					else {
						x -= dx;
						movimiento = 1;
					}

					break;
			}

			alas->setX(x);
			alas->setY(y);
			fuselaje->setX(x);
			fuselaje->setY(y);
			trenAterrizaje->setX(x);
			trenAterrizaje->setY(y);

			if (intervalo == 8) intervalo = 0;
			else intervalo++;
		}

		void dibujar() {
			alas->dibujar();
			fuselaje->dibujar();
			trenAterrizaje->dibujar();
		}
};