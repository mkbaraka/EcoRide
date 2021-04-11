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
int seleccionarEcoVehiculo(EcoVehiculo *vehiculos, int n);
void modificarDisponibilidad(EcoVehiculo *e);
EcoVehiculo pedirDatosEcoVehiculo();
void imprimirFactura(EcoVehiculo e);

int leerFichero(EcoVehiculo *vehiculos);
void almacenarEcoVehiculos(EcoVehiculo *ecove, int nEcove);

void insertarNuevosVehiculos(EcoVehiculo *vehiculos, int *n);
void mostrarDisponibilidad(EcoVehiculo *vehiculos, int n);
#endif
