#include "Competencia.h"

int main() {
	srand((unsigned)time(NULL));
	construir_ventana();

	Competencia* competencia = new Competencia();
	competencia->iniciar();

	system("pause>nul");
	return 0;
}