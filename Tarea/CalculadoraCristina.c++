#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int opcion;
    char continuar;

    //iniciamos el bucle principal del programa

    do {
        system("clear");
        cout << "          CALCULADORA          " << endl;
        cout << "------------------------------------------" << endl;
        cout << "1.  Operaciones Basicas" << endl;
        cout << "2.  Año Bisiesto" << endl;
        cout << "3.  Numeros Romanos (1-999)" << endl;
        cout << "4.  Capicua" << endl;
        cout << "5.  Tabla de Multiplicar" << endl;
        cout << "6.  Factorial" << endl;
        cout << "7.  Potencias y Raices" << endl;
        cout << "8.  Numero Primo" << endl;
        cout << "9.  Fibonacci" << endl;
        cout << "0.  Salir" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Seleccione: ";
        
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (opcion == 0) break;

        system("clear");

        switch (opcion) {
            case 1: {
                int sub;
                double n1, n2;
                cout << "1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\nSeleccione: ";
                cin >> sub;
                cout << "Ingrese dos numeros: "; cin >> n1 >> n2;
                if (sub == 1) cout << "Resultado: " << n1 + n2 << endl;
                else if (sub == 2) cout << "Resultado: " << n1 - n2 << endl;
                else if (sub == 3) cout << "Resultado: " << n1 * n2 << endl;
                else if (sub == 4 && n2 != 0) cout << "Resultado: " << n1 / n2 << endl;
                else cout << "Error." << endl;
                break;
            }
            case 2: {
                int a;
                cout << "Ingrese año: "; cin >> a;
                if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) cout << "Es bisiesto." << endl;
                else cout << "No es bisiesto." << endl;
                break;
            }
            case 3: {
                int n;
                cout << "Numero (1-999): "; cin >> n;
                string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
                string d[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
                string u[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
                cout << "Romano: " << c[(n/100)%10] << d[(n/10)%10] << u[n%10] << endl;
                break;
            }
            case 4: {
                int n, r, v = 0;
                cout << "Ingrese numero: "; cin >> n;
                r = n;
                while (n > 0) { v = (v * 10) + (n % 10); n /= 10; }
                if (r == v) cout << "Es capicua." << endl;
                else cout << "No es capicua." << endl;
                break;
            }
            case 5: {
                int t;
                cout << "Tabla del: "; cin >> t;
                for (int i = 1; i <= 10; i++) cout << t << " x " << i << " = " << t * i << endl;
                break;
            }
            case 6: {
                int n;
                unsigned long long f = 1;
                cout << "Factorial de: "; cin >> n;
                for (int i = 1; i <= n; i++) f *= i;
                cout << "Resultado: " << f << endl;
                break;
            }
            case 7: {
                int sub;
                double num;
                cout << "1. Cuadrado\n2. Cubo\n3. Raiz Cuadrada\n4. Raiz Cubica\nSeleccione: ";
                cin >> sub;
                cout << "Ingrese numero: "; cin >> num;
                if (sub == 1) cout << "Resultado: " << pow(num, 2) << endl;
                else if (sub == 2) cout << "Resultado: " << pow(num, 3) << endl;
                else if (sub == 3 && num >= 0) cout << "Resultado: " << sqrt(num) << endl;
                else if (sub == 4) cout << "Resultado: " << cbrt(num) << endl;
                else cout << "Error." << endl;
                break;
            }
            case 8: {
                int p, d = 0;
                cout << "Ingrese numero: "; cin >> p;
                for (int i = 1; i <= p; i++) if (p % i == 0) d++;
                if (d == 2) cout << "Es primo." << endl;
                else cout << "No es primo." << endl;
                break;
            }
            case 9: {
                int l, a = 0, b = 1, s;
                cout << "Cantidad de terminos: "; cin >> l;
                for (int i = 1; i <= l; i++) {
                    cout << a << (i == l ? "" : ", ");
                    s = a + b; a = b; b = s;
                }
                cout << endl;
                break;
            }
            default:
                cout << "Opcion invalida." << endl;
        }

        cout << "\n------------------------------------------" << endl;
        cout << "¿Desea realizar otra operacion? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "Finalizando programa... ¡Buen trabajo!" << endl;
    return 0;
}