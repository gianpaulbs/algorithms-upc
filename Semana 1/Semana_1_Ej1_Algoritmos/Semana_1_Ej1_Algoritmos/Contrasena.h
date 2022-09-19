#include <iostream>
using namespace System;
using namespace std;

class Contrasena {
private:
	int longitud;
	char* contrasena;

public:
	// Constructor & Destructor
	Contrasena() {
		this->contrasena = nullptr;
		this->longitud = 8;
	}
	Contrasena(int longitud) {
		this->contrasena = nullptr;
		this->longitud = longitud;
	}

	~Contrasena() { delete[] contrasena; }

	// Set & Get
	int getLongitud() { return this->longitud; }
	char* getContrasena() { return this->contrasena; }
	void setLongitud(int longitud) { this->longitud = longitud; }

	// Métodos
	bool esSeguro() {
		int cont_mayus = 0, cont_minus = 0, cont_num = 0;
		for (int i = 0; i < longitud; i++) {
			if (this->contrasena[i] <= 'Z' && this->contrasena[i] >= 'A')cont_mayus++;
			if (this->contrasena[i] <= 'z' && this->contrasena[i] >= 'a')cont_minus++;
			if (this->contrasena[i] <= '9' && this->contrasena[i] >= '0')cont_num++;
		}
		return (cont_mayus > 2 && cont_minus > 1 && cont_num > 5);
	}

	void generarContrasena() {
		this->contrasena = new char[this->longitud + 1];
		this->contrasena[longitud] = '\0';
		
		for (int i = 0; i < longitud; i++) {
			short tipo = rand() % (3 - 1 + 1) + 1;
			short caracter;
			switch (tipo) {
				case 1: caracter = rand() % (57 - 48 + 1) + 48; break; // Números
				case 2: caracter = rand() % (90 - 65 + 1) + 65; break; // Mayúsculas
				case 3: caracter = rand() % (122 - 97 + 1) + 97; break; // Minúsculas
			}

			this->contrasena[i] = caracter;
		}
	}
};