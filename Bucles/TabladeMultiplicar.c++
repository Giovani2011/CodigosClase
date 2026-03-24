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
        int TotalResultTabla = 0;
        for (int j = 1; j <= 10; j++)
        {
            cout << i << " x " << j << " = " << i * j << endl;
            TotalResultTabla += i * j;
        }

        cout << "Total de la tabla del " << i << ": " << TotalResultTabla << endl;
        cout << "Promedio de la tabla del " << i << ": " << TotalResultTabla / 10.0 << endl;
        cout << endl;
    }
    
}