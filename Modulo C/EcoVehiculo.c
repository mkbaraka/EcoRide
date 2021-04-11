#include <stdio.h>
#include "EcoVehiculo.h"
#include <stdlib.h>

void visualizarEcoVehiculos(EcoVehiculo e)
{

	printf("Nombre --> %s\n", e.nombre);
	printf("Marca --> %s\n", e.marca);
	printf("Modelo --> %s\n", e.modelo);
	printf("Precio --> %.2f\n", e.precio);
	printf("Disponibilidad --> %i\n", e.disponibles);
	printf("\n");

	return;
}

int seleccionarEcoVehiculo(EcoVehiculo *vehiculos, int n)
{
	int sel, i;

	printf("Seleccione un EcoVehiculo\n");
	printf("Patinetes electricas\n");
	printf("1. Patinete Electrice 15 Xiaomi \n");
	printf("2. Patinete Electrico Ninebot Segway Max 630\n");
	printf("3. Patinete Electrico CECOTEC Outsider Demigod Makalu \n");
	printf("4. Patinete Electrico Ninebot KickScooter E45E\n");
	printf("5. Patinete Electrico EGRET-TEN V3 x 48V\n");
	printf("\n");
	printf("Bicicletas electricas\n");
	printf("6. Bicicleta Electrica de carretera Orbea Gain 030 1X\n");
	printf("7. Mountain Bike Electrica Orbea Wild F5 H30 \n");
	printf("8. Specialized bicicleta completa Turbo Vado 51 5.0 \n");
	printf("9. Bicicleta emtb lapierre overvolt am 5.5 \n");
	printf("10. Bicicleta Cannondale Moterra \n\n");

	printf(" Nuevos modelos...\n\n");
	for (i = 11; i <= n; i++)
	{
		printf("%d. ", i);
		visualizarEcoVehiculos(vehiculos[i - 1]);
	}
	fflush(stdin);
	printf("Introduce un numero entre el 1-%d\n", n);
	scanf("%i", &sel);
	printf("\n\n");

	if (sel >= 1 && sel <= n)
		printf("Has seleccionado %s %s %s %d\n", vehiculos[sel - 1].nombre, vehiculos[sel - 1].marca, vehiculos[sel - 1].modelo, vehiculos[sel - 1].autonomia);
	else
	{
		printf("Seleccione un numero correcto\n");
	}

	return sel;
}
void modificarDisponibilidad(EcoVehiculo *e)
{
	int d;
	//mostramos los EcoVehiculos que disponemos
	do
	{
		visualizarEcoVehiculos(*e);
		printf("===================================\n");
		printf("Selecciona la disponibilidad\n");
		printf("===================================\n");

		fflush(stdin);
		scanf("%i", &d);

		//condicion de que no permita disponibilidad negativo
		if (d >= 0)
		{
			e->disponibles = d;
		}
		else
		{
			printf("Introduce un valor mayor que 0\n");
		}
	} while (d < 0);
	//return;
}
