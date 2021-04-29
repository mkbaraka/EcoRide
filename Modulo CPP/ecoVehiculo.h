#ifndef ECOVEHICULO_H_
#define ECOVEHICULO_H_

class EcoVehiculo
{
private:
    char nombre[20];
    char marca[20];
    char modelo[20];
    int autonomia;
    float precio;
    int disponibles;

public:
    EcoVehiculo();
    EcoVehiculo(char *, char *, char *, int, float, int);
    ~EcoVehiculo();
    char *getNombre();
    char *getMarca();
    char *getModelo();
    int getAutonomia();
    float getPrecio();
    int getDisponibles();
    virtual void imprimir();
};

#endif