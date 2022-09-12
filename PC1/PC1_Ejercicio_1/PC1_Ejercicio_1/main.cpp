#include <iostream>
#include "ListaProducto.h"

using namespace std;

int Menu() {
	system("cls");

	cout << "::::::::::::::::::::MENU::::::::::::::::::::" << endl;
	cout << "1. Agregar nuevo producto" << endl;
	cout << "2. Modificar productos" << endl;
	cout << "3. Mostrar productos" << endl;
	cout << "4. Eliminar producto" << endl;
	cout << "5. Reporte por modelo" << endl;
	cout << "6. Reporte por peso" << endl;
	cout << "7. Salir" << endl << endl;

	int opcion;
	do {
		cout << "Ingrese una opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 7);

	return opcion;
}

void Mostrar_Salida() {
	int opcion;
	do {
		cout << "\nPara salir, presione 0: "; cin >> opcion;
		if (opcion == 0) return;
	} while (opcion != 0);
}

void Mostrar_Cabecera() {
	system("cls");
	cout << "    " << "\t";
	cout << "Codi" << "\t";
	cout << "Producto" << "\t";
	cout << "Modelo" << "\t";
	cout << "Stock" << "\t";
	cout << "Color" << "\t";
	cout << "Peso" << "\t";
	cout << "Línea" << "\t";
	cout << endl;
}

void Proceso_Registrar(Producto* producto, ListaProducto* listaProducto) {
	system("cls");

	string codigo_producto, nombre, modelo, color, linea;
	int stock, peso;

	cout << "Ingrese el código del producto: "; cin >> codigo_producto;
	cout << "Ingrese el nombre del producto: "; cin >> nombre;
	cout << "Ingrese el modelo: "; cin >> modelo;
	cout << "Ingrese el stock: "; cin >> stock;
	cout << "Ingrese el color: "; cin >> color;
	cout << "Ingrese el peso: "; cin >> peso;
	cout << "Ingrese la linea: "; cin >> linea;

	producto = new Producto();
	producto->setCodigo_Producto(codigo_producto);
	producto->setProducto(nombre);
	producto->setModelo(modelo);
	producto->setStock(stock);
	producto->setColor(color);
	producto->setPeso(peso);
	producto->setLinea(linea);
	listaProducto->agregar_producto(producto);
}


void Proceso_Listar(ListaProducto* listaProducto, bool habSalida) {
	Mostrar_Cabecera();
	listaProducto->mostrar_producto();
	cout << endl;

	if (habSalida)
		Mostrar_Salida();
}


void Proceso_Modificar(ListaProducto* listaProducto) {
	system("cls");

	Proceso_Listar(listaProducto, false);

	int opt1;
	do {
		cout << "Seleccione el producto a modificar: ";
		cin >> opt1;
	} while (opt1 < 1 || opt1 > listaProducto->getNumero_Producto());

	system("cls");

	Producto* productoActual = new Producto();
	productoActual = listaProducto->obtener_producto(opt1 - 1);

	cout << "¿Qué atributo desea modificar?" << endl;
	cout << "1. Código (" << productoActual->getCodigo_Producto() << ")" << endl;
	cout << "2. Producto (" << productoActual->getProducto() << ")" << endl;
	cout << "3. Modelo (" << productoActual->getModelo() << ")" << endl;
	cout << "4. Stock (" << productoActual->getStock() << ")" << endl;
	cout << "5. Color (" << productoActual->getColor() << ")" << endl;
	cout << "6. Peso (" << productoActual->getPeso() << ")" << endl;
	cout << "7. Linea (" << productoActual->getLinea() << ")" << endl;
	cout << endl;

	int opt2;
	do {
		cout << "Seleccione: ";
		cin >> opt2;
	} while (opt2 < 1 || opt2 > 7);

	string codigo_producto, nombre, modelo, color, linea;
	int stock, peso;

	switch (opt2) {
	case 1:
		cout << "Ingrese el código del producto: "; cin >> codigo_producto;
		productoActual->setCodigo_Producto(codigo_producto);
		break;
	case 2:
		cout << "Ingrese el nombre del producto: "; cin >> nombre;
		productoActual->setProducto(nombre);
		break;
	case 3:
		cout << "Ingrese el modelo: "; cin >> modelo;
		productoActual->setModelo(modelo);
		break;
	case 4:
		cout << "Ingrese el stock: "; cin >> stock;
		productoActual->setStock(stock);
		break;
	case 5:
		cout << "Ingrese el color: "; cin >> color;
		productoActual->setColor(color);
		break;
	case 6:
		cout << "Ingrese el peso: "; cin >> peso;
		productoActual->setPeso(peso);
		break;
	case 7:
		cout << "Ingrese la linea: "; cin >> linea;
		productoActual->setLinea(linea);
		break;
	}

	listaProducto->modificar_producto(opt1 - 1, productoActual);
}

void Proceso_Eliminar(ListaProducto* listaProducto) {
	Proceso_Listar(listaProducto, false);

	int opcion;
	do {
		cout << "Ingrese el número del registro a eliminar: ";
		cin >> opcion;
	} while (opcion > listaProducto->getNumero_Producto() || opcion < 1);

	listaProducto->eliminar_producto(opcion - 1);
}

void Proceso_Reporte_Modelo(ListaProducto* listaProducto) {
	system("cls");

	string modelo;
	cout << "Ingrese el nombre del modelo para hacer el reporte: ";
	cin >> modelo;

	Mostrar_Cabecera();
	listaProducto->reporte_modelo(modelo);
	Mostrar_Salida();
}

void Proceso_Reporte_Peso(ListaProducto* listaProducto) {
	system("cls");

	int peso;
	cout << "Ingrese el peso del producto para hacer el reporte: ";
	cin >> peso;

	Mostrar_Cabecera();
	listaProducto->reporte_peso(peso);
	Mostrar_Salida();
}

int main() {
	setlocale(LC_ALL, "spanish");

	Producto* producto;
	ListaProducto* listaProducto = new ListaProducto();

	while (1) {
		int opcion = Menu();
		switch (opcion) {
			case 1: Proceso_Registrar(producto, listaProducto); break;
			case 2: Proceso_Modificar(listaProducto); break;
			case 3: Proceso_Listar(listaProducto, true); break;
			case 4: Proceso_Eliminar(listaProducto); break;
			case 5: Proceso_Reporte_Modelo(listaProducto); break;
			case 6: Proceso_Reporte_Peso(listaProducto); break;
			case 7: exit(0); break;
		}
	}

	delete producto, listaProducto;
	system("pause>nul");
}