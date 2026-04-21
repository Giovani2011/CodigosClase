// solicitar al usuario un rango de numeros , del 1 al 10 ,
// cantidad de numeros primos dentro de ese rango
// sumar los numeros primos dentro del rango que diga el usuario
// sacar el promedio del rango
// el numero primo menor al promedio y numero primmo el mayor al promedio

#include <iostream>
using namespace std;

bool esPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int ini, fin, cant=0, suma=0, total=0, menor=-1, mayor=-1;
    double prom;

    cout << "Inicio: "; cin >> ini;
    cout << "Fin: "; cin >> fin;

    for (int i=ini; i<=fin; i++) {
        total += i;
        if (esPrimo(i)) { cant++; suma+=i; }
    }

    prom = (double)total/(fin-ini+1);

    for (int i=ini; i<=fin; i++) {

        if (esPrimo(i) && i<prom) menor=i;
        
    }

    for (int i=ini; i<=fin; i++) {
        if (esPrimo(i) && i>prom) { mayor=i; break; }
    }

    cout << "Primos: " << cant << endl;
    cout << "Suma primos: " << suma << endl;
    cout << "Promedio: " << prom << endl;

    if (menor!=-1) cout << "Primo menor al promedio: " << menor << endl;
    else cout << "No hay primo menor al promedio." << endl;
    if (mayor!=-1) cout << "Primo mayor al promedio: " << mayor << endl;
    else cout << "No hay primo mayor al promedio." << endl;
    return 0;
}