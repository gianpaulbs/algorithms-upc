#pragma once
// Librerias
#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
#include <locale.h>

// Clases
#include "Utiles.h"
#include "Eclipse.h";
#include "ArrEclipse.h"

using namespace std;

int main() {
    // Cambiamos la codificación para que permita tildes y Ñ
    setlocale(LC_ALL, "spanish");

    // Instanciamos clases
    Eclipse* eclipse;
    ArrEclipse* objArreglo = new ArrEclipse();

    while (true) {
        int opcion = Menu();
        
        switch (opcion) {
        case 1: Proceso_Mostrar(objArreglo); break;
        case 2: Proceso_Registrar(eclipse, objArreglo); break;
        case 3: Proceso_Modificar(objArreglo); break;
        case 4: Proceso_Eliminar(objArreglo); break; //elimnar
        case 5: Proceso_Reportes(1, objArreglo); break; //reporte
        case 6: Proceso_Reportes(2, objArreglo); break; //reporte
        case 7: Proceso_Reportes(3, objArreglo); break;
        case 8: exit(0);
        }
    }

    delete objArreglo, eclipse;
    return 0;
}