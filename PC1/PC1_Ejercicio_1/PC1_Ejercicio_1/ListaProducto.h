#pragma once
#include "Producto.h"

class ListaProducto {
	private:
		Producto** productos;
		int numero_producto;

	public:
		~ListaProducto() {};
		ListaProducto() {
			productos = nullptr;
			numero_producto = 0;
		}

		int getNumero_Producto() { return numero_producto; }

		void agregar_producto(Producto* obj) {
			Producto** aux = new Producto * [numero_producto + 1];
			for (int i = 0; i < numero_producto; i++) {
				aux[i] = productos[i];
			}

			aux[numero_producto] = obj;
			numero_producto++;

			if (productos != nullptr)
				delete[] productos;

			productos = aux;
		}

		void modificar_producto(int posicion, Producto* objProducto) {
			for (int i = 0; i < numero_producto; i++) {
				if (i == posicion) {
					for (int j = posicion; j < numero_producto - 1; j++) {
						productos[j] = objProducto;
					}
				}
			}
		}

		Producto* obtener_producto(int posicion) {
			for (int i = 0; i < numero_producto; i++) {
				return productos[posicion];
			}
		}


		void mostrar_producto() {
			for (int i = 0; i < numero_producto; i++) {
				cout << "\n" << (i + 1) << ".- ";
				productos[i]->toString();
			}
		}

		void eliminar_producto(int posicion) {
			Producto** aux = new Producto * [numero_producto - 1];

			int actual = 0;
			if (productos != nullptr) {
				for (int i = 0; i < numero_producto; i++) {
					if (i == posicion) continue;
					aux[actual] = productos[i];
					++actual;
				}
			}

			if (productos != nullptr)
				delete[] productos;

			productos = aux;
			--numero_producto;
		}

		void reporte_modelo(string modelo) {
			for (int i = 0; i < numero_producto; i++) {
				if (productos[i]->getModelo() == modelo) {
					productos[i]->toString();
					cout << endl;
				}
			}
		}

		void reporte_peso(int peso) {
			for (int i = 0; i < numero_producto; i++) {
				if (productos[i]->getPeso() == peso) {
					productos[i]->toString();
					cout << endl;
				}
			}
		}
};