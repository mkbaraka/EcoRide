#ifdef __cplusplus
extern "C" {
#include "sqlite3.h"
}
#endif

#include "BD.h"
#include <iostream>
#include <string.h>
using namespace std;



BD::BD(char *nbd) {
    nombreBD = new char[strlen(nbd)+1];
    strcpy(nombreBD,nbd);
}
//METODO PARA CREAR LA BASE DE DATOS
void BD::crearBD()
{

	if (sqlite3_open(nombreBD, &db)) {
		cout << "ERROR!!" << endl;
	} else {
		/*char *sentencia = "CREATE TABLE PERSONA ("
							"DNI CHAR(10),"
							"EDAD INTEGER,"
							");";*/
        char *sentencia1 = "CREATE TABLE PERSONA(NICK CHAR(10), CON CHAR(10));";
		sqlite3_exec(db, sentencia1, NULL, 0, 0);

	}
}

//METODO PARA ABRIR LA BASE DE DATOS
int BD::abrirBD(){
	int result = sqlite3_open(nombreBD, &db);
	if(result != SQLITE_OK){
            cout<<"ERROR!! No se ha podido abrir la Base de Datos";
	}

	return result;
}
//METODO PARA COMPROBAR SI EXISTE EL USUARIO INTRODUCIDO
int BD::existePersona(const char* n){

    char query[100];
    int num;

    sprintf(query,"SELECT COUNT(*) FROM Persona WHERE nick='%s'",n);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
    num = sqlite3_column_int(stmt,0);
    sqlite3_finalize(stmt);

    return num;
}

//METODO PARA INSERTAR PERSONAS EN BASE DE DATOS(TABLA PERSONA)
void BD::insertarPersona(const char *u, const char *c){
    char query[100];
    int num;

    num = existePersona(u);
    if(num==0)
    {
        sprintf(query,"INSERT INTO Persona VALUES ('%s','%s')", u, c);
        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }
    else cout<<"ERROR! Nick repetido"<<endl;
}

//METODO PARA COMPROBAR EN LA BASE DE DATOS SI COINCIDEN LOS DATOS PARA ACCEDER
int BD::comprobarLogin(const char *n, const char *c){
    /*Devuelve 0 si el nick es incorrecto
    Devuelve 1 si el nick es correcto pero la contrase�a no
    Devuelve 2 si nick y contrase�a son correctos*/

    int resul = 2,r;
    char query[100];
    sprintf(query,"SELECT * FROM Persona WHERE nick='%s'",n);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    r=sqlite3_step(stmt);
    if (r == SQLITE_ROW){
        char* con = (char*) sqlite3_column_text(stmt, 1);
        if(strcmp(con,c)!=0){
            resul = 1;
        }
    }else{
        resul = 0;
    }
    sqlite3_finalize(stmt);
    return resul;
}

//TODO
//METODO QUE BORRA DE LA BD TODOS LOS DATOS DEL NOMBRE INTRODUCIDO
void BD::borrarPersona(char* n){
    char query[100];

    sprintf(query,"DELETE FROM Persona WHERE NICK='%s'",n);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

}

//MUESTRA TODOS LOS NOMBRES DE LAS PERSONAS EN LA BASE DE DATOS(ADMINS)
void BD::mostrarAdminsBD(){
    char query[100];
    int resul;


    sprintf(query,"SELECT NICK FROM Persona");
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);

            cout<<"ADMINISTRADORES"<<endl;
    do
    {
	resul = sqlite3_step(stmt);
	if (resul == SQLITE_ROW){

            char* nom = (char*) sqlite3_column_text(stmt, 0);
            cout<<nom<<" "<<endl;
	}

    }while(resul==SQLITE_ROW);
    sqlite3_finalize(stmt);

}
//TODO
//MODIFICAR CONTRASEÑA INTROUCIENDO EL NOMBRE DE LA PERSONA
void BD::modificarContra(char* n, char *c){

    char query[100];

    sprintf(query,"UPDATE Persona set CON = '%s' WHERE NICK='%s'", c, n);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

}


void BD::visualizarVentas(){
 	char query[100];
    int resul;

    sprintf(query,"SELECT * FROM Compras");
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
    cout<<"                                              [Ventas]"<<endl<<endl;
    cout<<"___________________________________________________________________________________________________________"<<endl;

    do
    {
	resul = sqlite3_step(stmt);
	if (resul == SQLITE_ROW){

            char* MARCA = (char*) sqlite3_column_text(stmt, 0);
            char* MODELO = (char*) sqlite3_column_text(stmt, 1);
            int PRECIOBASE = sqlite3_column_int(stmt,2);
            char* FCOMPRA = (char*) sqlite3_column_text(stmt, 3);
            cout<<"[Marca] "<<MARCA<<" "<<"[Modelo] "<<MODELO<<" "<<"[Precio Base] "<<PRECIOBASE<<" "<<"[Fecha de compra] "<<FCOMPRA<<endl;
            cout<<endl;
	}

    }while(resul==SQLITE_ROW);
    sqlite3_finalize(stmt);

}


BD::~BD() {
    delete[] nombreBD;
}
