#ifdef __cplusplus
extern "C"
{
#include "sqlite3.h"
}
#endif

#include "bd.h"
#include <iostream>
#include <string.h>
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
        cout << "ERROR!!" << endl;
    }
    else
    {
        /*char *sentencia = "CREATE TABLE PERSONA ("
							"DNI CHAR(10),"
							"EDAD INTEGER,"
							");";*/
        char *sentencia = "CREATE TABLE PERSONA(NICK CHAR(10), CON CHAR(10));";
        sqlite3_exec(db, sentencia, NULL, 0, 0);
    }
}

int BD::abrirBD()
{
    int result = sqlite3_open(nombreBD, &db);
    if (result != SQLITE_OK)
    {
        cout << "ERROR!! No se ha podido abrir la Base de Datos";
    }

    return result;
}

int BD::existePersona(const char *n)
{

    char query[100];
    int num;

    sprintf(query, "SELECT COUNT(*) FROM Persona WHERE nick='%s'", n);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
    num = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);

    return num;
}
void BD::insertarPersona(const char *u, const char *c)
{
    char query[100];
    int num;

    num = existePersona(u);
    if (num == 0)
    {
        sprintf(query, "INSERT INTO Persona VALUES ('%s','%s')", u, c);
        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }
    else
        cout << "ERROR! Nick repetido" << endl;
}
int BD::comprobarLogin(const char *n, const char *c)
{
    /*Devuelve 0 si el nick es incorrecto
    Devuelve 1 si el nick es correcto pero la contraseña no
    Devuelve 2 si nick y contraseña son correctos*/

    int resul = 2, r;
    char query[100];
    sprintf(query, "SELECT * FROM Persona WHERE nick='%s'", n);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    r = sqlite3_step(stmt);
    if (r == SQLITE_ROW)
    {
        char *con = (char *)sqlite3_column_text(stmt, 1);
        if (strcmp(con, c) != 0)
        {
            resul = 1;
        }
    }
    else
    {
        resul = 0;
    }
    sqlite3_finalize(stmt);
    return resul;
}
/*int BD::existePersona(char* d){

    char query[100];
    int num;

    sprintf(query,"SELECT COUNT(*) FROM Persona WHERE dni='%s'",d);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
    num = sqlite3_column_int(stmt,0);
    sqlite3_finalize(stmt);

    return num;
}*/

/*void BD::insertarPersona(char *dni, int edad){
    char query[100];
    int num;

    num = existePersona(dni);
    if(num==0)
    {
        sprintf(query,"INSERT INTO Persona(dni,edad) VALUES ('%s',%d)", dni, edad);
        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }
}*/

void BD::borrarPersona(char *d)
{
    char query[100];

    sprintf(query, "DELETE FROM Persona WHERE dni='%s'", d);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void BD::mostrarTodosLasPersonas()
{
    char query[100];
    int resul;

    sprintf(query, "SELECT * FROM Persona");
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);

    do
    {
        resul = sqlite3_step(stmt);
        if (resul == SQLITE_ROW)
        {
            char *dni = (char *)sqlite3_column_text(stmt, 0);
            int edad = sqlite3_column_int(stmt, 1);
            cout << dni << " " << edad << endl;
        }

    } while (resul == SQLITE_ROW);
    sqlite3_finalize(stmt);
}

void BD::modificarEdadPersona(char *d)
{

    char query[100];

    sprintf(query, "UPDATE Persona set edad=edad+1 WHERE dni='%s'", d);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
BD::~BD()
{
    delete[] nombreBD;
}