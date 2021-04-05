#ifndef CLIENTE_H_
#define CLIENTE_H_


typedef struct {
        char* dni;
        char* nombre;
        char* apellido;
        int* cp;
        char* contra;
        int fNac ;

} Cliente;

void imprimirCliente(Cliente c);

#endif
