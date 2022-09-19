#include "Contrasena.h"
#include <conio.h>
#include <time.h> 
#include <iostream>

int main() {
    srand(time(NULL));
    /* Se busca una longitud entre 10 y 15 para
       que tenga mas probabilidades de cumplir con la 
       condición del problema sobre el método esSeguro()
    */
    short longitud = rand() % (15 - 10 + 1) + 10;
    Contrasena* objeto = new Contrasena(longitud);

    for (int i = 0; i < 15; i++) {
        objeto->generarContrasena();
        cout << objeto->getContrasena();
        cout << " Fuerte: " << ((objeto->esSeguro()) ? 'V' : 'F') << " (V de verdad o F de falso)" << endl;
    }

    delete objeto;
    system("pause");
}