#include <iostream>
#include <string.h>
using namespace std;

class Cuenta {
    private:
        string titular;
        double cantidad;

    public:
        ~Cuenta() {};
        Cuenta(string titular);
        Cuenta(string titular, double cantidad);

        void setTitular(string titular);
        void setCantidad(double cantidad);
        string getTitular();
        double getCantidad();

        void ingresar(double cantidad);
        void retirar(double cantidad);
};

/* Constructores */
Cuenta::Cuenta(string titular) { this->titular = titular; }
Cuenta::Cuenta(string titular, double cantidad) {
    this->titular = titular;
    this->cantidad = cantidad;
}

/* Set & Get */
void Cuenta::setTitular(string titular) { this->titular = titular; }
void Cuenta::setCantidad(double cantidad) { this->cantidad = cantidad; }
string Cuenta::getTitular() { return this->titular; }
double Cuenta::getCantidad() { return this->cantidad; }

/* Métodos */
void Cuenta::ingresar(double cantidad) {
    if (cantidad > 0) {
        this->cantidad = cantidad;
        cout << "Se ha añadido S/. " << cantidad << " a la cuenta de " << this->titular << endl;
        return;
    }

    cout << "La cantidad del depósito no puede ser 0 o negativo" << endl;
}

void Cuenta::retirar(double cantidad) {
    this->cantidad = this->cantidad - cantidad;
    if (this->cantidad < 0) {
        this->cantidad = 0;
    }

    cout << "Retirando..." << endl;
    cout << "Saldo disponible S/." << this->cantidad << endl;
}