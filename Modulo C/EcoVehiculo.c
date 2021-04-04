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
	in


	printf("Seleccione un EcoVehiculo/n");
	printf("Patinetes electricas\n");
	printf("1. Patinete Electrice Xiaomi 15\n" );
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
	scanf("%i",&sel);
	printf("\n\n")
	int Eco = 0;

	for(i=0; i<strlen(sel); i++){

	if(sel[i]=="1"){
		eco = 1;
	}if(sel[i]=="2"){
		eco = 2;
	}if(sel[i]=="3"){
		eco = 3;
	}if(sel[i]=="4"){
		eco = 4;
	}if(sel[i]=="5"){
		eco = 5;
	}if(sel[i]=="6"){
		eco = 6;
	}if(sel[i]=="7"){
		eco = 7;
	}if(sel[i]=="8"){
		eco = 8;
	}if(sel[i]=="9"){
		eco = 9;
	}if(sel[i]=="10"){
		eco = 10;
	}else{
		printf("Seleccione un numero correcto\n");
	}
}
	return sel;
}

