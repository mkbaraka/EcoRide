#ifndef ECOVEHICULO_H_
#define ECOVEHICULO_H_

class EcoVehiculo
{
private:
    char marca[20];
    char modelo[20];
    int autonomia;
    float precio;
    int disponibles;

public:
    EcoVehiculo();
    EcoVehiculo( char *, char *, int, float, int);
    ~EcoVehiculo();
    char *getMarca();
    char *getModelo();
    int getAutonomia();
    float getPrecio();
    int getDisponibles();
    virtual void imprimir();
};

#endif