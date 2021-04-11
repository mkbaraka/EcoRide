#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <time.h>
#include "EcoVehiculo.h"
#include "EcoVehiculo.c"
#include "Cuestionario.h"

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
	fprintf(fichero, "Precio --> %f\n", e.precio);
	fclose(fichero);
}
int leerFichero(EcoVehiculo *vehiculos)
{

	FILE *fichero;
	int n = 0;
	if ((fichero = fopen("EcoVehiculos.dat", "rb")) == NULL)
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

int main()
{

	//Eco patines
	int n = 10;
	EcoVehiculo *vehiculos;
	vehiculos = (EcoVehiculo *)malloc(n * sizeof(EcoVehiculo));
	strcpy(vehiculos[0].nombre, "Patinete");
	strcpy(vehiculos[0].marca, "xiaomi");
	strcpy(vehiculos[0].modelo, "Electrice 15");
	vehiculos[0].autonomia = 20;
	vehiculos[0].precio = 499.99;
	vehiculos[0].disponibles, 1;

	strcpy(vehiculos[1].nombre, "Patinete");
	strcpy(vehiculos[1].marca, "Ninebot");
	strcpy(vehiculos[1].modelo, "Segway Max 630");
	vehiculos[1].autonomia = 22;
	vehiculos[1].precio = 399.99;
	vehiculos[1].disponibles, 0;

	strcpy(vehiculos[2].nombre, "Patinete");
	strcpy(vehiculos[2].marca, "CECOTEC");
	strcpy(vehiculos[2].modelo, "Segway Max 630");
	vehiculos[2].autonomia = 24;
	vehiculos[2].precio = 249.99;
	vehiculos[2].disponibles, 2;

	strcpy(vehiculos[3].nombre, "Patinete");
	strcpy(vehiculos[3].marca, "Ninebot");
	strcpy(vehiculos[3].modelo, "KickScooter E45E");
	vehiculos[3].autonomia = 18;
	vehiculos[3].precio = 350.0;
	vehiculos[3].disponibles, 3;

	strcpy(vehiculos[4].nombre, "Patinete");
	strcpy(vehiculos[4].marca, "EGRET-TEN");
	strcpy(vehiculos[4].modelo, "V3 x 48V");
	vehiculos[4].autonomia = 60;
	vehiculos[4].precio = 699.99;
	vehiculos[4].disponibles, 2;

	strcpy(vehiculos[5].nombre, "Bicicleta");
	strcpy(vehiculos[5].marca, "Orbea");
	strcpy(vehiculos[5].modelo, "Gain 030 1X");
	vehiculos[5].autonomia = 70;
	vehiculos[5].precio = 1499.99;
	vehiculos[5].disponibles, 1;

	strcpy(vehiculos[6].nombre, "Bicicleta");
	strcpy(vehiculos[6].marca, "Orbea");
	strcpy(vehiculos[6].modelo, "Wild F5 H30");
	vehiculos[6].autonomia = 80;
	vehiculos[6].precio = 1299.99;
	vehiculos[6].disponibles, 0;

	strcpy(vehiculos[7].nombre, "Bicicleta");
	strcpy(vehiculos[7].marca, "Specialized");
	strcpy(vehiculos[7].modelo, "Turbo Vado 51 5.0");
	vehiculos[7].autonomia = 90;
	vehiculos[7].precio = 1229.99;
	vehiculos[7].disponibles, 2;

	strcpy(vehiculos[8].nombre, "Bicicleta");
	strcpy(vehiculos[8].marca, "lapierre");
	strcpy(vehiculos[8].modelo, "overvolt am 5.5");
	vehiculos[8].autonomia = 100;
	vehiculos[8].precio = 1799.99;
	vehiculos[8].disponibles, 4;

	strcpy(vehiculos[9].nombre, "Bicicleta");
	strcpy(vehiculos[9].marca, "Cannondale");
	strcpy(vehiculos[9].modelo, "Moterra");
	vehiculos[9].autonomia = 120;
	vehiculos[9].precio = 1099.99;
	vehiculos[9].disponibles, 1;

	almacenarEcoVehiculos(vehiculos, n);

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
				e = seleccionarEcoVehiculo();
				break;
				printf("Compra realizada correctamente\n");
				imprimirFactura(vehiculos[e - 1]);

				//Aqui utilizariamos un metodo que nos permita hacer una factura de la compra de un EcoVehiculo.
			case 12:
				//visualizarCuestionario();
				break;
			case 13:
				e = seleccionarEcoVehiculo();
				//modificarDisponibilidad(vehiculos[e - 1]);
			}
		}

	} while (sel != 0);

	//almacenarEcoVehiculo(ecove, 10);

	free(vehiculos);
	return 0;
}
