#pragma once
#include "Plato.h"
using namespace std;
class ArrPlato {
	private:
		Plato** arreglo;
		int N;
	public:
		ArrPlato();
		~ArrPlato();

		void registrarPlato(Plato* objplato);
		void sobreescribirPlato(int posicion, Plato* objPlato);
		void eliminarPlato(int posicion);
		void mostrarPlatos();
		void reportePicantes();
		void reporteCaros();
		Plato* seleccionarPlato(int posicion);
		float promedioPrecio();
		int getN();
};

ArrPlato::ArrPlato() {
	arreglo = nullptr;
	N = 0;
}

ArrPlato::~ArrPlato() {};

void ArrPlato::mostrarPlatos() {
	for (int i=0;i<N;i++){
		cout << to_string(i + 1) + ".- ";
		arreglo[i]->toString();
	}
}

void ArrPlato::registrarPlato(Plato* objeto) {
	Plato** aux = new Plato * [N + 1];
	for (int i = 0; i < N; i++) {
		aux[i] = arreglo[i];
	}

	aux[N] = objeto;
	N++;
	if (arreglo != nullptr)
		delete[] arreglo;

	arreglo = aux;
}

void ArrPlato::sobreescribirPlato(int posicion, Plato* objPlato) {
	for (int i=0 ; i<N ; i++){
		if(i==posicion){
			for(int j=posicion ; j<N-1 ; j++){
				arreglo[j] = objPlato;
			}
		}
	}
}

Plato* ArrPlato::seleccionarPlato(int posicion) {
	for (int i = 0; i < N; i++)
		return arreglo[posicion];
}

float ArrPlato::promedioPrecio(){
	float acumPrecio;
	for (int i=0;i<N;i++){
		acumPrecio+=arreglo[i]->getPrecio();
	}
	return acumPrecio / (float)N;
}

void ArrPlato::reportePicantes(){
	for (int i = 0;i < N; i++) {
		if (arreglo[i]->getEsPicante()) arreglo[i]->toString();
	}
}

void ArrPlato::reporteCaros(){
	for (int i = 0;i < N;i++) {
		if (arreglo[i]->getPrecio() > 100) arreglo[i]->toString();
	}
}

void ArrPlato::eliminarPlato(int posicion){
	for (int i=0;i<N;i++){
		if (i==posicion){
			for (int j=posicion;j<N;j++){
				arreglo[j] = arreglo[j++];
			}
		}
	}

	N--;
}


int ArrPlato::getN() { return N; }