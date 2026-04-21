// solicitar un rango de a;os
// cantidad de a;os en bisiestos
// y sumar los a;os que no son bisiestos

#include <iostream>

using namespace std;

int main()
{

    int anioInicio = 0;
    int anioFin = 0;
    int cantidadDeBisiestos = 0;
    int sumaDeNoBisiestos = 0;

    cout << "ingrese un a;o de inicio: ";
    cin >> anioInicio;

    system("clear");

    cout << "ingrese el a;o de fin: ";
    cin >> anioFin;

    if (anioFin < anioInicio)
    {
        cout << "el a;o de fin es menor que el de inicio por favor ingresa uno valido" << endl;
        system("pause");
    }

    for (int i = anioInicio; i <= anioFin; i++)
    {

        if (( i % 4 == 0 && i % 100 != 0 ) || ( i % 400 == 0 ))
        {

            cout << "el a;o " << i << " es bisiesto" << endl;
            cantidadDeBisiestos++;
            
        }
        else{

            cout << "el a;o " << i << " no es bisiesto" << endl;
            sumaDeNoBisiestos += i;

        }

    }

    cout << "la cantidad de a;os bisiestos dentro del rango es: " << cantidadDeBisiestos << endl;
    cout << "la suma de los a;os no bisiestos dentro del rango es: " << sumaDeNoBisiestos << endl;

}