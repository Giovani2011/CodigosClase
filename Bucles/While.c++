
#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    int counter = 0;

    while (i <= 100)
    {
        cout << "Ingresa un numero: ";
        cin >> i;
        counter++;
    }
    cout << "El numero de veces que se ha intentado un numero es: " << counter << endl;

    return 0;
}