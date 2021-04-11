#ifndef CUESTIONARIO_H_
#define CUESTIONARIO_H_

typedef struct
{
    char res1[40];
    char res2[40];
    char res3[40];


} Cuestionario;

void visualizarCuestionario(Cuestionario *c);
void almacenarDatosCuestionario(Cuestionario c);

#endif
