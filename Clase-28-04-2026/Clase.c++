#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    string nombre;
    string linea;

    cout << "Dime el nombre del fichero: ";
    getline(cin, nombre);

    ifstream fichero(nombre.c_str());

      while (fichero.fail())
    {
        cout << "No existe el fichero!" << endl; // mensaje al usuario
        system("clear");
        cout << "Ingrese otro nombre de fichero: ";
        cin >> nombre;
        fichero.open(nombre.c_str());
    };

    while (!fichero.eof())
    {
        getline(fichero, linea);
        if (!fichero.eof()) //  tenemos una forma de saber si ya hemos llegado al final del fichero. Es “.eof()”, que será verdadero si el fichero ha terminado (EOF es la abreviatura de End Of File, fin de fichero).
            cout << linea << endl;
    }
    
    fichero.close();
    /// Esa será la estructura básica de casi cualquier programa que deba leer un fichero completo, de principio a fin: abrir, comprobar que se ha podido acceder correctamente, leer con “while ( !fichero.eof())” y cerrar.

    return 0;
}