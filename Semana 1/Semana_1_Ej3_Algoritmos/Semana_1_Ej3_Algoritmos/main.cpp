#include "Cuenta.h"

int main() {
    /* Intenta jugar con los valores en ingresar y 
       depositar para confirmar las validaciones
    */
	Cuenta* cuenta = new Cuenta("Gianpaul Bernal");
    cuenta->ingresar(250);
    cuenta->retirar(100);

    system("pause>nul");
}