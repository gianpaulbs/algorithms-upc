#pragma once
#include "Avion.h"

class Generador {
	private:
		Avion** aviones;
		Avion* avion;
		short* N;

	public:
		~Generador() {}
		Generador() {
			aviones = nullptr;
			N = new short;
			*N = 0;
		}

		void agregar_avion(Avion* obj) {
			Avion** tmp = new Avion * [*N + 1];
			
			if (tmp != nullptr) {
				for (int i = 0; i < *N; i++) {
					tmp[i] = aviones[i];
				}
			}

			tmp[*N] = obj;
			*N = *N + 1;

			if (aviones != nullptr) delete aviones;

			aviones = tmp;
		}

		void aviones_aleatorios() {
			srand(time(NULL));
			short aleatorio = rand() % (5 - 2 + 1) + 2;
			short x = 20;

			for (int i = 0; i < aleatorio; i++) {
				avion = new Avion(x, 1);
				agregar_avion(avion);

				x += 32;
			}
		}

		void mostrar_aviones() {
			for (int i = 0; i < *N; i++) {
				if (aviones[i]->getY() + 2 < 49) {
					aviones[i]->borrar();
					aviones[i]->mover();
					aviones[i]->dibujar();
				}
			}
		}
};