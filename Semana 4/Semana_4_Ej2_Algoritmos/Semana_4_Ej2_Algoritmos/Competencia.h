#pragma once
#include <conio.h>
#include "Carro.h"
#include "Interfaz.h"

class Competencia {
	private:
		Carro** carros;
		Carro* carro;

	public:
		~Competencia() {}
		Competencia() {
			carros = new Carro * [3];

			carro = new Carro(1, 1);
			carros[0] = carro;

			carro = new Carro(1, 6);
			carros[1] = carro;

			carro = new Carro(1, 11);
			carros[2] = carro;
		}

		void carrera() {
			bool terminar = false;
			while (true) {
				for (int i = 0; i < 3; i++) {
					carros[i]->borrar();
					carros[i]->mover();
					carros[i]->dibujar();

					cout << carros[i]->getX();
					if (carros[i]->getX() > 72) {
						mensaje_ganador(i);
						terminar = true;
						break;
					}

					_sleep(100);
				}

				if (terminar)
					break;
			}
		}

		void iniciar() {
			carros[0]->dibujar();
			carros[1]->dibujar();
			carros[2]->dibujar();

			while (true) {
				if (_kbhit()) {
					char tecla = getch();
					if (tecla == 'G') {
						borrar_mensaje_iniciar();
						carrera();
					}
				}
			}
		}
};