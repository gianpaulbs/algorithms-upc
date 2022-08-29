#pragma once
#include "Contacto.h"

class ArrContacto {
	private:
		Contacto** arreglo;
		int N;
	public:
		ArrContacto();
		~ArrContacto() {}

		void mostrarContactos();
		void registrarContacto(Contacto* objeto);
		void eliminarContacto(int posicion);
		void reporteAnios();
		void reporteVarones();
		void reporteRedSocial();
		void sobreescribirContacto(int posicion, Contacto* objEclipse);

		int getN();
		Contacto* obtenerContacto(int posicion);
};

ArrContacto::ArrContacto() {
	arreglo = nullptr;
	N = 0;
}

void ArrContacto::mostrarContactos() {
	for (int i = 0;i < N;i++) {
		cout << "\n" << (i + 1) << ".- ";
		arreglo[i]->toString();
	}
}

void ArrContacto::registrarContacto(Contacto* objeto) {
	Contacto** aux = new Contacto * [N + 1];
	for (int i = 0; i < N; i++) {
		aux[i] = arreglo[i];
	}

	aux[N] = objeto;
	N++;
	if (arreglo != nullptr)
		delete[] arreglo;

	arreglo = aux;
}

void ArrContacto::eliminarContacto(int posicion) {
	for (int i = 0;i < N;i++) {
		if (i == posicion) {
			for (int j = posicion;j < N - 1;j++) {
				arreglo[j] = arreglo[j++];
			}
		}
	}
	N--;
}

void ArrContacto::sobreescribirContacto(int posicion, Contacto* objEclipse) {
	for (int i = 0; i < N; i++) {
		if (i == posicion) {
			for (int j = posicion; j < N - 1; j++) {
				arreglo[j] = objEclipse;
			}
		}
	}
}

Contacto* ArrContacto::obtenerContacto(int posicion) {
	for (int i = 0;i < N;i++) {
		return arreglo[posicion];
	}
}

void ArrContacto::reporteAnios() {
	for (int i = 0;i < N; i++) {
		if ((arreglo[i]->getFechaNacimiento()) -> getMes() == 5) {
			arreglo[i]->toString();
		}
	}
}

void ArrContacto::reporteVarones() {
	for (int i = 0;i < N;i++) {
		if (arreglo[i]->getSexo() == "H") {
			arreglo[i]->toString();
		}
	}
}

void ArrContacto::reporteRedSocial() {
	for (int i = 0;i < N;i++) {
		if ((arreglo[i]->getRedSocial())->getFacebook() != "" &&
			(arreglo[i]->getRedSocial())->getWhatsapp() != "") 
		{
			arreglo[i]->toString();
		}
	}
}

int ArrContacto::getN() { return N; }