#include <iostream>

using namespace std;

int main() {
  string  Rif;

    cout << "Ingrese el Rif: ";

    cin >> Rif;

    if (Rif.length() == 0) {
        cout << "El Rif esta vacio" << endl;
        return 1;
    } else {
        
        for (int i = 0; i < Rif.length(); i++) {
            if (isalpha(Rif[i])) {
                cout << "El Rif contiene letras" << endl;
                return 0;
            }
        }
        cout << "El Rif no contiene letras" << endl;
        return 0;
    }
}