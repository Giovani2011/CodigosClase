#include "iostream"

using namespace std;

int main() {
  string texto;

  cout << "Ingrese un nombre: ";
  cin >> texto;

  if (texto.length() == 0) {
    cout << "El texto esta vacio" << endl;
    return 1;
  } else {

    // validamos si el texto contiene numeros

    for (int i = 0; i < texto.length(); i++) {
      if (isdigit(texto[i])) {
        cout << "El nombre contiene numeros" << endl;
        return 0;
      }
    }
    cout << "El nombre no contiene numeros" << endl;
    return 0;
  }
}