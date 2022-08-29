#pragma once
#include <string>
using namespace std;
class Fecha {
	private:
		int dia;
		int mes;
		int anio;

	public:
		Fecha() {};
		~Fecha() {};

		int getDia() { return this->dia; }
		int getMes() { return this->mes; }
		int getAnio() { return this->anio; }
		void setDia(int dia) { this->dia = dia; }
		void setMes(int mes) { this->mes = mes; }
		void setAnio(int anio) { this->anio = anio; }

		string formatearFecha() {
			string formatDate = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
			return formatDate;
		}
};
