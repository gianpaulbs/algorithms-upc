#pragma once
#include <iostream>
#include "ArrPlato.h"
#include <string>

using namespace std;

void dibujo() {
	cout << R"(
         (
          )
     __..---..__
 ,-='  /  |  \  `=-.
:--..___________..--;
 \.,_____________,./)";

	cout << endl;
	cout << endl;
}

int Menu() {
	int opcion;
	do {
		system("cls");
		cout << "Registro de platos 9000" << endl;
		cout << "-----------------------" << endl;

		cout << endl;

		cout << "Mantenimiento: " << endl;
		cout << "1. Mostrar datos." << endl;
		cout << "2. Registrar datos." << endl;
		cout << "3. Modificar datos." << endl;
		cout << "4. Eliminar." << endl;

		cout << endl;

		cout << "Reporte: " << endl;
		cout << "5. Reporte de platos picantes." << endl;
		cout << "6. Reporte de platos mas caros" << endl;

		cout << endl;
		cout << "7. Salir." << endl;

		dibujo();

		cout << "Ingrese una opción: "; cin >> opcion;
	} while (opcion < 1 || opcion > 7);

	return opcion;
}

string Mostrar_Nombre() {
	system("cls");
	string nombre;
	cout << "Ingrese el nombre del plato: "; cin >> nombre;
	return nombre;
}

bool Mostrar_Temperatura() {
	int opcion;
	do {
		system("cls");
		cout << "¿Es un plato frío o caliente?" << endl;
		cout << "1. Frío" << endl;
		cout << "2. Caliente" << endl;

		cout << "Seleccione: "; cin >> opcion;
	} while (opcion < 1 || opcion > 2);
	return (opcion == 1) ? true : false;
}

bool Mostrar_Picante() {
	int opcion;
	do {
		system("cls");
		cout << "¿Es un plato picante o no picante?" << endl;
		cout << "1. Picante" << endl;
		cout << "2. No picante" << endl;

		cout << "Seleccione: "; cin >> opcion;
	} while (opcion < 1 || opcion > 2);
	return (opcion == 1) ? true : false;
}

int Mostrar_Cantidad_Calorias() {
	system("cls");
	int calorias;
	cout << "Ingrese la cantidad de calorías: "; cin >> calorias;
	return calorias;
}

float Mostrar_Precio() {
	system("cls");
	float precio;
	cout << "Ingrese el precio: "; cin >> precio;
	return precio;
}

void Proceso_Mostrar(ArrPlato* objArreglo) {
	system("cls");
	objArreglo->mostrarPlatos();

	int opcion;
	do {
		if (opcion == 0) return;
		cout << "\nPara salir, presione la tecla 0: "; cin >> opcion;
	} while (opcion != 1);
}

void Proceso_Registrar(Plato* plato, ArrPlato* objArreglo) {
	plato = new Plato();
	plato->setNombre(Mostrar_Nombre());
	plato->setTemperatura(Mostrar_Temperatura());
	plato->setPicante(Mostrar_Picante());
	plato->setCalorias(Mostrar_Cantidad_Calorias());
	plato->setPrecio(Mostrar_Precio());

	objArreglo->registrarPlato(plato);
}

void Proceso_Modificar(ArrPlato* objArreglo) {
	system("cls");
	objArreglo->mostrarPlatos();

	int opt1, opt2;
	do {
		cout << "\nIngrese el elemento de la lista que desee modificar (Para salir presione 0): "; cin >> opt1;
		if (opt1 == 0) return;
	} while (opt1 < 0 || opt1 > objArreglo->getN());

	system("cls");

	Plato* platoActual = new Plato();
	platoActual = objArreglo->seleccionarPlato(opt1 - 1);

	cout << "¿Que atributo desea modificar?" << endl;
	cout << " 1 .- Nombre del plato: " << platoActual->getNombre() << endl;
	cout << " 2 .- Temperatura: " << (platoActual->getTemperatura() ? "Frío" : "Caliente") << endl;
	cout << " 3 .- Sabor: " << (platoActual->getEsPicante() ? "Picante" : "No picante") << endl;
	cout << " 4 .- Cantidad de calorías: " << to_string(platoActual->getCalorias()) + " kcal" << endl;
	cout << " 5 .- Precio promedio: " << "S/. " + to_string(platoActual->getPrecio()) << endl;
	cout << "Seleccione: "; cin >> opt2;

	switch (opt2) {
		case 1: platoActual->setNombre(Mostrar_Nombre()); break;
		case 2: platoActual->setTemperatura(Mostrar_Temperatura()); break;
		case 3: platoActual->setPicante(Mostrar_Picante()); break;
		case 4: platoActual->setCalorias(Mostrar_Cantidad_Calorias()); break;
		case 5: platoActual->setPrecio(Mostrar_Precio()); break;
	}

	objArreglo->sobreescribirPlato(opt1 - 1, platoActual);
}

void Proceso_Eliminar(ArrPlato* objArreglo) {
	system("cls");
	objArreglo->mostrarPlatos();

	int opt1;
	do {
		cout << "\nIngrese el elemento de la lista que desee eliminar (Para salir presione 0): "; cin >> opt1;
		if (opt1 == 0) return;
	} while (opt1 < 0 || opt1 > objArreglo->getN());

	objArreglo->eliminarPlato(opt1 - 1);
}

void Proceso_Reportes(int opcion, ArrPlato* objArreglo) {
	system("cls");
	switch (opcion) {
		case 1: objArreglo->reportePicantes(); break;
		case 2: objArreglo->reporteCaros(); break;
	}

	int opt1;
	do {
		cout << "\nPara salir presione 0: "; cin >> opt1;
		if (opt1 == 0) return;
	} while (opt1 != 0);
}