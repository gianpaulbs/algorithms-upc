#pragma once
// Librerías
#include <iostream>
#include <string>

// Clases
#include "Fecha.h";

using namespace std;

// Arreglos de String
string continentes[5] = { 
	"América del Sur", 
	"Europa", 
	"África", 
	"América del Norte", 
	"Asia"
};

string tipos[2] = { 
	"Lunar", 
	"Solar", 
};

class Eclipse {
	private:
		Fecha* fecha;
		int hora;
		bool sismos;
		bool lluvias;
		string continente;
		string tipo;
	public:
		// Constructores & Destructores
		Eclipse();
		~Eclipse() {};
		Eclipse(int hora, bool lluvias, bool sismos, string continente, string tipo);

		// Métodos de Acceso
		int getHora() { return hora/100; }
		bool getLluvias() { return lluvias; }
		bool getSismos() { return sismos; }
		string getContinente() { return continente; }
		string getTipo() { return tipo; }
		Fecha* getFecha() { return fecha; }

		void setHora(int hora) { 
			if (hora >= 100 && hora <= 2400) {
				this->hora = hora;
			}
		}

		void setSismos(bool sismos) { this->sismos = sismos; }
		void setLluvias(bool lluvias) { this->lluvias = lluvias; }
		void setTipo(int opcion) { this->tipo = tipos[opcion - 1]; }
		void setContinente(int opcion) { this->continente = continentes[opcion - 1]; }
		void setFecha(Fecha* f);
		void toString();
};

void Eclipse::setFecha(Fecha* f) {
	this->fecha = f;
}

Eclipse::Eclipse(){
	hora = rand()%(2400-100+1)+100;
	lluvias=rand()%2;
	sismos=rand()%2;
	continente = continentes[rand() % 5];
	tipo = tipos[rand() % 2];
	fecha = nullptr;
}

Eclipse::Eclipse(int hora, bool lluvias, bool sismos, string continentes, string tipo) {
	this->hora=hora;
	this->lluvias=lluvias;
	this->sismos = sismos;
	this->continente=continentes;
	this->tipo = tipo;
}

void Eclipse::toString() {
	cout << "Tipo: " << tipo << "\t";
	cout << "Hora: " << (to_string(hora / 100)) << ((hora >= 12) ? "pm\t" : "am\t");
	cout << "Lluvias: " << ((lluvias) ? "Sí\t" : "No\t");
	cout << "Sismos: " << ((sismos) ? "Sí\t" : "No\t");
	cout << "Continente: " << continente << "\t";
	cout << "Fecha: " << fecha -> formatearFecha();
}