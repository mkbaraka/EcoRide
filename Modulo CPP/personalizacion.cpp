#include <iostream>
#include <string.h>
#include "ecoVehiculo.h"
#include "personalizacion.h"

using namespace std;

Personalizacion::Personalizacion() : EcoVehiculo()
{
}
Personalizacion::Personalizacion(char *marca, char *modelo, char *nombre, char *color, char *material, char *fechaDeCompra, char *freno, char *cuentaKm, int autonomia, float precio, int disponibles) : EcoVehiculo(marca, modelo, autonomia, precio, disponibles)
{
    strcpy(this->nombre, nombre);
    strcpy(this->color, color);
    strcpy(this->material, material);
    strcpy(this->fechaDeCompra, fechaDeCompra);
    strcpy(this->freno, freno);
    strcpy(this->cuentaKm, cuentaKm);
}

Personalizacion::~Personalizacion()
{
    delete[] this->nombre;
    delete[] this->color;
    delete[] this->material;
    delete[] this->fechaDeCompra;
    delete[] this->freno;
    delete[] this->cuentaKm;
}

void Personalizacion::imprimir()
{
    EcoVehiculo::imprimir();

    cout << "EcoPacks de personalizacion" << endl;
    cout << "============================" << endl;
    cout << "Ecopack" << this->nombre << endl;
    cout << "Color" << this->color << endl;
    cout << "Material" << this->material << endl;
    cout << "Fecha de compra" << this->fechaDeCompra << endl;
    cout << "Tipo de freno" << this->freno << endl;
    cout << "Modelo de cuenta kilometos" << this->cuentaKm << endl;
    cout << "============================" << endl
         << endl;
}
void Personalizacion::imprimirPersonal()
{

    cout << "EcoPacks de personalizacion" << endl;
    cout << "============================" << endl;
    cout << "Ecopack" << this->nombre << endl;
    cout << "Color" << this->color << endl;
    cout << "Material" << this->material << endl;
    cout << "Tipo de freno" << this->freno << endl;
    cout << "Modelo de cuenta kilometos" << this->cuentaKm << endl;
    cout << "=============================" << endl
         << endl;
}
void Personalizacion::imprimirEcoVehiculo()
{
    EcoVehiculo::imprimir();
}
char *Personalizacion::getNombre()
{
    return this->nombre;
}
char *Personalizacion::getColor()
{
    return this->color;
}
char *Personalizacion::getMaterial()
{
    return this->material;
}
char *Personalizacion::getFechaDeCompra()
{
    return this->fechaDeCompra;
}
char *Personalizacion::getFreno()
{
    return this->freno;
}
char *Personalizacion::getCuentaKm()
{
    return this->cuentaKm;
}
void Personalizacion::setFechaCompra(char *fecha)
{
    strcpy(this->fechaDeCompra, fecha);
}
