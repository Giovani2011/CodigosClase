
#include <iostream>

using namespace std;

int main()
{
  int x;

  cout << "1. Lunes" << endl;
  cout << "2. Martes" << endl;
  cout << "3. Miércoles" << endl;
  cout << "4. Jueves" << endl;
  cout << "5. Viernes" << endl;
  cout << "6. Sábado" << endl;
  cout << "7. Domingo" << endl;

  cout << "Ingrese una de las opciones mencionadas: ";
  cin >> x;

  switch (x)
  {
  case 1:
    cout << "has seleccionada el lunes" << endl;
    system("pause");
    break;
  case 2:
    cout << "has seleccionada el martes" << endl;
    system("pause");
    break;
  case 3:
    cout << "has seleccionada el miércoles" << endl;
    system("pause");
    break;
  case 4:
    cout << "has seleccionada el jueves" << endl;
    system("pause");
    break;
  case 5:
    cout << "has seleccionada el viernes" << endl;
    system("pause");
    break;
  case 6:
    cout << "has seleccionada el sábado" << endl;
    system("pause");
    break;
  case 7:
    cout << "has seleccionada el domingo" << endl;
    break;

  default:
    cout << "no has seleccionado ninguna opción válida" << endl;
    break;
  }

  return 0;
}
