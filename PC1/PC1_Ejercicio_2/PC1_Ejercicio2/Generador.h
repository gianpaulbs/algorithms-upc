#pragma once
#include "Nave.h"

public class Generador {
	private:
		Nave** naves;
		Nave* nave;
		int* N;
		short navesGanadoras;

	public:
		Generador() {
			naves = nullptr;
			N = new int;
			*N = 0;
			navesGanadoras = 0;
		}

		~Generador() {}

		void agregar_nave(Nave* obj) {
			Nave** tmp = new Nave * [*N + 1];

			if (tmp != nullptr)
			{
				for (int i = 0; i < *N; i++)
				{
					tmp[i] = naves[i];
				}
			}

			tmp[*N] = obj;
			*N = *N + 1;

			if (naves != nullptr) delete naves;

			naves = tmp;
		}

		bool mostrar_naves() {
			if (navesGanadoras == 5) return false;

			for (int i = 0; i < *N; i++) {
				naves[i]->borrar();

				if (naves[i]->getY() > 0) {
					naves[i]->mover();
					naves[i]->dibujar();
				}

				if (naves[i]->getY() == 5) navesGanadoras++;
				if (naves[i]->getY() == 4) {
					Console::SetCursorPosition(naves[i]->getX(), naves[i]->getY() + 1);
					cout << char(220);
				}
			}

			return true;
		}

		int naves_guardadas() {
			return *N;
		}
};