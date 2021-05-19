#ifdef __cplusplus

extern "C"
{
#include "sqlite3.h"
}
#endif
class BD
{

    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *nombreBD;

public:
    BD(char *nbd);
    //Métodos que tiene que haber en la base de datos
    void crearBD();
    // void insertarPersona(char *dni, int edad);
    int abrirBD();
    //int existePersona(char *dni);              //Opción de comprobar si existe persona o producto
    //void borrarPersona(char *dni);              //Opción de borrar usuario o producto
    //void mostrarTodasLasPersonas();              //Opción de mostrar  todos los usuarios
    //void modificarEdad(char *d, int nuevaEdad);         //Opción de hacerla con modificarPrecio
    virtual BD();
}

#endif
