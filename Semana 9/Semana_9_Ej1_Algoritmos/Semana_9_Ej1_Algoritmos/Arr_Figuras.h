#pragma once
#include <vector>

#include "Circulo.h"
#include "Cuadrado.h"
#include "Elipse.h"
#include "Linea.h"
#include "Rectangulo.h"

using namespace std;

class Arr_Figuras {
	private:
		vector<Circulo*> circulos;
		vector<Cuadrado*> cuadrados;
		vector<Elipse*> elipses;
		vector<Linea*> lineas;
		vector<Rectangulo*> rectangulos;

	public:
		void Agregar_Circulo(Circulo* c) {
			circulos.push_back(c);
		}

		void Agregar_Cuadrado(Cuadrado* c) {
			cuadrados.push_back(c);
		}

		void Agregar_Elipse(Elipse* e) {
			elipses.push_back(e);
		}

		void Agregar_Linea(Linea* l) {
			lineas.push_back(l);
		}

		void Agregar_Rectangulo(Rectangulo* r) {
			rectangulos.push_back(r);
		}

		Circulo* Ultimo_Circulo() {
			return circulos[circulos.size() - 1];
		}

		Cuadrado* Ultimo_Cuadrado() {
			return cuadrados[cuadrados.size() - 1];
		}

		Elipse* Ultimo_Elipse() {
			return elipses[elipses.size() - 1];
		}

		Linea* Ultima_Linea() {
			return lineas[lineas.size() - 1];
		}

		Rectangulo* Ultimo_Rectangulo() {
			return rectangulos[rectangulos.size() - 1];
		}
};