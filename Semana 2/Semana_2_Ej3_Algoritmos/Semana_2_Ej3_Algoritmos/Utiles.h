#pragma once
#include <iostream>
#include <string>

#include "ArrContacto.h"

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
		cout << "Registro de contactos 5000" << endl;
		cout << "--------------------------" << endl;

		cout << endl;

		cout << "Mantenimiento: " << endl;
		cout << "1. Mostrar datos." << endl;
		cout << "2. Registrar datos." << endl;
		cout << "3. Modificar datos." << endl;
		cout << "4. Eliminar." << endl;

		cout << endl;

		cout << "Reporte: " << endl;
		cout << "5. Reporte de contactos cumplen años en mayo." << endl;
		cout << "6. Reporte de contactos que son varones." << endl;
		cout << "7. Reporte de contactos que tienen Facebook y Whatsapp" << endl;

		cout << endl;
		cout << "8. Salir." << endl;
		cout << "Ingrese una opción: "; cin >> opcion;
	} while (opcion < 1 || opcion > 9);

	return opcion;
}

string Mostrar_Nombre() {
	system("cls");
	string nombre;
	cout << "Ingrese el nombre del contacto: "; cin >> nombre;
	return nombre;
}

string Mostrar_Telefono() {
	system("cls");
	string telefono;
	cout << "Ingrese el número de teléfono del contacto: "; cin >> telefono;
	return telefono;
}

string Mostrar_Sexo() {
	int opcion;
	do {
		system("cls");
		cout << "¿Es hombre o mujer?" << endl;
		cout << "1. Hombre" << endl;
		cout << "2. Mujer" << endl;

		cout << "Seleccione: "; cin >> opcion;
	} while (opcion < 1 || opcion > 2);
	return (opcion == 1) ? "H" : "M";
}

string Mostrar_Facultad() {
	system("cls");
	string facultad;
	cout << "Ingrese la facultad del contacto: "; cin >> facultad;
	return facultad;
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

string Mostrar_Email() {
	system("cls");
	string email;
	cout << "Ingrese el email del contacto: "; cin >> email;
	return email;
}

RedSocial* Mostrar_RedSocial() {
	system("cls");
	RedSocial* rs = new RedSocial();
	string fb = "", gplus = "", tw = "", wsp = "";

	cout << "Ingrese la cuenta de Facebook del contacto (Presione X si no existe una cuenta): "; cin >> fb;
	cout << "Ingrese la cuenta de Google+ del contacto (Presione X si no existe una cuenta): "; cin >> gplus;
	cout << "Ingrese la cuenta de Twitter del contacto (Presione X si no existe una cuenta): "; cin >> tw;
	cout << "Ingrese la cuenta de Whatsapp del contacto (Presione X si no existe una cuenta): "; cin >> wsp;

	rs->setFacebook(fb);
	rs->setGooglePlus(gplus);
	rs->setTwitter(tw);
	rs->setWhatsapp(wsp);

	return rs;
}

void Proceso_Mostrar(ArrContacto* objArreglo) {
	system("cls");
	objArreglo->mostrarContactos();

	int opcion;
	do {
		if (opcion == 0) return;
		cout << "\nPara salir, presione la tecla 0: "; cin >> opcion;
	} while (opcion != 1);
}

void Proceso_Registrar(Contacto* contacto, ArrContacto* objArreglo) {
	contacto = new Contacto();
	contacto->setNombre(Mostrar_Nombre());
	contacto->setTelefono(Mostrar_Telefono());
	contacto->setSexo(Mostrar_Sexo());
	contacto->setFacultad(Mostrar_Facultad());
	contacto->setFechaNacimiento(Mostrar_Fecha());
	contacto->setEmail(Mostrar_Email());
	contacto->setRedSocial(Mostrar_RedSocial());

	objArreglo->registrarContacto(contacto);
}

void Proceso_Modificar(ArrContacto* objArreglo) {
	system("cls");
	objArreglo->mostrarContactos();

	int opt1, opt2;
	do {
		cout << "\nIngrese el elemento de la lista que desee modificar (Para salir presione 0): "; cin >> opt1;
		if (opt1 == 0) return;
	} while (opt1 < 0 || opt1 > objArreglo->getN());

	system("cls");

	Contacto* contactoActual = new Contacto();
	contactoActual = objArreglo->obtenerContacto(opt1 - 1);

	cout << "¿Que atributo desea modificar?" << endl;
	cout << " 1 .- Nombre de contacto: " << contactoActual->getNombre() << endl;
	cout << " 2 .- Teléfono: " << contactoActual->getTelefono() << endl;
	cout << " 3 .- Sexo: " << contactoActual->getSexo() << endl;
	cout << " 4 .- Facultad: " << contactoActual->getFacultad() << endl;
	cout << " 5 .- Fecha de nacimiento: " << (contactoActual->getFechaNacimiento()) ->formatearFecha() << endl;
	cout << " 6 .- Redes sociales: " << endl;
	(contactoActual->getRedSocial())->toString();
	
	cout << endl;
	cout << "Seleccione: "; cin >> opt2;

	switch (opt2) {
		case 1: contactoActual->setNombre(Mostrar_Nombre()); break;
		case 2: contactoActual->setTelefono(Mostrar_Telefono()); break;
		case 3: contactoActual->setSexo(Mostrar_Sexo()); break;
		case 4: contactoActual->setFacultad(Mostrar_Facultad()); break;
		case 5: contactoActual->setFechaNacimiento(Mostrar_Fecha()); break;
		case 6: contactoActual->setRedSocial(Mostrar_RedSocial()); break;
		default: return;
	}

	objArreglo->sobreescribirContacto(opt1 - 1, contactoActual);
}

void Proceso_Eliminar(ArrContacto* objArreglo) {
	system("cls");
	objArreglo->mostrarContactos();

	int opt1;
	do {
		cout << "\nIngrese el elemento de la lista que desee eliminar (Para salir presione 0): "; cin >> opt1;
		if (opt1 == 0) return;
	} while (opt1 < 0 || opt1 > objArreglo->getN());

	objArreglo->eliminarContacto(opt1 - 1);
}

void Proceso_Reportes(int opcion, ArrContacto* objArreglo) {
	system("cls");
	switch (opcion) {
		case 1: objArreglo->reporteAnios(); break;
		case 2: objArreglo->reporteVarones(); break;
		case 3: objArreglo->reporteRedSocial(); break;
	}

	int opt1;
	do {
		cout << "\nPara salir presione 0: "; cin >> opt1;
		if (opt1 == 0) return;
	} while (opt1 != 0);
}