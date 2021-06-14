#ifndef PERSONALIZACION_H
#define PERSONALIZACION_H

#include "ecoVehiculo.h"

class Personalizacion : public EcoVehiculo
{
private:
    char *nombre;
    char *color;
    char *material;
    char *fechaDeCompra;
    char *freno;
    char *cuentaKm;

public:
    Personalizacion();
    Personalizacion(const char *, const char *, const char *,const  char *, const char *, const char *, const char *, const char *, int, float, int);
    ~Personalizacion();
    char *getNombre() const;
    char *getColor() const;
    char *getMaterial() const;
    char *getFechaDeCompra() const;
    char *getFreno() const;
    char *getCuentaKm() const;
    void setFechaCompra(char *);
    void imprimir();
    void imprimirEcoVehiculo();
    void imprimirPersonal();
};

#endif

