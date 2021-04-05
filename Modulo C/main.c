#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "EcoVehiculo.h"


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
