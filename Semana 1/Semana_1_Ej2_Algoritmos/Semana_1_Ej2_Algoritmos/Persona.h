#pragma once
#include <iostream>
#include <string.h>

using namespace std;
using namespace System;

class Persona {
	private:
		// Atributos
		string nombre;
		int edad;
		int dni;
		char sexo;
		double peso;
		double altura;
		
		void comprobarSexo();

	public:
		// Constructores & Destructores
		Persona();
		Persona(string nombre, int edad, char sexo);
		Persona(int edad, int dni, char sexo, double peso, double altura);
		~Persona();

		// Set & Get
		string getNombre();
		int getEdad();
		int getDni();
		char getSexo();
		double getPeso();
		double getAltura();

		void setNombre(int nombre);
		void setEdad(int edad);
		void setDni(int dni);
		void setSexo(char sexo);
		void setPeso(double peso);
		void setAltura(double altura);

		//Metodos
		int calcularIMC();
		bool esMayorDeEdad();
	};

// Implementación de constructores y destructores
Persona::Persona() {
	this->nombre = "";
	this->edad = 0;
	this->sexo = 'H';
	this->peso = 0.0;
	this->altura = 0.0;
}

Persona::Persona(string nombre, int edad, char sexo) {
	this->nombre = nombre;
	this->edad = edad;
	this->sexo = sexo;
	this->peso = 0.0;
	this->altura = 0.0;
}

Persona::Persona(int edad, int dni, char sexo, double peso, double altura) {
	this->edad = edad;
	this->dni = dni;
	this->sexo = sexo;
	this->peso = peso;
	this->altura = altura;
}

Persona::~Persona() {}

// Implementación de Set & Get
void Persona::setNombre(int nombre) { this->nombre = nombre; }
void Persona::setEdad(int edad) { this->edad = edad; }
void Persona::setDni(int dni) { this->dni = dni; }
void Persona::setSexo(char sexo) { this->sexo = sexo; }
void Persona::setPeso(double peso) { this->peso = peso; }
void Persona::setAltura(double altura) { this->altura = altura; }

string Persona::getNombre() { return this->nombre; }
int Persona::getEdad() { return this->edad; }
int Persona::getDni() { return this->dni; }
char Persona::getSexo() { return this->sexo; }
double Persona::getPeso() { return this->peso; }
double Persona::getAltura() { return this->altura; }

// Métodos
void Persona::comprobarSexo() {
	if (sexo != 'H' && sexo != 'M') sexo = 'H';
}

int Persona::calcularIMC() {
	int resultado = this->peso / pow(this->altura, 2);
	if (resultado < 20) return -1;
	else if (resultado >= 20 && resultado <= 25) return 0;
	else return 1;
};

bool Persona::esMayorDeEdad() {
	if (this->edad < 18) return false;
	return true;
}