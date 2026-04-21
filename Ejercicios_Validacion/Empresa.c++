// - necesitamos que valides en el programa si el programa dicen que esta en caracas mostrar los municipios , mostrar las parroquias,
// validar la cantidad de accionisas , el nombre comercial , la razon social , cuantas sucursales tienen ,
// validar si los nobres tienen simbolos , donde estan ubicada sesas sucursale sis estan en caracas ,
// y guarda toda esa informacion eun txt

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string nombreComercial, razonSocial, ubicacionSucursal;
    int cantidadAccionistas, cantidadSucursales;

    cout << "Ingrese el nombre comercial de la empresa: ";
    getline(cin, nombreComercial);

    cout << "Ingrese la razón social de la empresa: ";
    getline(cin, razonSocial);

    do
    {
        cout << "Ingrese la cantidad de accionistas: ";
        cin >> cantidadAccionistas;

    } while (isdigit(cantidadAccionistas));

    string accionistasName[cantidadAccionistas];

    for (int i = 0; i < cantidadAccionistas; i++)
    {
        cout << "Ingrese el nombre del accionista " << i + 1 << ": ";
        getline(cin, accionistasName[i]);
        // Validar si el nombre del accionista contiene símbolos
        if (accionistasName[i].find_first_of("!@#$%^&*()_+{}|:\"<>?") != string::npos || accionistasName[i].empty() || accionistasName[i].find_first_of("0123456789") != string::npos)
        {
            cout << "El nombre del accionista no debe contener símbolos, números ni estar vacío." << endl;
            return 1;
        }
    }


    cout << "Ingrese la ubicación de las sucursales (si están en Caracas): ";
    getline(cin, ubicacionSucursal);

    // Validar si el nombre comercial o la razón social contienen símbolos
    if (nombreComercial.find_first_of("!@#$%^&*()_+{}|:\"<>?") != string::npos ||
        razonSocial.find_first_of("!@#$%^&*()_+{}|:\"<>?") != string::npos)
    {
        cout << "El nombre comercial o la razón social no deben contener símbolos." << endl;
        return 1;
    }

    // Validar si las sucursales están ubicadas en Caracas
    if (ubicacionSucursal.find("Caracas") != string::npos)
    {
        cout << "Las sucursales están ubicadas en Caracas." << endl;
        // Aquí podrías agregar lógica para mostrar los municipios y parroquias de Caracas
    }
    else
    {
        cout << "Las sucursales no están ubicadas en Caracas." << endl;
    }

    // Guardar la información en un archivo de texto
    ofstream archivo("informacion_empresa.txt");
    if (archivo.is_open())
    {
        archivo << "Nombre Comercial: " << nombreComercial << endl;
        archivo << "Razón Social: " << razonSocial << endl;
        archivo << "Cantidad de Accionistas: " << cantidadAccionistas << endl;
        archivo << "Cantidad de Sucursales: " << cantidadSucursales << endl;
        archivo << "Ubicación de Sucursales: " << ubicacionSucursal << endl;
        archivo.close();
        cout << "Información guardada en informacion_empresa.txt" << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo para escribir." << endl;
        return 1;
    }
}