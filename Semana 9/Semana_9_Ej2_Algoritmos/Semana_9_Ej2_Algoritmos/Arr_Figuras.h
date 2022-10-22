#pragma once
#include "Circulo.h"
#include "Triangulo.h"
#include <vector>

using namespace std;
using namespace System;

class Arr_Figuras {
	private: 
		vector<Circulo*>* circulos;
		vector<Triangulo*>* triangulos;

	public:
		~Arr_Figuras() { delete circulos, triangulos; }
		Arr_Figuras() {
			circulos = new vector<Circulo*>();
			triangulos = new vector<Triangulo*>();
		}

		void agregar_circulo(Circulo* circulo) {
			circulos->push_back(circulo);
		}

		void agregar_triangulo(Triangulo* triangulo) {
			triangulos->push_back(triangulo);
		}

		void mostrar_circulos(Graphics^ g) {
			for (int i = 0; i < circulos->size(); i++) {
				circulos->at(i)->Borrar(g);
				circulos->at(i)->Mover(g);
				circulos->at(i)->Dibujar(g);
			}
		}

		void mostrar_triangulos(Graphics^ g) {
			for (int i = 0; i < triangulos->size(); i++) {
				triangulos->at(i)->Borrar(g);
				triangulos->at(i)->Mover(g);
				triangulos->at(i)->Dibujar(g);
			}
		}

		void gestionar_colision_figuras(Graphics^ g) {
			for (short i = 0; i < circulos->size(); i++) {
				for (short j = 0; j < triangulos->size(); j++) {
					if (circulos->size() > 0) {
						if (circulos->at(i)->getRectangle().IntersectsWith(triangulos->at(j)->getRectangle())) {
							circulos->at(i)->Borrar(g);
							triangulos->at(j)->Borrar(g);

							circulos->erase(circulos->begin() + i);
							triangulos->erase(triangulos->begin() + j);
						}
					}
				}
			}
		}
};