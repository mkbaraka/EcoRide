#include <stdio.h>
#include "Cliente.h"

void void imprimirCliente(Cliente c)
{
    printf("Dni: %s,Nombre: %s, Apellido: %s, cp: %i, Contrase�a: %s,"
    " Fecha de nacimiento: %i\n ", c.dni, c.nombre, c.apellido, c.cp, c.contra, c.fNac);
}