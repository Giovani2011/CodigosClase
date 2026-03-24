
#include <iostream>

using namespace std;

int main()
{

    /*for (i = 0; i <= 400; i = i + 2)
    {
        cout << i << endl;
    };*/

    /*for ( int i = 501 ; i >= 3;  i=i-3)
    {
        cout << i << endl;
    };*/


    int countPar=0;
    int countImpar=0; 

    int sumPar=0;
    int sumImpar=0;

    for ( int i = 1; i <= 10; i++)
    {
        if (i%2==0)
        {
            countPar++;
            sumPar = sumPar + i;
        }
        else
        {
            countImpar++;
            sumImpar = sumImpar + i;
        }
    }
    cout << "Numeros pares: " << countPar << endl;
    cout << "Numeros impares: " << countImpar << endl;
    cout << "Suma de numeros pares: " << sumPar << endl;
    cout << "Suma de numeros impares: " << sumImpar << endl;

    return 0;
}