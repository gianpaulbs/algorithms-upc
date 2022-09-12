#pragma once
#include <iostream>
using namespace std;

class Producto {
	private:
		string codigo_producto;
		string producto;
		string modelo;
		int stock;
		string color;
		int peso;
		string linea;

	public:
		/* Constructor  & Destructor */
		Producto() {};
		~Producto() {};

		/* Set & Get */
		void setCodigo_Producto(string codigo_producto) { this->codigo_producto = codigo_producto; }
		void setProducto(string producto) { this->producto = producto; }
		void setModelo(string modelo) { this->modelo = modelo; }
		void setStock(int stock) { this->stock = stock; }
		void setColor(string color) { this->color = color; }
		void setPeso(int peso) { this->peso = peso; }
		void setLinea(string linea) { this->linea = linea; }

		string getCodigo_Producto() { return codigo_producto; }
		string getProducto() { return producto; }
		string getModelo() { return modelo; }
		int getStock() { return stock; }
		string getColor() { return color; }
		int getPeso() { return peso; }
		string getLinea() { return linea; }

		/* Métodos */
		void toString() {
			cout << codigo_producto << "\t";
			cout << producto << "\t";
			cout << modelo << "\t";
			cout << stock << "\t";
			cout << color << "\t";
			cout << peso << "\t";
			cout << linea << "\t";
		}
};