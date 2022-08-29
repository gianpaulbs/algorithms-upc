#pragma once
#include "Eclipse.h"

class ArrEclipse {
private:
	Eclipse** arreglo;
	int N;
public:
	ArrEclipse();
	~ArrEclipse() {}
	void mostrar();
	void registrar(Eclipse* objeto);
	void eliminarDato(int posicion);
	void reporteEuropa();
	void reporteSismos();
	void reporteNoche();
	void sobreEscribirDato(int posicion, Eclipse* objEclipse);

	int getN() { return N; }
	Eclipse* obtenerElemento(int posicion);
};

ArrEclipse::ArrEclipse(){
	arreglo=nullptr;
	N = 0;
}

void ArrEclipse::mostrar() {
	for (int i = 0;i < N;i++) {
		cout << "\n" << (i + 1) << ".- ";
		arreglo[i]->toString();
	}
}

void ArrEclipse::registrar(Eclipse* objeto) {
	Eclipse** aux = new Eclipse * [N + 1];
	for (int i = 0; i < N; i++) {
		aux[i] = arreglo[i];
	}

	aux[N] = objeto;
	N++;
	if (arreglo != nullptr)
		delete[] arreglo;

	arreglo = aux;
}

void ArrEclipse::eliminarDato(int posicion){
	for (int i=0;i<N;i++){
		if (i==posicion){
			for (int j=posicion;j<N-1;j++){
				arreglo[j]=arreglo[j++];
			}
		}
	}

	N--;
}

void ArrEclipse::sobreEscribirDato(int posicion, Eclipse* objEclipse){
	for (int i = 0; i < N; i++){
		if (i == posicion){
			for (int j = posicion; j < N - 1; j++){
				arreglo[j] = objEclipse;			}
		}
	}
}

Eclipse* ArrEclipse::obtenerElemento(int posicion){
	for (int i=0;i<N;i++){
		return arreglo[posicion]; 
	}
}

void ArrEclipse::reporteEuropa(){
	for (int i=0;i<N;i++){
		if(arreglo[i]->getContinente() == "Europa"){
			arreglo[i]->toString();
		}
	}
}

void ArrEclipse::reporteSismos(){
	for (int i=0;i<N;i++){
		if(arreglo[i]->getSismos()) {
			arreglo[i]->toString();
		}
	}
}

void ArrEclipse::reporteNoche(){
	for (int i=0;i<N;i++){
		if(arreglo[i]->getHora() >= 18){
			arreglo[i]->toString();
		}
	}
}