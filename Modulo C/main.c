#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <time.h>
#include "EcoVehiculo.h"


void leerFichero(EcoVehiculo *EcoV1, EcoVehiculo *EcoV2, EcoVehiculo *EcoV3,EcoVehiculo *EcoV4,
	EcoVehiculo *EcoV5,EcoVehiculo *EcoV6,EcoVehiculo *EcoV7,EcoVehiculo *EcoV8,EcoVehiculo *EcoV9,EcoVehiculo *EcoV10) {

	FILE *fichero;

	if ((fichero = fopen( "EcoVehiculos.dat", "rb" )) == NULL) {

	return;
	}
	fread(EcoV1, sizeof(EcoVehiculo), 1 , fichero);
	fread(EcoV2, sizeof(EcoVehiculo), 1 , fichero);
	fread(EcoV3, sizeof(EcoVehiculo), 1 , fichero);
	fread(EcoV4, sizeof(EcoVehiculo), 1 , fichero);
	fread(EcoV5, sizeof(EcoVehiculo), 1 , fichero);
	fread(EcoV6, sizeof(EcoVehiculo), 1 , fichero);
	fread(EcoV7, sizeof(EcoVehiculo), 1 , fichero);
	fread(EcoV8, sizeof(EcoVehiculo), 1 , fichero);
	fread(EcoV9, sizeof(EcoVehiculo), 1 , fichero);
	fread(EcoV10, sizeof(EcoVehiculo), 1 , fichero );


 fclose(fichero);
}

void almacenarEcoVehiculos(EcoVehiculo *ecove, int nEcove){
	  FILE *fichero;


	if((fichero = fopen("EcoVehiculo.dat", "wb"))== NULL){
		printf("Error al abrir el fichero\n");

		exit(1);
}

	for(int i = 0;i<nEcove;i++){
		fwrite(&ecove[i], sizeof(EcoVehiculo),1,fichero);
	}
	fclose(fichero);
 }


//metodo para c++
//void facturacion(){  }


//main

int main(){

	//Eco patines
	EcoVehiculo *EcoV1;
	EcoV1 =(Vehiculo *)malloc(sizeof(EcoVehiculo));
	strcpy(EcoV1->nombre, "Patinete" );
	strcpy(EcoV1->marca, "xiaomi" );
	strcpy(EcoV1->modelo, "Electrice 15" );
	EcoV1->autonomia = 20  ;
	EcoV1->precio = 499.99 );
	EcoV1->disponibles, 1);

	EcoVehiculo *EcoV1;
	EcoV1 =(Vehiculo *)malloc(sizeof(EcoVehiculo));
	strcpy(EcoV1->nombre, "Patinete" );
	strcpy(EcoV1->marca, "Ninebot" );
	strcpy(EcoV1->modelo, "Segway Max 630" );
	EcoV1->autonomia = 22  ;
	EcoV1->precio = 399.99 );
	EcoV1->disponibles, 0);

	EcoVehiculo *EcoV1;
	EcoV1 =(Vehiculo *)malloc(sizeof(EcoVehiculo));
	strcpy(EcoV1->nombre, "Patinete" );
	strcpy(EcoV1->marca, "CECOTEC" );
	strcpy(EcoV1->modelo, "Segway Max 630" );
	EcoV1->autonomia = 24  ;
	EcoV1->precio = 249.99 );
	EcoV1->disponibles, 2);

	EcoVehiculo *EcoV1;
	EcoV1 =(Vehiculo *)malloc(sizeof(EcoVehiculo));
	strcpy(EcoV1->nombre, "Patinete" );
	strcpy(EcoV1->marca, "Ninebot" );
	strcpy(EcoV1->modelo, "KickScooter E45E" );
	EcoV1->autonomia = 18  ;
	EcoV1->precio = 350.0 );
	EcoV1->disponibles, 3);


	EcoVehiculo *EcoV1;
	EcoV1 =(Vehiculo *)malloc(sizeof(EcoVehiculo));
	strcpy(EcoV1->nombre, "Patinete" );
	strcpy(EcoV1->marca, "EGRET-TEN" );
	strcpy(EcoV1->modelo, "V3 x 48V" );
	EcoV1->autonomia = 60  ;
	EcoV1->precio = 699.99 );
	EcoV1->disponibles, 2);

	//EcoBicicletas
	EcoVehiculo *EcoV1;
	EcoV1 =(Vehiculo *)malloc(sizeof(EcoVehiculo));
	strcpy(EcoV1->nombre, "Bicicleta" );
	strcpy(EcoV1->marca, "Orbea" );
	strcpy(EcoV1->modelo, "Gain 030 1X" );
	EcoV1->autonomia = 70  ;
	EcoV1->precio = 1499.99 );
	EcoV1->disponibles, 1);

	EcoVehiculo *EcoV1;
	EcoV1 =(Vehiculo *)malloc(sizeof(EcoVehiculo));
	strcpy(EcoV1->nombre, "Bicicleta" );
	strcpy(EcoV1->marca, "Orbea" );
	strcpy(EcoV1->modelo, "Wild F5 H30" );
	EcoV1->autonomia = 80  ;
	EcoV1->precio = 1299.99 );
	EcoV1->disponibles, 0);


	EcoVehiculo *EcoV1;
	EcoV1 =(Vehiculo *)malloc(sizeof(EcoVehiculo));
	strcpy(EcoV1->nombre, "Bicicleta" );
	strcpy(EcoV1->marca, "Specialized" );
	strcpy(EcoV1->modelo, "Turbo Vado 51 5.0" );
	EcoV1->autonomia = 90  ;
	EcoV1->precio = 1229.99 );
	EcoV1->disponibles, 2);


	EcoVehiculo *EcoV1;
	EcoV1 =(Vehiculo *)malloc(sizeof(EcoVehiculo));
	strcpy(EcoV1->nombre, "Bicicleta" );
	strcpy(EcoV1->marca, "lapierre" );
	strcpy(EcoV1->modelo, "overvolt am 5.5" );
	EcoV1->autonomia = 100  ;
	EcoV1->precio = 1799.99 );
	EcoV1->disponibles, 4);

	EcoVehiculo *EcoV1;
	EcoV1 =(Vehiculo *)malloc(sizeof(EcoVehiculo));
	strcpy(EcoV1->nombre, "Bicicleta" );
	strcpy(EcoV1->marca, "Cannondale" );
	strcpy(EcoV1->modelo, "Moterra" );
	EcoV1->autonomia = 120  ;
	EcoV1->precio = 1099.99 );
	EcoV1->disponibles, 1);


	leerFichero(EcoV1, EcoV2, EcoV3, EcoV4, EcoV5, EcoV6, EcoV7, EcoV8, EcoV9, EcoV10);

	int sel = 0;
	int e;

	do{
		printf("EcoRide tu tienda de Vehiculos EcoFriendly\n");
				printf(" \n ");
				printf(" Selecciona una opcion: \n");
				printf(" \n ");
				printf("Patinetes electricas\t\t\t\t\t\t"); printf("Bicicletas electricas\n" );
				printf("\n");
				printf("1. Patinete Electrice 15 Xiaomi \t\t\t\t" ); printf("6. Bicicleta Electrica de carretera Orbea Gain 030 1X\n");
				printf("2. Patinete Electrico Ninebot Segway Max 630\t\t\t" );printf("7. Mountain Bike Electrica Orbea Wild F5 H30 \n");
				printf("3. Patinete Electrico CECOTEC Outsider Demigod Makalu \t\t");printf("8. Specialized bicicleta completa Turbo Vado 51 5.0 \n");
				printf("4. Patinete Electrico Ninebot KickScooter E45E\t\t\t");printf("9. Bicicleta emtb lapierre overvolt am 5.5 \n");
				printf("5. Patinete Electrico EGRET-TEN V3 x 48V\t\t\t");	printf("10. Bicicleta Cannondale Moterra \n");
				printf("\n");

				printf(" Otras opciones\n");
				printf("\n");
				printf("11.Comprar EcoVehiculo\n");
				printf("12.Modificar disponibilidad\n");


				printf("\n");


				printf("                                                   0. Exit\n");



		fflush(stdin);
		scanf("%i",&sel);
		printf("\n");


	switch(sel){

	case 1: visualizarEcoVehiculos(*EcoV1);break;
	case 2: visualizarEcoVehiculos(*EcoV2);break;
	case 3: visualizarEcoVehiculos(*EcoV3);break;
	case 4: visualizarEcoVehiculos(*EcoV4);break;
	case 5: visualizarEcoVehiculos(*EcoV5);break;
	case 6: visualizarEcoVehiculos(*EcoV6);break;
	case 7: visualizarEcoVehiculos(*EcoV7);break;
	case 8: visualizarEcoVehiculos(*EcoV8);break;
	case 9: visualizarEcoVehiculos(*EcoV9);break;
	case 10: visualizarEcoVehiculos(*EcoV10);break;
	case 11: e = seleccionarEcoVehiculo();

	//Aqui utilizariamos un metodo que nos permita hacer una factura de la compra de un EcoVehiculo.


		printf("Compra realizada correctamente\n");



		//Cuestionario post-realizar compra

		printf("Las respuestas a estas preguntas seran exclusivamente para la empresa EcoRide");
		printf("Has tenido alguna dificultad a la hora de realizar la compra En caso de que si, cual");
		scanf("%s", &r);
		printf("Has sentido seguridad y confianza a la hora de comprar el producto")
		scanf("%s", &r);
		printf("Añadirias alguna sugerencia o propuesta de mejora, de cara al futuro")
		scanf("%s%", &r);
		printf("Muchas gracias por su atencion, ¡hasta la proxima!")













	break;
	case 12: e = seleccionarEcoVehiculo();
	if (e == 1){
		modificarDisponibilidad(EcoV1);
	}if (e == 2){
		modificarDisponibilidad(EcoV2);
	}if (e == 3){
		modificarDisponibilidad(EcoV3);
	}if (e == 4){
		modificarDisponibilidad(EcoV4);
	}if (e == 5){
		modificarDisponibilidad(EcoV5);
	}if (e == 6){
		modificarDisponibilidad(EcoV6);
	}if (e == 7){
		modificarDisponibilidad(EcoV7);
	}if (e == 8){
		modificarDisponibilidad(EcoV8);
	}if (e == 9){
		modificarDisponibilidad(EcoV9);
	}if (e == 10){
		modificarDisponibilidad(EcoV10);
	}break;





	}

	} while(sel!=0);

	EcoVehiculo ecove[9];
	ecove[0] = *EcoV1;
	ecove[1] = *EcoV2;
	ecove[2] = *EcoV3;
	ecove[3] = *EcoV4;
	ecove[4] = *EcoV5;
	ecove[5] = *EcoV6;
	ecove[6] = *EcoV7;
	ecove[7] = *EcoV8;
	ecove[8] = *EcoV9;
	ecove[9] = *EcoV10;


	almacenarEcoVEhiculo(ecove, 10);

	free(EcoV1);
	free(EcoV2);
	free(EcoV3);
	free(EcoV4);
	free(EcoV5);
	free(EcoV6);
	free(EcoV7);
	free(EcoV8);
	free(EcoV9);
	free(EcoV10);
	return 0;

 }
















































