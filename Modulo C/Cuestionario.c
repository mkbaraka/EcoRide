#include <stdio.h>
#include "Cuestionario.h"
#include <stdlib.h>

void almacenarDatosCuestionario(Cuestionario c)
{
	FILE *fichero;
	fichero = fopen("Cuestionario.txt", "w");
	if (fichero == NULL)
	{
		return;
	}
	fprintf(fichero, "%s\n", c.res1);
	fprintf(fichero, "%s\n", c.res2);
	fprintf(fichero, "%s\n", c.res3);
	fclose(fichero);
}
void visualizarCuestionario(Cuestionario *c)
{

	printf("Las respuestas a estas preguntas seran exclusivamente para la empresa EcoRide\n");
	printf("Has tenido alguna dificultad a la hora de realizar la compra En caso de que si, cual*\n");
	fflush(stdin);
	scanf("%s", c->res1);
	printf("Has sentido seguridad y confianza a la hora de comprar el producto*\n");
	fflush(stdin);
	scanf("%s", c->res2);
	printf("Anadirias alguna sugerencia o propuesta de mejora, de cara al futuro*\n");
	fflush(stdin);
	scanf("%s", c->res3);
	printf("Muchas gracias por su atencion, hasta la proxima\n\n");

	almacenarDatosCuestionario(*c);
}
