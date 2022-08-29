#pragma once
#include <iostream>
#include "ArrEclipse.h"
#include <string>

using namespace std;

bool EsBisiesto(int anio) {
	if (anio < 10) { // 1 
		return anio % 4 == 0;
	}

	if (anio < 100 && anio >= 10) { // 2 cifras
		return anio % 4 == 0;
	}

	if (anio < 1000 && anio >= 100) { // 3 cifras
		return (anio % 100) % 4 == 0;
	}

	if (anio < 10000 && anio >= 1000) { // 4 cifras
		int primeras_cifras, ultimas_cifras;
		primeras_cifras = anio / 100;
		ultimas_cifras = anio % 100;

		if (ultimas_cifras != 0) return ultimas_cifras % 4 == 0;
		else return primeras_cifras % 4 == 0;
	}

	return false;
}

int Menu() {
	int opcion;
	do {
		system("cls");
		cout << "Registro de acontecimientos | ECLIPSES" << endl;
		cout << "--------------------------------------" << endl;

		cout << endl;

		cout << "Mantenimiento: " << endl;
		cout << "1. Mostrar datos." << endl;
		cout << "2. Registrar datos." << endl;
		cout << "3. Modificar datos." << endl;
		cout << "4. Eliminar." << endl;

		cout << endl;

		cout << "Reporte: " << endl;
		cout << "5. Reporte de Eclipses que fueron visibles en Europa." << endl;
		cout << "6. Reporte de Eclipses que ocasionaron sismos" << endl;
		cout << "7. Reporte de Eclipses que se produjeron en la noche" << endl;

		cout << endl;
		cout << "8. Salir." << endl;
		cout << "Ingrese una opción: "; cin >> opcion;
	} while (opcion < 1 || opcion > 9);

	return opcion;
}

int Mostrar_Tipos() {
	int opcion;
	do {
		system("cls");
		cout << "Tipos de eclipse: " << endl;
		cout << "1. " << tipos[0] << endl;
		cout << "2. " << tipos[1] << endl;

		cout << "Seleccione: "; cin >> opcion;
	} while (opcion < 1 || opcion > 2);

	return opcion;
}

int Mostrar_Continente() {
	int opcion;
	do {
		system("cls");
		for (int i = 0; i < 5; i++)
			cout << (i + 1) << ". " << continentes[i] << endl; //comando de exercion
			//comando de insercion >> I/O 
		cout << " Seleccione: "; cin >> opcion;
	} while (opcion < 1 || opcion > 5);

	return opcion;
}

bool Mostrar_Sismos() {
	int opcion;
	do {
		system("cls");
		cout << "¿Presenta sismos?" << endl;
		cout << "1. Si" << endl;
		cout << "2. No" << endl;

		cout << "Seleccione: "; cin >> opcion;
	} while (opcion < 1 || opcion > 2);
	return (opcion == 1) ? true : false;
}

bool Mostrar_Lluvias() {
	int opcion;
	do {
		system("cls");
		cout << "¿Presenta lluvias?" << endl;
		cout << "1. Si" << endl;
		cout << "2. No" << endl;

		cout << "Seleccione: "; cin >> opcion;
	} while (opcion < 1 || opcion > 2);
	return (opcion == 1) ? true : false;
}

int Mostrar_Hora() {
	int hora;
	do {
		system("cls");
		for (int i = 100; i < 2500; i += 100)
			cout << i << ": " << (i / 100) << (((i / 100) < 12) ? "am" : "pm") << endl;

		cout << "Seleccione: "; cin >> hora;
	} while (hora < 100 || hora > 2500);

	return hora;
}

Fecha* Mostrar_Fecha() {
	Fecha* f = new Fecha();
	int dia, mes, anio;
	do {
		system("cls");
		cout << "Ingrese el día, mes y año (dejando un espacio): ";
		cin >> dia >> mes >> anio;
	} while (mes < 1 || mes > 12 || (mes == 2 && dia > 28 && !EsBisiesto(anio)));

	f->setDia(dia);
	f->setMes(mes);
	f->setAnio(anio);

	return f;
}

void Proceso_Mostrar(ArrEclipse* objArreglo) {
	system("cls");
	objArreglo->mostrar();
	
	int opcion;
	do {
		if (opcion == 0) return;
		cout << "\nPara salir, presione la tecla 0: "; cin >> opcion;
	} while (opcion != 1);
}

void Proceso_Registrar(Eclipse* eclipse, ArrEclipse* objArreglo) {
	eclipse = new Eclipse();
	eclipse->setTipo(Mostrar_Tipos());
	eclipse->setContinente(Mostrar_Continente());
	eclipse->setSismos(Mostrar_Sismos());
	eclipse->setLluvias(Mostrar_Lluvias());
	eclipse->setHora(Mostrar_Hora());
	eclipse->setFecha(Mostrar_Fecha());

	objArreglo->registrar(eclipse);
}

void Proceso_Modificar(ArrEclipse* objArreglo) {
	system("cls");
	objArreglo->mostrar();

	int opt1, opt2;
	do {
		cout << "\nIngrese el elemento de la lista que desee modificar (Para salir presione 0): "; cin >> opt1;
		if (opt1 == 0) return;
	} while (opt1 < 0 || opt1 > objArreglo -> getN());

	system("cls");

	Eclipse* eclipseActual = new Eclipse();
	eclipseActual = objArreglo->obtenerElemento(opt1 - 1);

	cout << "¿Que atributo desea modificar?" << endl;
	cout << " 1 .- Tipo: " << eclipseActual->getTipo() << endl;
	cout << " 2 .- Fecha: " << (eclipseActual->getFecha()) -> formatearFecha() << endl;
	cout << " 3 .- Sismos: " << (eclipseActual->getSismos() ? "Sí" : "No") << endl;
	cout << " 4 .- Lluvias: " << (eclipseActual->getLluvias() ? "Sí" : "No") <<endl;
	cout << " 5 .- Visibilidad: " << eclipseActual->getContinente() << endl;
	cout << " 6 .- Hora: " << ((eclipseActual->getHora()>=12) ? to_string(eclipseActual->getHora()) + "pm" : to_string(eclipseActual->getHora()) + "am") << endl;
	cout << "Seleccione: "; cin >> opt2;

	switch(opt2) {
		case 1: eclipseActual->setTipo(Mostrar_Tipos()); break;
		case 2: eclipseActual->setFecha(Mostrar_Fecha()); break;
		case 3: eclipseActual->setSismos(Mostrar_Sismos()); break;
		case 4: eclipseActual->setLluvias(Mostrar_Lluvias()); break;
		case 5: eclipseActual->setContinente(Mostrar_Continente()); break;
		case 6: break;
	}

	objArreglo->sobreEscribirDato(opt1 - 1, eclipseActual);
}

void Proceso_Eliminar(ArrEclipse* objArreglo) {
	system("cls");
	objArreglo->mostrar();

	int opt1;
	do {
		cout << "\nIngrese el elemento de la lista que desee eliminar (Para salir presione 0): "; cin >> opt1;
		if (opt1 == 0) return;
	} while (opt1 < 0 || opt1 > objArreglo->getN());

	objArreglo->eliminarDato(opt1 - 1);
}

void Proceso_Reportes(int opcion, ArrEclipse* objArreglo) {
	system("cls");
	switch (opcion) {
		case 1: objArreglo->reporteEuropa(); break;
		case 2: objArreglo->reporteSismos(); break;
		case 3: objArreglo->reporteNoche(); break;
	}

	int opt1;
	do {
		cout << "\nPara salir presione 0: "; cin >> opt1;
		if (opt1 == 0) return;
	} while (opt1 != 0);
}