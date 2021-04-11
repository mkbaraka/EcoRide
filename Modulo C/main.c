#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "EcoVehiculo.h"
#include "EcoVehiculo.c"
#include "Cuestionario.h"
#include "Cuestionario.c"
#define MAX 100

void imprimirFactura(EcoVehiculo e)
{
    FILE *fichero;
    fichero = fopen("Factura.txt", "w");
    if (fichero == NULL)
    {
        return;
    }
    fprintf(fichero, "Nombre --> %s\n", e.nombre);
    fprintf(fichero, "Marca --> %s\n", e.marca);
    fprintf(fichero, "Modelo --> %s\n", e.modelo);
    fprintf(fichero, "Precio --> %.2f\n", e.precio);
    fclose(fichero);
}

int leerFichero(EcoVehiculo *vehiculos)
{

    FILE *fichero;
    int n = 0;
    if ((fichero = fopen("EcoVehiculo.dat", "rb")) == NULL)
    {
        return 0;
    }
    while (fread(&vehiculos[n], sizeof(EcoVehiculo), 1, fichero) != 0)
    {
        n++;
    }
    fclose(fichero);
    return n;
}

void almacenarEcoVehiculos(EcoVehiculo *ecove, int nEcove)
{
    FILE *fichero;
    printf("Vamos a almacenar %d", nEcove);
    if ((fichero = fopen("EcoVehiculo.dat", "wb")) == NULL)
    {
        printf("Error al abrir el fichero\n");

        exit(1);
    }

    for (int i = 0; i < nEcove; i++)
    {
        fwrite(&ecove[i], sizeof(EcoVehiculo), 1, fichero);
    }
    fclose(fichero);
}

//metodo para c++
//void facturacion(){  }

//main
void mostrarDisponibilidad(EcoVehiculo *vehiculos, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%s: %d unidades\n", vehiculos[i].nombre, vehiculos[i].disponibles);
}

EcoVehiculo pedirDatosEcoVehiculo()
{
    EcoVehiculo e;

    printf("Introduce el nombre: ");
    fflush(stdin);
    gets(e.nombre);
    printf("Introduce el modelo: ");
    fflush(stdin);
    gets(e.modelo);
    printf("Introduce la marca: ");
    fflush(stdin);
    gets(e.marca);
    printf("Introduce la automonía: ");
    fflush(stdin);
    scanf("%d", &e.autonomia);
    printf("Introduce el precio: ");
    fflush(stdin);
    scanf("%f", &e.precio);
    printf("Introduce el número de unidades disponibles: ");
    fflush(stdin);
    scanf("%d", &e.disponibles);
    return e;
}
void insertarNuevosVehiculos(EcoVehiculo *vehiculos, int *n)
{
    char resp;
    EcoVehiculo e;
    do
    {
        e = pedirDatosEcoVehiculo();
        vehiculos[*n] = e;
        (*n)++;
        do
        {
            printf("¿Hay más (s/n)? ");
            fflush(stdin);
            scanf("%c", &resp);
        } while (resp != 's' && resp != 'n');
    } while (resp == 's' && *n < MAX);
}
int main()
{
    Cuestionario c;
    char resp;
    //Eco patines
    int n, i;
    EcoVehiculo *vehiculos;
    vehiculos = (EcoVehiculo *)malloc(MAX * sizeof(EcoVehiculo));

    n = leerFichero(vehiculos);
    do
    {
        printf("Quieres agregar nuevos Eco-Vehiculos a la tienda, (s/n) ");
        fflush(stdin);
        scanf("%c", &resp);
    } while (resp != 's' && resp != 'n');
    if (resp == 's')
    {
        insertarNuevosVehiculos(vehiculos, &n);
    }
    int sel = 0;
    int e;

    do
    {
        printf("------------------------------------------------------------------------------------------------------------------\n\n");
        printf("                                EcoRide tu tienda de Vehiculos EcoFriendly\n");
        printf(" \n ");
        printf(" Selecciona una opcion: \n");
        printf(" \n ");
        printf("Patinetes electricas\t\t\t\t\t\t");
        printf("Bicicletas electricas\n");
        printf("\n");
        printf("1. Patinete Electrice 15 Xiaomi \t\t\t\t");
        printf("6. Bicicleta Electrica de carretera Orbea Gain 030 1X\n");
        printf("2. Patinete Electrico Ninebot Segway Max 630\t\t\t");
        printf("7. Mountain Bike Electrica Orbea Wild F5 H30 \n");
        printf("3. Patinete Electrico CECOTEC Outsider Demigod Makalu \t\t");
        printf("8. Specialized bicicleta completa Turbo Vado 51 5.0 \n");
        printf("4. Patinete Electrico Ninebot KickScooter E45E\t\t\t");
        printf("9. Bicicleta emtb lapierre overvolt am 5.5 \n");
        printf("5. Patinete Electrico EGRET-TEN V3 x 48V\t\t\t");
        printf("10. Bicicleta Cannondale Moterra \n");
        printf("\n");

        printf(" Otras opciones\n");
        printf("\n");
        printf("11.Comprar EcoVehiculo\n");
        printf("12.Realizar cuestionario\n");
        printf("13.Modificar disponibilidad\n");

        printf("\n");

        printf("                                                   0. Exit\n\n");
        printf("------------------------------------------------------------------------------------------------------------------\n");

        for (i = 11; i <= n; i++)
        {
            printf("%d. ", i);
            visualizarEcoVehiculos(vehiculos[i - 1]);
        }

        fflush(stdin);
        scanf("%i", &sel);
        printf("\n");
        if (sel >= 1 && sel <= 10)
            visualizarEcoVehiculos(vehiculos[sel - 1]);
        else
        {
            switch (sel)
            {

            case 11:
                e = seleccionarEcoVehiculo(vehiculos, n);
                printf("Compra realizada correctamente\n");
                imprimirFactura(vehiculos[e - 1]);
                break;
                //Aqui utilizariamos un metodo que nos permita hacer una factura de la compra de un EcoVehiculo.
            case 12:
                visualizarCuestionario(&c);
                break;
            case 13:
                mostrarDisponibilidad(vehiculos, n);
                e = seleccionarEcoVehiculo(vehiculos, n);
                modificarDisponibilidad(&vehiculos[e - 1]);
                mostrarDisponibilidad(vehiculos, n);
                break;
            }
        }

    } while (sel != 0);

    free(vehiculos);
    return 0;
}
