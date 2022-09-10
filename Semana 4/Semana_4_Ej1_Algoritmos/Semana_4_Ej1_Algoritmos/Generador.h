#pragma once
#include "Cuadrado.h"

public class Generador {
private:
	Cuadrado** cuadrados;
	int* N;

public:
	Generador() {
		cuadrados = nullptr;
		N = new int;
		*N = 0;
	}

	~Generador() {}

	void agregar_cuadrado(Cuadrado* obj) {
		Cuadrado** tmp = new Cuadrado * [*N + 1];

		if (tmp != nullptr)
		{
			for (int i = 0; i < *N; i++)
			{
				tmp[i] = cuadrados[i];
			}
		}

		tmp[*N] = obj;
		*N = *N + 1;

		if (cuadrados != nullptr) delete cuadrados;

		cuadrados = tmp;
	}

	void mostrar_cuadrados() {
		for (int i = 0; i < *N; i++) {
			cuadrados[i]->borrar();
			cuadrados[i]->mover();
			cuadrados[i]->dibujar();
		}
	}

	void recolorear_cuadrados() {
		for (int i = 0; i < *N; i++) {
			cuadrados[i]->setColor(rand() % (5 - 1 + 1) + 1);
		}
	}

	void eliminar_cuadrado(int posicion) {
		cuadrados[0]->borrar();

		Cuadrado** aux = new Cuadrado * [*N - 1];

		int actual = 0;
		if (cuadrados != nullptr) {
			for (int i = 0; i < *N; i++) {
				if (i == posicion) continue;
				aux[actual] = cuadrados[i];
				++actual;
			}
		}

		if (cuadrados != nullptr)
			delete[] cuadrados;

		cuadrados = aux;

		--*N;
	}

	int cuadrados_guardados() {
		return *N;
	}
};