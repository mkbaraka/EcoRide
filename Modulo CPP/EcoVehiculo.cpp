#include <iostream>
#include <string.h>
#include "ecoVehiculo.h"

using namespace std;

EcoVehiculo::EcoVehiculo()
{
    this->autonomia = 0;
    this->precio = 0;
    this->disponibles = 0;
}

EcoVehiculo::EcoVehiculo(const char *marca, const char *modelo, int autonomia, float precio, int disponibles)
{
    this->marca = new char[strlen(marca+1)];
    strcpy(this->marca, marca);
    this->modelo = new char[strlen(modelo+1)];
    strcpy(this->modelo, modelo);
    this->autonomia = autonomia;
    this->precio = precio;
    this->disponibles = disponibles;
}

EcoVehiculo::~EcoVehiculo()
{
    delete[] this->marca;
    delete[] this->modelo;
}
char *EcoVehiculo::getMarca() const
{
    return this->marca;
}
char *EcoVehiculo::getModelo() const
{
    return this->modelo;
}
int EcoVehiculo::getAutonomia() const
{
    return this->autonomia;
}
float EcoVehiculo::getPrecio() const
{
    return this->precio;
}
int EcoVehiculo::getDisponibles() const
{
    return this->disponibles;
}
void EcoVehiculo::imprimir()
{
    cout << endl;
    cout << "EcoVehiculo: " << endl;
    cout << "--------- " << endl;
    cout << "Marca: " << this->getMarca() << endl;
    cout << "Modelo: " << this->getModelo() << endl;
    cout << "Autonomia: " << this->getAutonomia() << endl;
    cout << "Precio: " << this->getPrecio() << endl;
    cout << "Disponibles: " << this->getDisponibles() << endl;
}
