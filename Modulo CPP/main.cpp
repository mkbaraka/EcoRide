#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <time.h>

#include "ecoVehiculo.h"
#include "personalizacion.h"

//introducir los ficheros (CAMBIAR NOMBRES)
#define FicheroFacturacion "EcoVehiculo_compras.txt"
#define FicheroVentas "Ventas.dat"

using namespace std;

typedef struct
{

    char marca[20];
    char modelo[20];
    int autonomia;
    float precio;
    int disponibles;
    char nombre[20];
    char color[20];
    char material[20];
    char fechaDeCompra[20];
    char freno[20];
    char cuentaKm[20];
    char precioPer[20];

} EcoVehiculoP;

void verFacturas();
void personalizarVentas(Personalizacion *, Personalizacion *, Personalizacion *);
void listarVentas();
void estadisticas();

int main(int argc, char **argv)
{

    char marca[20];
    char modelo[20];
    int autonomia;
    int disponible;
    char nombre[20];
    char color[20];
    char material[20];
    char fechaDeCompra[20];
    char freno[20];
    char cuentaKm[20];
    char precioPer[20];

    strcpy(marca, "");
    strcpy(modelo, "");
    strcpy(fechaDeCompra, "");

    strcpy(nombre, "Ecopack Nature");
    strcpy(color, "gris");
    strcpy(material, "Aluminio reciclado");
    strcpy(freno, "Mecanico");
    strcpy(cuentaKm, "Garmin 530");
    strcpy(precioPer, "199");
    Personalizacion *p1 = new Personalizacion(marca, modelo, 0.0f, nombre, color, material, freno, cuentaKm, precioPer, fechaDeCompra);

    strcpy(nombre, "Ecopack Water");
    strcpy(color, "Azul");
    strcpy(material, "Fibra de vidrio Reciclada");
    strcpy(freno, "Mecanico");
    strcpy(cuentaKm, "Garmin 630");
    strcpy(precioPer, "299");

    Personalizacion *p2 = new Personalizacion(autonomia, disponible, marca, 0.0f, modelo, nombre, color, material, freno, cuentaKm, precioPer, fechaDeCompra);

    strcpy(nombre, "Ecopack Fire");
    strcpy(color, "Rojo");
    strcpy(material, "Fibra de carbono Reciclada");
    strcpy(freno, "Hidraulico");
    strcpy(cuentaKm, "Garmin 830");
    strcpy(precioPer, "399");

    Personalizacion *p3 = new Personalizacion(marca, modelo, 0.0f, nombre, color, material, freno, cuentaKm, precioPer, fechaDeCompra);

    int s = 0;

    do
    {
        cout << endl
             << endl;
        cout << "==============================================" << endl;
        cout << "EcoRide tu tienda de Vehiculos EcoFriendly" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Visualizar facturas pendientes " << endl;
        cout << "2. Personalizar EcoVentas" << endl;
        cout << "3. Visualizara ventas" << endl;
        cout << "4. Estadisticas" << endl;
        cout << "0. Exit" << endl;

        fflush(stdin);
        scanf("%i", &s);
        printf("\n\n");

        switch (s)
        {
        case 1:
            verFacturas();
            break;
        case 2:
            personalizarVentas(p1, p2, p3);
            break;
        case 3:
            listarVentas();
            break;
        case 4:
            estadisticas();
            break;
        case 0:
            cout << "Gracias por confiar en ecoRide, nos vemos pronto!!\n";
            break;
        default:
            cout << "Error introduce un numero valido\n";
        }
    } while (s != 0);

    return 0;
}
void verFacturas()
{
    ifstream reader;
    string linea;

    reader.open(FicheroFacturacion, ios::in);

    if (!reader)
    {
        cout << "Error al abrir el fichero" << endl;
        return;
    }

    int cont = 0;
    int num = 0;
    int total = 0;
    while (!reader.eof())
    {
        getline(reader, linea);
        if (!reader.eof())
        {
            if (num == 0)
            {
                total++;
                cout << endl;
                cout << linea << "  Numero: " << total << endl;
            }
            else
            {
                cout << linea << endl;
            }

            cont++;
            num++;
            if (num == 4)
            {
                num = 0;
            }
        }
    }

    reader.close();

    cont = cont / 4;
    cout << endl
         << "Hay " << cont << " facturas pendientes" << endl;
}

//hacer metodo para personalizar ventas**********************************

void listarVentas()
{
    EcoVehiculoP ecoVP;

    cout << "Vehiculos vendidos:" << endl;
    cout << "====================" << endl;

    ifstream in(FicheroVentas, ios::in);

    if (in.is_open())
    {
        while (!in.eof())
        {
            in.read((char *)&ecoVP, sizeof(ecoVP));
            if (!in.eof())
            {
                Personalizacion *p = new Personalizacion(ecoVP.marca, ecoVP.modelo, ecoVP.autonomia,
                                                         ecoVP.precio, ecoVP.disponibles, ecoVP.nombre, ecoVP.color, ecoVP.material,
                                                         ecoVP.fechaDeCompra, ecoVP.freno, ecoVP.cuentaKm);
                p->imprimir();
            }
        }
    }
    in.close();
}

// Metodo que imprime el importe total de las ventas (EcoVehiculos + personalizacion)
// Metodo que saca el EcoVehiculo mas vendido
void estadisticas()
{
    EcoVehiculoP ecoVP;
    int cont = 0;
    ifstream in(FicheroVentas, ios::in);

    double importeTotal = 0;

    if (in.is_open())
    {
        while (!in.eof())
        {
            in.read((char *)&ecoVP, sizeof(ecoVP));
            if (!in.eof())
            {
                cont++;
                importeTotal += ecoVP.precio + atof(ecoVP.precio);
            }
        }
    }
    in.close();

    printf("Importe total de ventas: %.2f\n\n", importeTotal);

    // Arrays de trabajo para buscar el vehiculo mas vendido
    Personalizacion *persons[cont];
    int cuenta[cont];
    cont = 0;

    ifstream in1(FicheroVentas, ios::in);
    if (in1.is_open())
    {
        while (!in1.eof())
        {
            Personalizacion obj;
            in1.read((char *)&ecoVP, sizeof(ecoVP));
            if (!in1.eof())
            {
                persons[cont] = new Personalizacion(ecoVP.marca, ecoVP.modelo, ecoVP.disponibles, ecoVP.nombre, ecoVP.color, ecoVP.material, ecoVP.fechaDeCompra, ecoVP.freno, ecoVP.cuentaKm, ecoVP.precioPer);
                cuenta[cont] = 1;
                cont++;
            }
        }
    }
    in1.close();

    // Se cuentan los EcoVehiculos de la misma marca
    for (int i = 0; i < cont; i++)
    {
        for (int j = 0; j < cont; j++)
        {
            if (i != j)
            {
                if (strcmp(persons[i]->getMarca(), persons[j]->getMarca()) == 0)
                {
                    cuenta[i] = cuenta[i] + 1;
                }
            }
        }
    }

    // Se anulan los EcoVehiculos iguales (poniendolos a cero), dejando solo uno
    for (int i = 0; i < cont - 1; i++)
    {
        if (cuenta[i] > 0)
        {
            for (int j = i + 1; j < cont; j++)
            {
                if (i != j)
                {
                    if (strcmp(persons[i]->getMarca(), persons[j]->getMarca()) == 0)
                    {
                        cuenta[i] = 0;
                    }
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < cont; i++)
    {
        if (cuenta[i] > max)
        {
            max = cuenta[i];
        }
    }

    cout << "El EcoVehiculo mas vendido es:" << endl;
    for (int i = 0; i < cont; i++)
    {
        if (cuenta[i] == max)
        {
            persons[i]->imprimirEcoVehiculo();
            if (max == 1)
            {
                cout << "Vendido " << max << " vez " << endl
                     << endl;
            }
            else
            {
                cout << "Vendido " << max << " veces " << endl
                     << endl;
            }
        }
    }
}
