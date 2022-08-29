#pragma once
#include <iostream>
using namespace std;
class Plato {
	private:
		string nombre;
		bool temperatura;
		bool picante;
		int calorias;
		float precio;

	public:
		Plato() {};
		~Plato(){}
		string getNombre() { return nombre; }
		bool getTemperatura() { return temperatura; }
		bool getEsPicante() { return picante; }
		int getCalorias(){ return calorias; }
		float getPrecio(){ return precio;}

		void setNombre(string nombre) { this->nombre = nombre; }
		void setTemperatura(bool temperatura) { this -> temperatura = temperatura; }
		void setPicante(bool picante){this->picante=picante;}
		void setCalorias(int calorias){this->calorias=calorias;}
		void setPrecio(float precio) { this->precio = precio; }
		void toString(){
			cout << "Nombre: " << nombre;
			cout << "\tTemperatura: " <<((temperatura) ? "Sí":"No");
			cout << "\t\tPicante: " <<((picante) ? "Sí":"No");
			cout << "\tCalorias: " << calorias;
			cout << "\tPrecio: " << precio;
			cout << endl;
		}
};
	