#ifndef ECOVEHICULO_H_
#define ECOVEHICULO_H_

typedef struct ecoVehiculo
{
    char nombre[20];
    char marca[20];
    char modelo[20];
    int autonomia;
    float precio;
    int disponibles;

} ecoVehiculo;

void visualizarEcoVehiculos(Vehiculo v);
int seleccionarEcoVehiculo();
void modificarDisponibilidad(Vehiculo *v);

#endif
