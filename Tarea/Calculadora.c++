// importamos librerias imporyantes para el funcionamiento del programa

#include <iostream>
// input and output
#include <cmath>
// funciones matematicas
#include <regex>
#include <string>
// manejo de cadenas
#include <cstdlib>
// funciones de sistema para limpiar pantalla

using namespace std;

/**
 * Calculadora Modular Pro
 * Autor: Giovani Marcano
 * Use una arquitectura modular para organizar el código en funciones
 * específicas, mejorando la legibilidad y mantenibilidad.
 */

// Declaración de funciones para cada categoría de operaciones
void limpiarPantalla();
void configurarColor(int colorOpcion);
void menuPrincipal();
void menuColores();
void subMenuBasico();
void realizarOperacionBasica(int subOpcion);
void subMenuPotenciasRaices();
void realizarPotenciaRaiz(int subOpcion);
void verificarBisiesto();
void convertirRomano();
void verificarCapicua();
void tablaMultiplicar();
void calcularFactorial();
void verificarPrimo();
void serieFibonacci();
void DeterminarTriangulos();
void conversionesFisica();
void CalcularHipotenusa();
void DeterminarLaEdadPersona();

int main() {
  int opcion;
  char continuar;

  configurarColor(6); // Blanco inicial

  do {
    limpiarPantalla();
    menuPrincipal();

    if (!(cin >> opcion)) {
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }

    if (opcion == 0)
      break;

    limpiarPantalla();

    switch (opcion) {
    case 1:
      subMenuBasico();
      break;
    case 2:
      verificarBisiesto();
      break;
    case 3:
      convertirRomano();
      break;
    case 4:
      verificarCapicua();
      break;
    case 5:
      tablaMultiplicar();
      break;
    case 6:
      calcularFactorial();
      break;
    case 7:
      subMenuPotenciasRaices();
      break;
    case 8:
      verificarPrimo();
      break;
    case 9:
      serieFibonacci();
      break;
    case 10:
      menuColores();
      cout << "\nColor aplicado correctamente." << endl;
      break;
    case 11:
      DeterminarTriangulos();
      break;
    case 12:
      conversionesFisica();
      break;
    case 13:
      CalcularHipotenusa();
      break;
    case 14:
      DeterminarLaEdadPersona();
      break;
    default:
      cout << "Opcion no valida." << endl;
    }

    cout << "\n------------------------------------------" << endl;
    cout << "¿Desea realizar otra operacion general? (s/n): ";
    cin >> continuar;

  } while (continuar == 's' || continuar == 'S');

  limpiarPantalla();
  cout << "\033[0m"; // Resetear color al salir para no dejar la terminal pintada
  cout << "Finalizando programa... ¡Buen trabajo, Giovani!" << endl;
  return 0;
}

void DeterminarLaEdadPersona() {

  system("clear");
  int diadenacimiento, mesdenacimiento, añodenacimiento;
  int diaactual, mesactual, añoactual;
  
}

void conversionesFisica() {
  cout << "Por favor seleccione una conversion de unidad : \n1. centimetros a "
          "metros \n2. metros a centimetros \n3. kilometros a metros \n4. "
          "metros a kilometros \n5. libras a kilogramos \n6. kilogramos a "
          "libras \n7. grados Celsius a Fahrenheit \n8. grados Fahrenheit a "
          "Celsius\nSeleccione: ";

  int opcionSeleccionada;

  cin >> opcionSeleccionada;

  switch (opcionSeleccionada) {
  case 1: {
    system("clear");
    float centimetros, metros;
    cout << "Ingrese la cantidad en centimetros: ";
    cin >> centimetros;
    metros = centimetros / 100;
    cout << centimetros << " centimetros son " << metros << " metros." << endl;
    break;
  }

  case 2: {
    system("clear");
    float metros2, centimetros2;
    cout << "Ingrese la cantidad en metros: ";
    cin >> metros2;
    centimetros2 = metros2 * 100;
    cout << metros2 << " metros son " << centimetros2 << " centimetros."
         << endl;
    break;
  }

  case 3: {
    system("clear");
    float kilometros, metros3;
    cout << "Ingrese la cantidad en kilometros: ";
    cin >> kilometros;
    metros3 = kilometros * 1000;
    cout << kilometros << " kilometros son " << metros3 << " metros." << endl;
    break;
  }

  case 4: {
    system("clear");
    float metros4, kilometros2;
    cout << "Ingrese la cantidad en metros: ";
    cin >> metros4;
    kilometros2 = metros4 / 1000;
    cout << metros4 << " metros son " << kilometros2 << " kilometros." << endl;
    break;
  }
  case 5: {
    system("clear");
    int libras;
    double kilogramos;
    cout << "por favor ingresa una cantidad de libras:";
    cin >> libras;
    double calculoLibrasKilos = libras / 2.20462;
    cout << libras << " libras son " << calculoLibrasKilos << " kilogramos."
         << endl;
    break;
  }
  case 6: {
    system("clear");
    int kilogramos2;
    double libras2;
    cout << "por favor ingresa una cantidad de kilogramos:";
    cin >> kilogramos2;

    libras2 = kilogramos2 * 2.20462;

    cout << kilogramos2 << " kilogramos son " << libras2 << " libras." << endl;
    break;
  }

  case 7: {
    system("clear");
    float gradosCelsius, gradosFahrenheit;
    cout << "Ingrese la cantidad en grados Celsius: ";
    cin >> gradosCelsius;
    gradosFahrenheit = (gradosCelsius * 9 / 5) + 32;
    cout << gradosCelsius << " grados Celsius son " << gradosFahrenheit
         << " grados Fahrenheit." << endl;
    break;
  }

  case 8: {
    system("clear");
    float gradosFahrenheit2, gradosCelsius2;
    cout << "Ingrese la cantidad en grados Fahrenheit: ";
    cin >> gradosFahrenheit2;
    gradosCelsius2 = (gradosFahrenheit2 - 32) * 5 / 9;
    cout << gradosFahrenheit2 << " grados Fahrenheit son " << gradosCelsius2
         << " grados Celsius." << endl;
    break;
  }

  case 9: {
    system("clear");
    float gradosFahrenheit3, gradosCelsius3;
    cout << "Ingrese la cantidad en grados Fahrenheit: ";
    cin >> gradosFahrenheit3;
    gradosCelsius3 = (gradosFahrenheit3 - 32) * 5 / 9;
    cout << gradosFahrenheit3 << " grados Fahrenheit son " << gradosCelsius3
         << " grados Celsius." << endl;
    break;
  }

default:
    break;
  }

}

void CalcularHipotenusa(){
  system("clear");
  int Lopuesto;
  int Ladyacente;

  cout << "Ingrese cateto opuesto : ";
  cin>>Lopuesto;

  cout << "Ingrese cateto adyacente : "; 
  cin>> Ladyacente;

  double Hipotenusa = sqrt(pow(Lopuesto,2) + pow(Ladyacente,2));

  cout << "La hipotenusa es: " << Hipotenusa << endl;
}

void DeterminarTriangulos() {
  int Lado1;
  int Lado2;
  int Lado3;

  double Hipotenusa;

  cout << "ingrese lado 1 del traingulo:";
  cin >> Lado1;

  cout << "ingrese lado 2 del traingulo:";
  cin >> Lado2;

  cout << "ingrese lado 3 del traingulo:";
  cin >> Lado3;


  if (Lado1 == Lado2 && Lado2 == Lado3) {

   
    cout << "El triangulo es equilatero";
    cout << "\nLa hipotenusa es: " << Hipotenusa << endl;

  } else if (Lado1 == Lado2 || Lado1 == Lado3 || Lado2 == Lado3) {

    cout << "El triangulo es isosceles";
    cout << "\nLa hipotenusa es: " << Hipotenusa << endl;

  } else {
    cout << "El triangulo es escaleno";
    cout << "\nLa hipotenusa es: " << Hipotenusa << endl;
  }
}

void limpiarPantalla() {
  system("clear"); // Comando estándar en Mac/Linux
}

void configurarColor(int colorOpcion) {
  // Usamos códigos ANSI para macOS
  switch (colorOpcion) {
  case 1:
    cout << "\033[1;32m";
    break; // Verde
  case 2:
    cout << "\033[1;36m";
    break; // Celeste
  case 3:
    cout << "\033[1;31m";
    break; // Rojo
  case 4:
    cout << "\033[1;33m";
    break; // Amarillo
  case 5:
    cout << "\033[1;35m";
    break; // Púrpura
  default:
    cout << "\033[1;37m";
    break; // Blanco
  }
}

void menuColores() {
  int c;
  cout << "==========================================" << endl;
  cout << "       PERSONALIZAR COLOR DE LETRAS       " << endl;
  cout << "==========================================" << endl;
  cout << "1. Verde Neón\n2. Celeste\n3. Rojo\n4. Amarillo\n5. Púrpura\n6. "
          "Blanco\nElija su color: ";
  cin >> c;
  configurarColor(c);
}

void menuPrincipal() {
  cout << "==========================================" << endl;
  cout << "          CALCULADORA MULTITAREA          " << endl;
  cout << "==========================================" << endl;
  cout << "1.  Operaciones Basicas\n2.  Año Bisiesto\n3.  Numeros Romanos\n4.  "
          "Capicua\n5.  Tabla de Multiplicar\n6.  Factorial\n7.  Potencias y "
          "Raices\n8.  Numero Primo\n9.  Fibonacci \n10. PERSONALIZAR COLOR "
          "\n11. Determinar que triangulo es \n12.Trasnformar unidades \n13. Calcular la hipotenusa sabiendo catetos opuestos y adyacentes. \n0.  "
          "Salir"
       << endl;
  cout << "------------------------------------------" << endl;
  cout << "Seleccione: ";
}

void subMenuPotenciasRaices() {
  limpiarPantalla();
  int subOpcion;
  cout << ">>> CATEGORIA: POTENCIAS Y RAICES" << endl;
  cout << "------------------------------------------" << endl;
  cout << "1. Elevar al Cuadrado (^2)\n2. Elevar al Cubo (^3)\n3. Raiz "
          "Cuadrada\n4. Raiz Cubica\nSeleccione: ";
  cin >> subOpcion;
  realizarPotenciaRaiz(subOpcion);
}

void realizarPotenciaRaiz(int subOpcion) {
  limpiarPantalla();
  string opNombre;
  switch (subOpcion) {
  case 1:
    opNombre = "ELEVAR AL CUADRADO";
    break;
  case 2:
    opNombre = "ELEVAR AL CUBO";
    break;
  case 3:
    opNombre = "RAIZ CUADRADA";
    break;
  case 4:
    opNombre = "RAIZ CUBICA";
    break;
  default:
    return;
  }

  cout << "HAS SELECCIONADO: " << opNombre << endl;
  cout << "------------------------------------------" << endl;

  double num;
  cout << "Ingrese el numero: ";
  cin >> num;
  cout << "\nRESULTADO:" << endl;

  switch (subOpcion) {
  case 1:
    cout << " -> " << num << "^2 = " << pow(num, 2) << endl;
    break;
  case 2:
    cout << " -> " << num << "^3 = " << pow(num, 3) << endl;
    break;
  case 3:
    if (num >= 0)
      cout << " -> Raiz Cuadrada de " << num << " = " << sqrt(num) << endl;
    else
      cout << " -> Error: Numero negativo." << endl;
    break;
  case 4:
    cout << " -> Raiz Cubica de " << num << " = " << cbrt(num) << endl;
    break;
  }
}

void subMenuBasico() {
  limpiarPantalla();
  int subOpcion;
  cout << ">>> CATEGORIA: OPERACIONES BASICAS" << endl;
  cout << "------------------------------------------" << endl;
  cout << "1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\nSeleccione: ";
  cin >> subOpcion;
  realizarOperacionBasica(subOpcion);
}

void realizarOperacionBasica(int subOpcion) {
  limpiarPantalla();
  string opNombre = (subOpcion == 1)   ? "SUMA"
                    : (subOpcion == 2) ? "RESTA"
                    : (subOpcion == 3) ? "MULTIPLICACION"
                                       : "DIVISION";

  cout << "HAS SELECCIONADO: " << opNombre << endl;
  cout << "------------------------------------------" << endl;

  double n1, n2;
  cout << "Primer numero: ";
  cin >> n1;
  cout << "Segundo numero: ";
  cin >> n2;
  cout << "\nRESULTADO:" << endl;

  switch (subOpcion) {
  case 1:
    cout << " -> " << n1 << " + " << n2 << " = " << n1 + n2 << endl;
    break;
  case 2:
    cout << " -> " << n1 << " - " << n2 << " = " << n1 - n2 << endl;
    break;
  case 3:
    cout << " -> " << n1 << " * " << n2 << " = " << n1 * n2 << endl;
    break;
  case 4:
    if (n2 != 0)
      cout << " -> " << n1 << " / " << n2 << " = " << n1 / n2 << endl;
    else
      cout << " -> Error: Division por cero." << endl;
    break;
  }
}

void verificarBisiesto() {
  int a;
  cout << "Año: ";
  cin >> a;
  cout << (((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
               ? "\nEs bisiesto."
               : "\nNo es bisiesto.")
       << endl;
}

void convertirRomano() {
  int n;
  cout << "Numero (1-999): ";
  cin >> n;
  string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  string d[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  string u[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  cout << "\nResultado: " << c[(n / 100) % 10] << d[(n / 10) % 10] << u[n % 10]
       << endl;
}
void verificarCapicua() {
  int n, r, v = 0;
  cout << "Numero: ";
  cin >> n;
  r = n;
  while (n > 0) {
    v = (v * 10) + (n % 10);
    n /= 10;
  }
  cout << (r == v ? "\nEs capicua." : "\nNo es capicua.") << endl;
}

void tablaMultiplicar() {
  int t;
  int tI;
  int TF;
  cout << "Numero: ";
  cin >> t;
  cout<< endl;

  cout << "ingrese numero de inicio: ";

  cin >> tI;

  cout<< endl;

   cout << "ingrese numero de fin: ";

  cin >> TF;

  cout<< endl;


  for (int i = tI; i <= TF; i++)
    cout << t << " x " << i << " = " << t * i << endl;
}

void calcularFactorial() {
  int n;
  unsigned long long f = 1;
  cout << "Numero: ";
  cin >> n;
  for (int i = 1; i <= n; i++)
    f *= i;
  cout << "\nFactorial: " << f << endl;
}

void verificarPrimo() {
  int p, d = 0;
  cout << "Numero: ";
  cin >> p;
  for (int i = 1; i <= p; i++)
    if (p % i == 0)
      d++;
  cout << (d == 2 ? "\nEs primo." : "\nNo es primo.") << endl;
}

void serieFibonacci() {
  int l, a = 0, b = 1, s;
  cout << "Terminos: ";
  cin >> l;
  for (int i = 1; i <= l; i++) {
    cout << a << (i == l ? "" : ", ");
    s = a + b;
    a = b;
    b = s;
  }
  cout << endl;
}