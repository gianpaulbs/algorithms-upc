#include "Persona.h"
#include <iostream>

int main() {
    Persona* objPersona = new Persona("MARIA", 34, 'F');
    objPersona->setAltura(1.55);
    objPersona->setPeso(80);

    int imc = objPersona->calcularIMC();
    if (imc == 1) cout << objPersona->getNombre() << " tiene sobrepeso.";
    else if (imc == 0)  cout << objPersona->getNombre() << " está debajo de su peso ideal.";
    else cout << objPersona->getNombre() << " está en su peso ideal.";

    system("pause>nul");
}