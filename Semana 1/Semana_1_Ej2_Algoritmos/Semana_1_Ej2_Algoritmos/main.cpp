#include "Persona.h"
#include <iostream>

int main() {
    Persona* objPersona = new Persona("MARIA", 34, 'F');
    objPersona->setAltura(1.55);
    objPersona->setPeso(80);

    int imc = objPersona->calcularIMC();
    if (imc == 1) cout << objPersona->getNombre() << " tiene sobrepeso.";
    else if (imc == 0)  cout << objPersona->getNombre() << " est� debajo de su peso ideal.";
    else cout << objPersona->getNombre() << " est� en su peso ideal.";

    system("pause>nul");
}