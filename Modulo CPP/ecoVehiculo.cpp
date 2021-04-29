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

EcoVehiculo::EcoVehiculo(char *nombre, char *marca, char *modelo, int autonomia, float precio, int disponibles)
{
    strcpy(this->nombre, nombre);
    strcpy(this->marca, marca);
    strcpy(this->modelo, modelo);
    this->autonomia = autonomia;
    this->precio = precio;
    this->disponibles = disponibles;
}

EcoVehiculo::~EcoVehiculo()
{
    delete[] this->nombre;
    delete[] this->marca;
    delete[] this->modelo;
}

char *EcoVehiculo::getNombre()
{
    return this->nombre;
}

char *EcoVehiculo::getMarca()
{
    return this->marca;
}

char *EcoVehiculo::getModelo()
{
    return this->modelo;
}

int EcoVehiculo::getAutonomia()
{
    return this->autonomia;
}

float EcoVehiculo::getPrecio()
{
    return this->precio;
}

int EcoVehiculo::getDisponibles()
{
    return this->disponibles;
}

void EcoVehiculo::imprimir()
{
    cout << endl;
    cout << "EcoVehiculo: " << endl;
    cout << "--------- " << endl;
    cout << "Nombre: " << this->getNombre() << endl;
    cout << "Marca: " << this->getMarca() << endl;
    cout << "Modelo: " << this->getModelo() << endl;
    cout << "Autonomia: " << this->getAutonomia() << endl;
    cout << "Precio: " << this->getPrecio() << endl;
    cout << "Disponibles: " << this->getDisponibles() << endl;
}