
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <time.h>

#include "ecoVehiculo.h"
#include "bd.h"
#include "personalizacion.h"
#define FicheroFacturacion "EcoVehiculo_compras.txt"
#define FicheroVentas "Ventas.dat"

using namespace std;

typedef struct
{

    char marca[20];
    char modelo[20];
    int autonomia;
    float precio;
    int disponibles;
    char nombre[20];
    char color[20];
    char material[20];
    char fechaDeCompra[20];
    char freno[20];
    char cuentaKm[20];
    char precioPer[20];

} EcoVehiculoP;

void verFacturas();
void personalizarVentas(Personalizacion *, Personalizacion *, Personalizacion *);
void listarVentas();
void estadisticas();

int main(int argc, char **argv)
{


    char marca[20];
    char modelo[20];
    char nombre[20];
    char color[20];
    char material[30];
    char freno[20];
    char cuentaKm[20];
    float precio;
    char fechaDeCompra[20];
    char precioPer[20];
    int autonomia;
    int disponibles;

    strcpy(marca, "");
    strcpy(modelo, "");
    strcpy(fechaDeCompra, "");

    strcpy(nombre, " Ecopack Nature");
    strcpy(color, " Gris");
    strcpy(material, " Aluminio reciclado");
    strcpy(freno, " Mecanico");
    strcpy(cuentaKm, " Garmin 530");
    //strcpy(precioPer, "199");
    precio = 199;
    autonomia = 300;
    disponibles = 3;

    Personalizacion *p1 = new Personalizacion(marca, modelo, nombre, color, material, fechaDeCompra, freno, cuentaKm, autonomia, precio, disponibles);
    strcpy(nombre, " Ecopack Water");
    strcpy(color, " Azul");
    strcpy(material, " Fibra de vidrio Reciclada");
    strcpy(freno, " Mecanico");
    strcpy(cuentaKm, " Garmin 630");
    strcpy(precioPer, " 299");

    Personalizacion *p2 = new Personalizacion(marca, modelo, nombre, color, material, fechaDeCompra, freno, cuentaKm, autonomia, precio, disponibles);

    strcpy(nombre, " Ecopack Fire");
    strcpy(color, " Rojo");
    strcpy(material, " Fibra de carbono Reciclada");
    strcpy(freno, " Hidraulico");
    strcpy(cuentaKm, " Garmin 830");
    strcpy(precioPer, " 399");

    Personalizacion *p3 = new Personalizacion(marca, modelo, nombre, color, material, fechaDeCompra, freno, cuentaKm, autonomia, precio, disponibles);

    BD bd("BaseDeDatos.db");
    bd.crearBD();
    bd.abrirBD();

    /*Si es la primera vez que lo usas y no tienes en la BD ningun
    valor de persona descomenta antes de ejecutarlo las lineas de abajo
    para que se inserten las personas con su usuario y contraseña
    solo 1 vez, sino saldra que el nick esta duplicado*/

    //bd.insertarPersona("mikel", "mikel");
    //bd.insertarPersona("jose", "jose");
    //bd.insertarPersona("xabier", "xabier");
    bd.insertarPersona("a", "a");
    int s = 0;
    char usu[10], con[10];
    int intentos = 0, resul;
    do
    {
        cout << "Introduce nombre de usuario: ";
        cin >> usu;
        cout << "Introduce el password: ";
        cin >> con;
        intentos++;
        resul = bd.comprobarLogin(usu, con);
        if (resul == 0)
            cout << "El nick no es correcto" << endl;
        else if (resul == 1)
            cout << "Password incorrecto" << endl;
        else
            cout << "Usuario log" << endl;
    } while (resul != 2 && intentos < 3);
    if(resul==2){
        do
        {
                cout << endl
                     << endl;
                cout << "==============================================" << endl;
                cout << "EcoRide tu tienda de Vehiculos EcoFriendly" << endl;
                cout<<" "<<endl;
                cout << "Seleccione una opcion:" << endl;
                cout << "1. Visualizar facturas pendientes " << endl;
                cout << "2. Personalizar EcoVentas" << endl;
                cout << "3. Visualizar ventas" << endl;
                cout << "4. Mostrar todos los Admin en la BD" << endl;
                cout << "5. Cambiar password" << endl;
                cout << "6. Borrar persona de la BD" << endl;
                cout << " " << endl;
                cout << "         0. Exit" << endl;

                fflush(stdin);
                scanf("%i", &s);
                printf("\n\n");

                switch (s)
                {
                case 1:
                	cout<<"                              [Factura]"<<endl;
                    verFacturas();
                    break;
                case 2:
                    personalizarVentas(p1, p2, p3);
                    break;
                case 3:
                	bd.visualizarVentas();
                    break;
                case 4:
                	bd.mostrarAdminsBD();
                	break;
                case 5:
                	cout<<"Introduce el nombre de la persona que quieres cambiar su password: ";
                	cin>>usu;
                	if(bd.existePersona(usu)!= 0){
                	cout<<"Introduce el nueva password: ";
                	cin>>con;
                	bd.modificarContra(usu,con);
                	cout<<endl;
                	cout<<"Password cambiada correctamente"<<endl;
                	}else{
                	cout<<endl;
                	cout<<"Este usuario no esta en la Base de datos"<<endl;
                	}
                	break;
                case 6:
                	cout<<"Introduce el nombre de la persona que quieres borrar: ";
                	cin>>usu;
                	if(bd.existePersona(usu)!= 0){
                	bd.borrarPersona(usu);
                	cout<<endl;
                	cout<<"Usuario eliminado correctamente"<<endl;
                	}else{
                	cout<<"Este usuario no esta en la Base de datos"<<endl<<endl;
                	}

                	break;
                case 0:
                    cout << "Gracias por confiar en ecoRide, nos vemos pronto!!\n";
                    break;
                default:
                    cout << "Error introduce un numero valido\n";
                }
            } while (s != 0);

    }
    return 0;
}

void verFacturas()
{
    ifstream reader;
    string linea;

    reader.open(FicheroFacturacion, ios::in);

    if (!reader)
    {
        cout << "Error al abrir el fichero" << endl;
        return;
    }

    int cont = 0;
    int num = 0;
    int total = 0;
    while (!reader.eof())
    {
        getline(reader, linea);
        if (!reader.eof())
        {
            if (num == 0)
            {
                total++;
                cout << endl;
                cout << linea << "  Numero: " << total << endl;
            }
            else
            {
                cout << linea << endl;
            }

            cont++;
            num++;
            if (num == 4)
            {
                num = 0;
            }
        }
    }

    reader.close();

    cont = cont / 4;
    cout << endl
         << "Hay " << cont << " facturas pendientes" << endl;
}

//metodo para personalizar ventas
void personalizarVentas(Personalizacion *p1, Personalizacion *p2, Personalizacion *p3)
{
    ifstream reader;
    string linea;

    reader.open(FicheroFacturacion, ios::in);
    if (!reader)
    {
        cout << "Error al abrir el fichero" << endl;

        return;
    }
    // Contamos el numero de lineas para saber cuantos Ecovehiculos hay (cada Ecovehiculo tiene 4 lineas en el fichero)
    int cont = 0;
    while (!reader.eof())
    {
        getline(reader, linea);
        cont++;
    }
    reader.close();
    cont = cont / 4;

    //Array de ecovehiculos
    EcoVehiculo EcoVehiculos[cont];
    //Array de fechas
    string fechas[cont];

    char *marca;
    char *modelo;
    string fecha;
    char *preciox;
    float precio;

    reader.open(FicheroFacturacion, ios::in);

    if (!reader)
    {
        cout << "Error al abrir el fichero" << endl;
        return;
    }
    // Leemos el fichero de compras de vehiculos y se extraen los datos del EcoVehiculo
    // Separamos con , luego los introducimos en el array

    printf("%7s%35s%35s%15s\n","NUM","MARCA","MODELO","PRECIO");
    cont = 0;
    while (!reader.eof())
    {
        getline(reader, linea);
        if (linea.substr(0, 8) == "[Marca: ")
        {
            int pos = 0;
            int ind;
            for (int i = 8; i < linea.length(); i++)
            {
                if (linea.substr(i, 1) != ",")
                {
                    pos++;
                }
                else
                {
                    ind = i;
                    break;
                }
            }

            marca = strdup(linea.substr(8, pos).c_str());
           // cout << "Marca: " << marca << endl; getchar();
            ind += 10;
            pos = 0;
            int ind1;
            for (int i = ind; i < linea.length(); i++)
            {
                if (linea.substr(i, 1) != ",")
                {
                    pos++;
                }
                else
                {
                    ind1 = i;
                    break;
                }
            }
            modelo = strdup(linea.substr(ind, pos).c_str());
            //cout << "Modelo: " << modelo << endl;getchar();
            ind1 += 16;
            pos = 0;
            for (int i = ind1; i < linea.length(); i++)
            {
                if (linea.substr(i, 1) != "]")
                {
                    pos++;
                }
                else
                {
                    break;
                }
            }
            preciox = strdup(linea.substr(ind1, pos).c_str());
            precio = atof(preciox);
        }

        if (linea.substr(0, 18) == "[Fecha de compra: ")
        {
            int pos = 0;
            int ind;
            for (int i = 18; i < linea.length(); i++)
            {
                if (linea.substr(i, 1) != "]")
                {
                    pos++;
                }
                else
                {
                    ind = i;
                    break;
                }
            }
            fecha = linea.substr(18, pos);
            //cout<<fecha<<endl;getchar();
            printf("%5d.-%35s%35s%15s\n",cont+1,marca,modelo,preciox);
             EcoVehiculo ecovh(marca, modelo, 100, precio, 10);
             EcoVehiculos[cont] = ecovh;
             fechas[cont] = fecha;
             cont++;
        }

    }
    reader.close();
    int selec;
    do
    {
        cout << "Escoja un ecoVehiculo para personalizar ( 1 - " << cont << "): ";
        cin >> selec;

    } while (selec < 1 || selec > cont);

    // Menu para los paquetes de personalizacion
    cout << endl;
    p1->imprimirPersonal();
    p2->imprimirPersonal();
    p3->imprimirPersonal();

    Personalizacion *pe;

    int selecp;
    do
    {
        cout << "Escoja un modelo para personalizar ( 1 - 3 ) : ";
        cin >> selecp;
        cout<<"Seleccion agregada correctamente"<<endl;

        switch (selecp)
        {
        case 1:
            pe = p1;
            break;
        case 2:
            pe = p2;
            break;
        case 3:
            pe = p3;
            break;
        }

    } while (selecp < 1 || selecp > 3);

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char fechax[128];
    strftime(fechax, 128, "%d/%m/%Y %H:%M:%S", tlocal);
    pe->setFechaCompra(fechax);

    // Creamos la personalizacion y la agregamos al fichero de compras
    EcoVehiculoP ecoVP;

    strcpy(ecoVP.marca, EcoVehiculos[selec - 1].getMarca());
    strcpy(ecoVP.modelo, EcoVehiculos[selec - 1].getModelo());
    ecoVP.precio = EcoVehiculos[selec - 1].getPrecio();
    strcpy(ecoVP.nombre, pe->getNombre());
    strcpy(ecoVP.color, pe->getColor());
    strcpy(ecoVP.material, pe->getMaterial());
    strcpy(ecoVP.fechaDeCompra, pe->getFechaDeCompra());
    strcpy(ecoVP.freno, pe->getFreno());
    strcpy(ecoVP.cuentaKm, pe->getCuentaKm());

    ofstream out(FicheroVentas, ios::app | ios::binary);

    if (out.is_open())
    {
        out.write((char *)&ecoVP, sizeof(ecoVP));
    }
    out.close();

    // Borrado la factura del fichero de facturas
    ofstream ofs(FicheroFacturacion, ios::trunc);

    if (!ofs)
    {
        cout << "Error al borrar la factura" << endl;
        return;
    }

    for (int i = 0; i < cont; i++)
    {
        if (i != (selec - 1))
        {
            ofs << "Factura" << endl;
            ofs << "===============================================================================" << endl;
            ofs << "[Marca: " << EcoVehiculos[i].getMarca() << ", Modelo: " << EcoVehiculos[i].getModelo() << ", Precio Base: " << EcoVehiculos[i].getPrecio() << "]" << endl;
            ofs << "[Fecha de compra: " << fechas[i] << "]" << endl;
        }
    }

    ofs.close();
}

