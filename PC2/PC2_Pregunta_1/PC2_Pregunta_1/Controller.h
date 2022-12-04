/* Controller.h */
#pragma once
#include <vector>

#include "Bomberman.h"
#include "Fantasma.h"
#include "Bomba.h"

using namespace std;

class Controller {
	private:
		vector<Bomba*> bombas;
		vector<Fantasma*> fantasmas;
		int nFantasmasMuertos = 0;

	public:
		~Controller() {}
		Controller() {}

		void AddBombas(Bomba* bomba) {
			bombas.push_back(bomba);
		}

		void AddFantasmas(int width, int height) {
			fantasmas.push_back(new Fantasma(width, height));
		}

		void MoveEverything(Graphics^ g) {
			for (int i = 0; i < this->bombas.size(); i++) {
				bombas[i]->Move(g);
			}

			for (int i = 0; i < this->fantasmas.size(); i++) {
				fantasmas[i]->Move(g);
			}
		}

		void DrawEverything(Graphics^ g, Bitmap^ bmBomba, Bitmap^ bmFantasma) {
			for (int i = 0; i < this->fantasmas.size(); i++) {
				fantasmas[i]->Draw(g, bmFantasma);
			}

			for (int i = 0; i < this->bombas.size(); i++) {
				bombas[i]->Draw(g, bmBomba);
			}
		}

		void Collision(Graphics^ g, Bomberman* bomberman) {
			/* Colisiones de las bombas con los bordes */
			for (int i = 0; i < this->bombas.size(); i++) {
				if (bombas[i]->getX() <= 0 ||
					bombas[i]->getY() <= 0 ||
					bombas[i]->getWidth() >= g->VisibleClipBounds.Width ||
					bombas[i]->getHeight() >= g->VisibleClipBounds.Height) {
					bombas[i]->setVisibility(false);
				}
			}

			/* Colisiones de las bombas con los fantasmas */
			for (int i = 0; i < this->fantasmas.size(); i++) {
				for (int j = 0; j < this->bombas.size(); j++) {
					if (fantasmas[i]->getRectangle().IntersectsWith(bombas[j]->getRectangle())) {
						fantasmas[i]->setVisibility(false);
						bombas[j]->setVisibility(false);
					}
				}
			}

			/* Colisión de los fantasmas con bomberman */
			for (int i = 0; i < this->fantasmas.size(); i++) {
				if (fantasmas[i]->getRectangle().IntersectsWith(bomberman->getRectangle())) {
					/*DialogResult dr = MessageBox::Show("¡Perdiste!, fin del juego :(");
					if (dr == DialogResult::OK)
						Application::Exit();*/
				}
			}

			/* Eliminación de elementos en los arreglos */
			for (int i = 0; i < this->bombas.size(); i++) {
				if (!bombas[i]->getVisibility()) bombas.erase(bombas.begin() + i);
			}

			for (int i = 0; i < this->fantasmas.size(); i++) {
				if (!fantasmas[i]->getVisibility()) {
					fantasmas.erase(fantasmas.begin() + i);
					nFantasmasMuertos++;
				}
			}
		}

		int getPuntaje() { return this->nFantasmasMuertos * 5; }
		int getFantasmasMuertos() { return this->nFantasmasMuertos; }
};