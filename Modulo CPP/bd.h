#ifndef BD_H
#define BD_H

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
    void crearBD();
    //void insertarPersona(char *dni, int edad);
    void insertarPersona(const char *n, const char *c);
    int abrirBD();

    // int existePersona(char *d);
    int existePersona(const char *n);
    int comprobarLogin(const char *n, const char *c);
    void borrarPersona(char *d);
    void mostrarTodosLasPersonas();
    void modificarEdadPersona(char *d);
    virtual ~BD();
};

#endif // BD_H
