#ifndef ECOVEHICULO_H_
#define ECOVEHICULO_H_

class EcoVehiculo
{
private:

    char *marca;
    char *modelo;
    int autonomia;
    float precio;
    int disponibles;

public:
    EcoVehiculo();
    EcoVehiculo( const char *, const char *, int, float, int);
    ~EcoVehiculo();
    char *getMarca() const;
    char *getModelo() const;
    int getAutonomia() const;
    float getPrecio() const;
    int getDisponibles() const;
    virtual void imprimir();
};

#endif
