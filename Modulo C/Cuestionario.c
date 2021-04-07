#include <stdio.h>
#include "Cuestionario.h"
#include <stdlib.h>

void almacenarDatosCuestionario(Cuestionario *cuest, int ncuest){
	  FILE *fichero;


	if((fichero = fopen("DatosCuestionario.dat", "wb"))== NULL){
		printf("Error al abrir el fichero\n");

		exit(1);
}

	for(int i = 0;i<ncuest;i++){
		fwrite(&cuest[i], sizeof(Cuestionario),1,fichero);
	}
	fclose(fichero);
 }
void visualizarCuestionario(Cuestionario c){

		printf("Las respuestas a estas preguntas seran exclusivamente para la empresa EcoRide\n");
		printf("Has tenido alguna dificultad a la hora de realizar la compra En caso de que si, cual*\n");
		fflush(stdin);
		scanf("%s", &c.res1);
		printf("Has sentido seguridad y confianza a la hora de comprar el producto*\n");
		fflush(stdin);
		scanf("%s", &c.res2);
		printf("Anadirias alguna sugerencia o propuesta de mejora, de cara al futuro*\n");
		fflush(stdin);
		scanf("%s", &c.res3);
		printf("Muchas gracias por su atencion, hasta la proxima\n\n");

		almacenarDatosCuestionario(c, ncuest)
}

