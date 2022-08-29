#pragma once
#include <iostream>
#include <string>

#include "RedSocial.h"
#include "Fecha.h"

using namespace std;
class Contacto {
	private:
		string nombre;
		string telefono;
		string sexo;
		string facultad;
		Fecha* fechaNacimiento;
		string email;
		RedSocial* redSocial;

	public:
		Contacto() {};
		~Contacto() {};

		string getNombre() { return nombre; }
		string getTelefono() { return telefono; }
		string getSexo() { return sexo; }
		string getFacultad() { return facultad; }
		string getEmail() { return email; }
		Fecha* getFechaNacimiento() { return fechaNacimiento; }
		RedSocial* getRedSocial() { return redSocial; }

		void setNombre(string nombre) { this->nombre = nombre; }
		void setTelefono(string telefono) { this->telefono = telefono; }
		void setSexo(string sexo) { this->sexo = sexo; }
		void setFacultad(string facultad) { this->facultad = facultad; }
		void setFechaNacimiento(Fecha* fechaNacimiento) { this->fechaNacimiento = fechaNacimiento; }
		void setEmail(string email) { this->email = email; }
		void setRedSocial(RedSocial* redSocial) { this->redSocial = redSocial; }
		void toString() {
			cout << "Nombre: " << nombre << "\t";
			cout << "Telefono: " << telefono << "\t";
			cout << "Sexo: " << sexo << "\t";
			cout << "Facultad: " << facultad << "\t";
			cout << "Fecha de nacimiento: " << fechaNacimiento->formatearFecha() << "\t";
			cout << "Email: " << email << "\t";
			redSocial->toString();
		}
};