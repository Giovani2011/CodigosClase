#include <iostream>
#include <string>
#include <iomanip> // Para formatear la salida
#include <limits>  // Para validar entradas
#include <thread> // Para usar std::this_thread::sleep_for
#include <chrono> // Para std::chrono::seconds

#ifdef _WIN32
#include <windows.h> // Para cambiar colores en Windows
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#endif

using namespace std;

// Constante para la tasa de cambio (BCV)
const double TASA_BCV = 30.5;          // Ejemplo de tasa de cambio
const int HORAS_LABORALES_DIARIAS = 7; // 8 horas menos 1 hora de almuerzo
const int DIAS_LABORALES_SEMANALES = 5;
const int SEMANAS_LABORALES_MENSUALES = 4;

// Función para cambiar colores en la consola
void cambiarColor(int color)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
#else
    string colorCode;
    switch (color)
    {
    case 10: // Verde
        colorCode = "\033[0;32m";
        break;
    case 9: // Azul
        colorCode = "\033[0;34m";
        break;
    case 14: // Amarillo
        colorCode = "\033[0;33m";
        break;
    case 12: // Rojo
        colorCode = "\033[0;31m";
        break;
    default: // Por defecto
        colorCode = "\033[0m";
        break;
    }
    cout << colorCode;
#endif
}

// Función para restaurar el color por defecto
void restaurarColor()
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
#else
    cout << "\033[0m";
#endif
}

// Función para limpiar la pantalla
void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system(CLEAR_SCREEN);
#endif
}

// Función para mostrar un encabezado decorativo
void mostrarEncabezado(const string &titulo, const string &datosRecopilados = "")
{
    limpiarPantalla();
    cout << string(50, '*') << "\n";
    cout << "*" << setw(48) << right << "*\n";
    cout << "*" << setw((48 - titulo.length()) / 2) << " " << titulo << setw((48 - titulo.length()) / 2) << " " << "*\n";
    cout << "*" << setw(48) << right << "*\n";
    cout << string(50, '*') << "\n\n";
    if (!datosRecopilados.empty())
    {
        cout << datosRecopilados << "\n\n";
    }
}

// Función para mostrar una animación de carga
void mostrarCargando(const string &mensaje, int duracionSegundos = 3)
{
    cout << mensaje;
    for (int i = 0; i < duracionSegundos; ++i)
    {
        cout << ".";
        cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    cout << "\n";
}

int main()
{
    // Opción para cambiar el color de la terminal
    int colorOpcion;
    cout << "Seleccione un color para la terminal:\n";
    cout << "1. Verde\n2. Azul\n3. Amarillo\n4. Rojo\n5. Por defecto\n";
    cout << "Ingrese su opción: ";
    cin >> colorOpcion;

    switch (colorOpcion)
    {
    case 1:
        cambiarColor(10); // Verde
        break;
    case 2:
        cambiarColor(9); // Azul
        break;
    case 3:
        cambiarColor(14); // Amarillo
        break;
    case 4:
        cambiarColor(12); // Rojo
        break;
    default:
        restaurarColor(); // Por defecto
        break;
    }

    // Variables principales
    double sueldoMensual = 0, bonoProductividad = 0, bonoAntiguedad = 0;
    string cumplimientoTareas;
    string nombre, sexo;
    int antiguedad = 0;
    bool ausencias = false;
    int edad = 0;
    int hijos = 0;
    string estadoCivil;

    // Declarar las variables necesarias antes de usarlas
    double horasSemanales = HORAS_LABORALES_DIARIAS * DIAS_LABORALES_SEMANALES;
    double horasMensuales = horasSemanales * SEMANAS_LABORALES_MENSUALES;
    if (ausencias)
    {
        horasMensuales -= HORAS_LABORALES_DIARIAS; // Ajuste por ausencias
    }

    // Entrada de datos personales (primero)
    mostrarEncabezado("Sistema de Nóminas");
    while (true)
    {
        mostrarEncabezado("Sistema de Nóminas", "Datos personales del empleado");
        cout << "Ingrese el nombre del empleado: ";
        getline(cin >> ws, nombre);
        if (nombre.empty())
        {
            cout << "Entrada inválida. Por favor, ingrese un nombre válido.\n";
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        mostrarEncabezado("Sistema de Nóminas", "Datos personales:\nNombre: " + nombre);
        cout << "Ingrese el sexo del empleado (Mujer/Hombre): ";
        cin >> sexo;
        if (sexo != "Mujer" && sexo != "Hombre")
        {
            cout << "Entrada inválida. Por favor, ingrese 'Mujer' o 'Hombre'.\n";
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        int edadMaxima = (sexo == "Hombre") ? 70 : 60;
        mostrarEncabezado("Sistema de Nóminas", "Datos personales:\nNombre: " + nombre + "\nSexo: " + sexo);
        cout << "Ingrese la edad del empleado: ";
        cin >> edad;

        if (cin.fail())
        {
            cout << "Entrada inválida. Por favor, ingrese una edad numérica.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (edad < 18 || edad > edadMaxima)
        {
            cout << "Edad inválida. Debe ser mayor o igual a 18 y menor o igual a " << edadMaxima << ".\n";
            continue;
        }

        break;
    }

    while (true)
    {
        mostrarEncabezado("Sistema de Nóminas", "Datos personales:\nNombre: " + nombre + "\nSexo: " + sexo + "\nEdad: " + to_string(edad));
        cout << "Ingrese el número de hijos del empleado: ";
        cin >> hijos;
        if (cin.fail() || hijos < 0)
        {
            cout << "Entrada inválida. Por favor, ingrese un número válido.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        mostrarEncabezado("Sistema de Nóminas", "Datos personales:\nNombre: " + nombre + "\nSexo: " + sexo + "\nEdad: " + to_string(edad) + "\nHijos: " + to_string(hijos));
        cout << "¿El empleado está casado? (si/no): ";
        cin >> estadoCivil;
        if (estadoCivil != "si" && estadoCivil != "no")
        {
            cout << "Entrada inválida. Por favor, ingrese 'si' o 'no'.\n";
        }
        else
        {
            break;
        }
    }

    // Entrada de datos de nómina
    while (true)
    {
        mostrarEncabezado("Sistema de Nóminas", "Datos recopilados: \nSueldo mensual: " + to_string(sueldoMensual));
        cout << "Ingrese el sueldo mensual del empleado: ";
        cin >> sueldoMensual;
        if (cin.fail() || sueldoMensual <= 0)
        {
            cout << "Entrada inválida. Por favor, ingrese un número positivo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        mostrarEncabezado("Sistema de Nóminas", "Datos recopilados: \nSueldo mensual: " + to_string(sueldoMensual));
        cout << "¿El empleado cumplió con el 100% de sus tareas? (si/no): ";
        cin >> cumplimientoTareas;
        if (cumplimientoTareas != "si" && cumplimientoTareas != "no")
        {
            cout << "Entrada inválida. Por favor, ingrese 'si' o 'no'.\n";
        }
        else
        {
            break;
        }
    }

    if (cumplimientoTareas == "si")
    {
        while (true)
        {
            mostrarEncabezado("Sistema de Nóminas", "Datos recopilados: \nSueldo mensual: " + to_string(sueldoMensual) + "\nCumplimiento: " + cumplimientoTareas);
            cout << "Ingrese el bono por productividad: ";
            cin >> bonoProductividad;
            if (cin.fail() || bonoProductividad < 0)
            {
                cout << "Entrada inválida. Por favor, ingrese un número positivo o cero.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        }
    }

    while (true)
    {
        mostrarEncabezado("Sistema de Nóminas", "Datos recopilados: \nSueldo mensual: " + to_string(sueldoMensual) + "\nCumplimiento: " + cumplimientoTareas);
        cout << "Ingrese el bono por antigüedad: ";
        cin >> bonoAntiguedad;
        if (cin.fail() || bonoAntiguedad < 0)
        {
            cout << "Entrada inválida. Por favor, ingrese un número positivo o cero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        mostrarEncabezado("Sistema de Nóminas", "Datos recopilados: \nSueldo mensual: " + to_string(sueldoMensual) + "\nCumplimiento: " + cumplimientoTareas);
        cout << "Ingrese la antigüedad del empleado en años: ";
        cin >> antiguedad;
        if (cin.fail() || antiguedad < 0)
        {
            cout << "Entrada inválida. Por favor, ingrese un número entero positivo o cero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        mostrarEncabezado("Sistema de Nóminas", "Datos recopilados: \nSueldo mensual: " + to_string(sueldoMensual) + "\nCumplimiento: " + cumplimientoTareas);
        cout << "¿El empleado alguna vez se ha ausentado? (si/no): ";
        string respuestaAusencia;
        cin >> respuestaAusencia;
        if (respuestaAusencia == "si")
        {
            ausencias = true;
            break;
        }
        else if (respuestaAusencia == "no")
        {
            ausencias = false;
            break;
        }
        else
        {
            cout << "Entrada inválida. Por favor, ingrese 'si' o 'no'.\n";
        }
    }

    // Solicitar el tiempo de ausencia si el empleado se ausentó
    int diasAusencia = 0;
    if (ausencias) {
        while (true) {
            mostrarEncabezado("Sistema de Nóminas", "Datos recopilados: \nAusencias: Si");
            cout << "¿Cuántos días se ausentó el empleado?: ";
            cin >> diasAusencia;
            if (cin.fail() || diasAusencia < 0) {
                cout << "Entrada inválida. Por favor, ingrese un número válido.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }

    // Mostrar resumen de datos recopilados
    mostrarEncabezado("Sistema de Nóminas - Resumen", "Nombre: " + nombre + "\nSexo: " + sexo + "\nEdad: " + to_string(edad) + "\nHijos: " + to_string(hijos) + "\nEstado civil: " + estadoCivil);

    // Continuar con los cálculos existentes
    double sueldoConBonos = sueldoMensual + bonoProductividad + bonoAntiguedad;
    double sueldoSemanal = sueldoMensual / 4;
    double sueldoDiario = sueldoSemanal / 5;
    double sueldoPorHora = sueldoDiario / HORAS_LABORALES_DIARIAS;

    double retencion = sueldoConBonos * 0.10;
    double seguroSocial = sueldoConBonos * 0.04;
    double sueldoNeto = sueldoConBonos - retencion - seguroSocial;

    double sueldoMensualBs = sueldoMensual * TASA_BCV;
    double sueldoNetoBs = sueldoNeto * TASA_BCV;

    // Mostrar animación de carga antes de los cálculos
    mostrarCargando("Calculando resultados", 5);

    // Mostrar resultados en columnas bien alineadas
    mostrarEncabezado("Sistema de Nóminas - Resultados", "");
    cout << left << setw(30) << "Concepto" << right << setw(20) << "Monto" << endl;
    cout << string(50, '-') << endl;
    cout << left << setw(30) << "Sueldo mensual:" << right << setw(20) << fixed << setprecision(2) << sueldoMensual << " USD (" << sueldoMensualBs << " Bs)" << endl;
    cout << left << setw(30) << "Bono por productividad:" << right << setw(20) << bonoProductividad << endl;
    cout << left << setw(30) << "Bono por antigüedad:" << right << setw(20) << bonoAntiguedad << endl;
    cout << left << setw(30) << "Sueldo con bonos:" << right << setw(20) << sueldoConBonos << endl;
    cout << left << setw(30) << "Sueldo semanal:" << right << setw(20) << sueldoSemanal << endl;
    cout << left << setw(30) << "Sueldo diario:" << right << setw(20) << sueldoDiario << endl;
    cout << left << setw(30) << "Sueldo por hora:" << right << setw(20) << sueldoPorHora << endl;
    cout << left << setw(30) << "Retención:" << right << setw(20) << retencion << endl;
    cout << left << setw(30) << "Seguro social:" << right << setw(20) << seguroSocial << endl;
    cout << left << setw(30) << "Sueldo neto:" << right << setw(20) << sueldoNeto << " USD (" << sueldoNetoBs << " Bs)" << endl;
    cout << left << setw(30) << "Horas trabajadas semanalmente:" << right << setw(20) << horasSemanales << endl;
    cout << left << setw(30) << "Horas trabajadas mensualmente:" << right << setw(20) << horasMensuales << endl;

    return 0;
}