/* Controlador.h */
#pragma once
#include <vector>
#include "Bomba.h"
#include "Enemigo.h"

using namespace std;

class Controlador {
	private:
		vector<Bomba*> bombas;
		vector<Enemigo*> enemigos;
		int nEnemigosDerrotados = 0;
		bool terminarJuego = false;

	public:
		~Controlador() {}
		Controlador() {}

		void AddBombas(Bomba* bomba) {
			bombas.push_back(bomba);
		}

		void AddEnemigos(int width, int height) {
			enemigos.push_back(new Enemigo(width, height));
		}

		void MoveEverything(Graphics^ g) {
			/*for (int i = 0; i < this->bombas.size(); i++) {
				bombas[i]->Move(g);
			}*/

			for (int i = 0; i < this->enemigos.size(); i++) {
				enemigos[i]->Move(g);
			}
		}

		void DrawEverything(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpEnemigo) {
			for (int i = 0; i < this->enemigos.size(); i++) {
				enemigos[i]->Draw(g, bmpEnemigo);
			}

			for (int i = 0; i < this->bombas.size(); i++) {
				bombas[i]->Draw(g, bmpBomba);
			}
		}

		void Collision(Graphics^ g, Jugador* jugador) {
			/* Colisiones de las bombas con los bordes */
			for (int i = 0; i < this->bombas.size(); i++) {
				if (bombas[i]->getX() <= 0 ||
					bombas[i]->getY() <= 0 ||
					bombas[i]->getWidth() >= g->VisibleClipBounds.Width ||
					bombas[i]->getHeight() >= g->VisibleClipBounds.Height) {
					bombas[i]->setVisibility(false);
				}
			}

			/* Colisiones de las bombas con los enemigos */
			for (int i = 0; i < this->enemigos.size(); i++) {
				for (int j = 0; j < this->bombas.size(); j++) {
					if (enemigos[i]->getRectangle().IntersectsWith(bombas[j]->getRectangle())) {
						enemigos[i]->setVisibility(false);
						bombas[j]->setVisibility(false);
					}
				}
			}

			/* Colisión de los enemigos con bomberman */
			for (int i = 0; i < this->enemigos.size(); i++) {
				if (enemigos[i]->getRectangle().IntersectsWith(jugador->getRectangle())) {
					enemigos[i]->restarVidas();

					if (enemigos[i]->getVidas() == 0) {
						terminarJuego = true;
					}
				}
			}

			/* Eliminación de elementos en los arreglos */
			for (int i = 0; i < this->bombas.size(); i++) {
				if (!bombas[i]->getVisibility()) bombas.erase(bombas.begin() + i);
			}

			for (int i = 0; i < this->enemigos.size(); i++) {
				if (!enemigos[i]->getVisibility()) {
					enemigos.erase(enemigos.begin() + i);
					nEnemigosDerrotados++;
				}
			}
		}

		int getPuntaje() { return this->nEnemigosDerrotados * 9; }
		int getEnemidosDerrotados() { return this->nEnemigosDerrotados; }
		bool terminoJuego() { return this->terminarJuego; }
};