/*
Tabla de multiplicar inicio y final, solicitados por el usuario
*/


#include <iostream>

using namespace std;

int main()
{
    int TablaSolInicio;
    int TablaSolFinal;

    cout << "Ingrese el inicio de la tabla de multiplicar que desea ver: ";
    cin >> TablaSolInicio;
    cout << "Ingrese el final de la tabla de multiplicar que desea ver: ";
    cin >> TablaSolFinal;

    for (int i = TablaSolInicio; i <= TablaSolFinal; i++)
    {
        cout << "Tabla del " << i << endl;
        for (int j = 0; j <= 10; j++)
        {
            cout << i << " x " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
    
}