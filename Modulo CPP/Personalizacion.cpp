#include <iostream>
#include <string.h>
#include "ecoVehiculo.h"
#include "personalizacion.h"

using namespace std;

Personalizacion::Personalizacion() : EcoVehiculo()
{
}
Personalizacion::Personalizacion(const char *marca, const char *modelo, const char *nombre, const char *color, const char *material, const char *fechaDeCompra, const char *freno, const char *cuentaKm, int autonomia, float precio, int disponibles) : EcoVehiculo(marca, modelo, autonomia, precio, disponibles)
{
    this->nombre = new char[strlen(nombre)+1];
    this->color = new char[strlen(color)+1];
    this->material = new char[strlen(material)+1];
    this->fechaDeCompra = new char[strlen(fechaDeCompra)+1];
    this->freno = new char[strlen(freno)+1];
    this->cuentaKm = new char[strlen(cuentaKm)+1];

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
char *Personalizacion::getNombre() const
{
    return this->nombre;
}
char *Personalizacion::getColor() const
{
    return this->color;
}
char *Personalizacion::getMaterial() const
{
    return this->material;
}
char *Personalizacion::getFechaDeCompra() const
{
    return this->fechaDeCompra;
}
char *Personalizacion::getFreno() const
{
    return this->freno;
}
char *Personalizacion::getCuentaKm() const
{
    return this->cuentaKm;
}
void Personalizacion::setFechaCompra(char *fecha)
{
    strcpy(this->fechaDeCompra, fecha);
}
