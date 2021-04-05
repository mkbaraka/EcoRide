#ifndef ECOVEHICULO_H_
#define ECOVEHICULO_H_

typedef struct
{
    char nombre[20];
    char marca[20];
    char modelo[20];
    int autonomia;
    float precio;
    int disponibles;

} EcoVehiculo;

void visualizarEcoVehiculos(EcoVehiculo e);
int seleccionarEcoVehiculo();
void modificarDisponibilidad(EcoVehiculo *e);

#endif
