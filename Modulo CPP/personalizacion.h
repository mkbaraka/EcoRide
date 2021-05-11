#ifndef PERSONALIZACION_H
#define PERSONALIZACION_H

#include "ecoVehiculo.h"

class Personalizacion : public EcoVehiculo
{
private:
    char nombre[20];
    char color[20];
    char material[20];
    char fechaDeCompra[20];
    char freno[20];
    char cuentaKm[20];

public:
    Personalizacion();
    Personalizacion(char *, char *, char *, char *, char *, char *);
    ~Personalizacion();
    char *getNombre();
    char *getColor();
    char *getMaterial();
    char *getFechaDeCompra();
    char *getFreno();
    char *getCuentaKm();
    void setFechaCompra(char *);
    void imprimir();
    void imprimirEcoVehiculo();
    void imprimirPersonal();
};

#endif
