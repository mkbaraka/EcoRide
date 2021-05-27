#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <time.h>

#include "ecoVehiculo.h"
#include "personalizacion.h"
#include "bd.h"

//introducir los ficheros (CAMBIAR NOMBRES)
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

    strcpy(nombre, "Ecopack Nature");
    strcpy(color, "gris");
    strcpy(material, "Aluminio reciclado");
    strcpy(freno, "Mecanico");
    strcpy(cuentaKm, "Garmin 530");
    //strcpy(precioPer, "199");
    precio = 199;
    autonomia = 300;
    disponibles = 3;

    Personalizacion *p1 = new Personalizacion(marca, modelo, nombre, color, material, fechaDeCompra, freno, cuentaKm, autonomia, precio, disponibles);

    strcpy(nombre, "Ecopack Water");
    strcpy(color, "Azul");
    strcpy(material, "Fibra de vidrio Reciclada");
    strcpy(freno, "Mecanico");
    strcpy(cuentaKm, "Garmin 630");
    strcpy(precioPer, "299");

    Personalizacion *p2 = new Personalizacion(marca, modelo, nombre, color, material, fechaDeCompra, freno, cuentaKm, autonomia, precio, disponibles);

    strcpy(nombre, "Ecopack Fire");
    strcpy(color, "Rojo");
    strcpy(material, "Fibra de carbono Reciclada");
    strcpy(freno, "Hidraulico");
    strcpy(cuentaKm, "Garmin 830");
    strcpy(precioPer, "399");

    Personalizacion *p3 = new Personalizacion(marca, modelo, nombre, color, material, fechaDeCompra, freno, cuentaKm, autonomia, precio, disponibles);

    BD bd("BaseDeDatos.db");
    bd.crearBD();
    bd.abrirBD();
    /*bd.insertarPersona("111A",19);
    bd.insertarPersona("222B",21);
    bd.abrirBD();
    bd.mostrarTodosLasPersonas();
    bd.borrarPersona("111A");
    bd.mostrarTodosLasPersonas();*/
    bd.insertarPersona("mikel", "mikel");
    bd.insertarPersona("jose", "jose");
    bd.insertarPersona("xabier", "xabier");

    int s = 0;
    char usu[10], con[10];
    int intentos = 0, resul;
    do
    {
        cout << "Introduce nombre de usuario: ";
        cin >> usu;
        cout << "Introduce la contraseña: ";
        cin >> con;
        intentos++;
        resul = bd.comprobarLogin(usu, con);
        if (resul == 0)
            cout << "El nick no es correcto" << endl;
        else if (resul == 1)
            cout << "Contreña incorrecta" << endl;
        else
            cout << "Usuario log" << endl;
        do
        {
            cout << endl
                 << endl;
            cout << "==============================================" << endl;
            cout << "EcoRide tu tienda de Vehiculos EcoFriendly" << endl;
            cout << "Seleccione una opcion:" << endl;
            cout << "1. Visualizar facturas pendientes " << endl;
            cout << "2. Personalizar EcoVentas" << endl;
            cout << "3. Visualizara ventas" << endl;
            cout << "4. Estadisticas" << endl;
            cout << "0. Exit" << endl;

            fflush(stdin);
            scanf("%i", &s);
            printf("\n\n");

            switch (s)
            {
            case 1:
                verFacturas();
                break;
            case 2:
                personalizarVentas(p1, p2, p3);
                break;
            case 3:
                listarVentas();
                break;
            case 4:
                estadisticas();
                break;
            case 0:
                cout << "Gracias por confiar en ecoRide, nos vemos pronto!!\n";
                break;
            default:
                cout << "Error introduce un numero valido\n";
            }
        } while (s != 0);

        return 0;
    }
}
while (resul != 2 && intentos < 3)
    ;

return 0;

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

//hacer metodo para personalizar ventas
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

    // array de ecovehiculos
    EcoVehiculo EcoVehiculos[cont];
    // Array con las fechas
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
    // Se lee el fichero de compras de vehiculos y se extraen los datos del vehiculo
    // , luego los cargamos en el array
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
            //cout << "Marca: " << marca << endl;
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
            //cout << "Modelo: " << modelo << endl;
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

            // EcoVehiculo ecovh(marca, modelo, autonomia, precio, disponibles);
            // EcoVehiculos[cont] = ecovh;
            // fechas[cont] = fecha;
            // cont++;
        }
    }
    reader.close();
    int selec;
    do
    {
        cout << "Escoja un ecoVehiculo para personalizar ( 1 - " << cont << "): ";
        cin >> selec;
    } while (selec < 1 || selec > cont);

    // Menu para seleccionar uno de los tres paquetes personalizados por pantalla, que estan creados y que se agreguen a la fichero de ventas de la parte de c++
    cout << endl;
    p1->imprimirPersonal();
    p2->imprimirPersonal();
    p3->imprimirPersonal();

    Personalizacion *pe;

    int selecp;
    do
    {
        cout << "Escoja una modelo para personalizar ( 1 - 3 ) : ";
        cin >> selecp;

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

    // Creamos la personalizacion y la anadimos al fichero de Ventas
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

    // Borramos la factura del fichero de facturas
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
            ofs << "      Factura" << endl;
            ofs << "===================" << endl;
            ofs << "[Marca: " << EcoVehiculos[i].getMarca() << ", Modelo: " << EcoVehiculos[i].getModelo() << ", Precio: " << EcoVehiculos[i].getPrecio() << "]" << endl;
            ofs << "[ Fecha de compra: " << fechas[i] << "]" << endl;
        }
    }

    ofs.close();
}

void listarVentas()
{
    EcoVehiculoP ecoVP;

    cout << "Vehiculos vendidos:" << endl;
    cout << "====================" << endl;

    ifstream in(FicheroVentas, ios::in);

    if (in.is_open())
    {
        while (!in.eof())
        {
            in.read((char *)&ecoVP, sizeof(ecoVP));
            if (!in.eof())
            {
                Personalizacion *p = new Personalizacion(ecoVP.marca, ecoVP.modelo, ecoVP.nombre, ecoVP.color, ecoVP.material, ecoVP.fechaDeCompra, ecoVP.freno, ecoVP.cuentaKm, ecoVP.autonomia, ecoVP.precio, ecoVP.disponibles);
                p->imprimir();
            }
        }
    }
    in.close();
}

// Metodo que imprime el importe total de las ventas (EcoVehiculos + personalizacion)
// Metodo que saca el EcoVehiculo mas vendido
void estadisticas()
{
    EcoVehiculoP ecoVP;
    int cont = 0;
    ifstream in(FicheroVentas, ios::in);

    double importeTotal = 0;

    if (in.is_open())
    {
        while (!in.eof())
        {
            in.read((char *)&ecoVP, sizeof(ecoVP));
            if (!in.eof())
            {
                cont++;
                importeTotal += ecoVP.precio + atof(ecoVP.precioPer);
            }
        }
    }
    in.close();

    printf("Importe total de ventas: %.2f\n\n", importeTotal);

    // Arrays de trabajo para buscar el vehiculo mas vendido
    Personalizacion *persons[cont];
    int cuenta[cont];
    cont = 0;

    ifstream in1(FicheroVentas, ios::in);
    if (in1.is_open())
    {
        while (!in1.eof())
        {
            Personalizacion obj;
            in1.read((char *)&ecoVP, sizeof(ecoVP));
            if (!in1.eof())
            {
                persons[cont] = new Personalizacion(ecoVP.marca, ecoVP.modelo, ecoVP.nombre, ecoVP.color, ecoVP.material, ecoVP.fechaDeCompra, ecoVP.freno, ecoVP.cuentaKm, ecoVP.autonomia, ecoVP.precio, ecoVP.disponibles);

                cuenta[cont] = 1;
                cont++;
            }
        }
    }
    in1.close();

    // Se cuentan los EcoVehiculos de la misma marca
    for (int i = 0; i < cont; i++)
    {
        for (int j = 0; j < cont; j++)
        {
            if (i != j)
            {
                if (strcmp(persons[i]->getMarca(), persons[j]->getMarca()) == 0)
                {
                    cuenta[i] = cuenta[i] + 1;
                }
            }
        }
    }

    // Se anulan los EcoVehiculos iguales (poniendolos a cero), dejando solo uno
    for (int i = 0; i < cont - 1; i++)
    {
        if (cuenta[i] > 0)
        {
            for (int j = i + 1; j < cont; j++)
            {
                if (i != j)
                {
                    if (strcmp(persons[i]->getMarca(), persons[j]->getMarca()) == 0)
                    {
                        cuenta[i] = 0;
                    }
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < cont; i++)
    {
        if (cuenta[i] > max)
        {
            max = cuenta[i];
        }
    }

    cout << "El EcoVehiculo mas vendido es:" << endl;
    for (int i = 0; i < cont; i++)
    {
        if (cuenta[i] == max)
        {
            persons[i]->imprimirEcoVehiculo();
            if (max == 1)
            {
                cout << "Vendido " << max << " vez " << endl
                     << endl;
            }
            else
            {
                cout << "Vendido " << max << " veces " << endl
                     << endl;
            }
        }
    }
}
