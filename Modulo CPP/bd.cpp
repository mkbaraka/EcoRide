#ifdef __cplusplus
extern "C"
{
#include "sqlite3.h"
}
#endif
#include "bd.h"
#include <string.h>
#include <iostream>
using namespace std;
BD::BD(char *nbd)
{
    nombreBD = new char[strlen(nbd) + 1];
    strcpy(nombreBD, nbd);
}

void BD::crearBD()
{
    if (sqlite3_open(nombreBD, &db))
    {
        cout << "ERROR" << endl;
    }
    else
    {
        //Por cada tabla que quiera crear hago estas dos líneas de código
        char *sentencia = "CREATE TABLE PERSONA(DNI CHAR(10), EDAD INTEGER);";
        sqlite3_exec(db, sentencia, NULL, 0, 0) //Para ejecutar una sentencia, NULL y 0, 0 siempre
    }
}
int BD::abrirBD()
{
    int resultado = sqlite3_open(nombreBD, &db);
    if (resultado != SQLITE_OK)
        cout << "ERROR" << endl;

    return resultado;
}

void BD::insertaPersona(char *dni, int edad)
{
    char query[20];
    int resul;
    resul = existe_persona(dni);

    if (resul == 0)
    {
        sprintf(query, "INSERT INTO Persona VALUES('%s', %d)", dni, edad); //Las cadenas de caracteres van entre comillas simples
        sqlite3_prepare_V2(db, query, strlen(query) + 1, &stmt, NULL);     //Preparar la sentencia
        sqlite3_step(stmt);                                                //Ejecutar la sentencia
        sqlite3_finalize(stmt);                                            //Finalizar la sentencia asi porque no devuelve nada
    }
}

int BD::existePersona(char *dni)
{
    int resul;
    char query[200];
    sprintf(query, "SELECT COUNT(*) FROM PERSONA WHERE DNI = '%s'", dni);
    sqlite3_prepare_V2(db, query, strlen(query) + 1, &stmt, NULL); //Preparar la sentencia
    sqlite3_step(stmt);                                            //Ejecutar la sentencia
    resul = sqlite3_column_int(stmt, 0);                           //0 es el numero de la columna del dni.
    sqlite3_finalize(stmt);                                        //Finalizar la sentencia
    return resul;
}

void BD::borrarPersona(char *dni)
{
    char query[200];
    sqrintf(query, "DELETE FROM Persona WHERE DNI = '%s'", dni);
    sqlite3_prepare_V2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void BD::mostrarTodasLasPersonas()
{
    char query[200];
    int resul;
    sprintf(query, "SELECT * FROM Persona");
    sqlite3_prepare_V2(db, query, strlen(query) + 1, &stmt, NULL);

    do
    {
        resul = sqlite3_step(stmt);
        if (resul == SQLITE_ROW)
        {
            char *dni = sqlite3_column_text(stmt, 0); //0 es donde está el dni
            int edad = sqlite3_column_int(stmt, 1);
            cout << dni << "" << edad << endl;
        }
    } while (resul == SQLITE_ROW);
    sqlite3_finalize(stmt);
}

void BD::modificarEdad(char *dni, int nuevaEdad)
{
    BS::~BD()
    {
        delete[] nombreBD;
    }
