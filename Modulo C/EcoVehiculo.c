#include <stdio.h>
#include "EcoVehiculo.h"
#include <stdlib.h>



void visualizarEcoVehiculos(EcoVehiculo e){

	printf("Nombre --> %s\n", e.nombre);
	printf("Marca --> %s\n", e.marca);
	printf("Modelo --> %s\n", e.modelo);
	printf("Precio --> %f\n", e.precio);
	printf("Disponibilidad --> %i\n", e.disponibles);
	printf("\n");

	return;
}

int seleccionarEcoVehiculo(){
	int sel;



	printf("Seleccione un EcoVehiculo\n");
		printf("Patinetes electricas\n");
		printf("1. Patinete Electrice 15 Xiaomi \n" );
		printf("2. Patinete Electrico Ninebot Segway Max 630\n" );
		printf("3. Patinete Electrico CECOTEC Outsider Demigod Makalu \n");
		printf("4. Patinete Electrico Ninebot KickScooter E45E\n");
		printf("5. Patinete Electrico EGRET-TEN V3 x 48V\n");
		printf("\n");
		printf("Bicicletas electricas\n" );
		printf("6. Bicicleta Electrica de carretera Orbea Gain 030 1X\n");
		printf("7. Mountain Bike Electrica Orbea Wild F5 H30 \n");
		printf("8. Specialized bicicleta completa Turbo Vado 51 5.0 \n");
		printf("9. Bicicleta emtb lapierre overvolt am 5.5 \n");
		printf("10. Bicicleta Cannondale Moterra \n");

		fflush(stdin);
		printf("Introduce un numero entre el 1-10\n");
		scanf("%i",&sel);
		printf("\n\n");




		 if (sel == 1){
			 printf("Has seleccionado Patinete Electrice Xiaomi 15\n" );
		 }else if(sel == 2){
			 printf("Has seleccionado Patinete Electrico Ninebot Segway Max 630\n" );

		 }else if(sel == 3){
			 printf("Has seleccionado Patinete Electrico CECOTEC Outsider Demigod Makalu \n");
		 }else if(sel == 4){
			 printf("Has seleccionado Patinete Electrico Ninebot KickScooter E45E\n");
		 }else if(sel == 5){
			 printf("Has seleccionado Patinete Electrico EGRET-TEN V3 x 48V\n");
		 }else if(sel == 6){
			  printf("Has seleccionado Bicicleta Electrica de carretera Orbea Gain 030 1X\n");
		 }else if(sel == 7){
			 printf("Has seleccionado Mountain Bike Electrica Orbea Wild F5 H30 \n");
		 }else if(sel == 8){
			 printf("Has seleccionado Specialized bicicleta completa Turbo Vado 51 5.0 \n");
		 }else if(sel == 9){
			 printf("Has seleccionado Bicicleta emtb lapierre overvolt am 5.5 \n");
		 }else if(sel == 10){
			 printf("Has seleccionado Bicicleta Cannondale Moterra \n");
		}else{
			printf("Seleccione un numero correcto\n");
		}

		return sel;
	}
void modificarDisponibilidad(EcoVehiculo *e){
	//mostramos los EcoVehiculos que disponemos
	visualizarEcoVehiculos(*e);
	printf("=======================");
	int d;
	printf("Selecciona la disponibilidad ");
	fflush(stdin);
	scanf("%i",&d);
	printf("=======================");


	//condicion de que no permita disponibilidad negativo
	if(d>=0){
		e->disponibles = d;

	}else{
		printf("Introduce un valor mayor que 0\n");
	}
	return;
}
