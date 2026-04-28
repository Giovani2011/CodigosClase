#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Estructura para la configuración de seguridad del sistema
struct EnvConfig {
    string aesKey;
};

// Función interna para obtener una clave de respaldo de forma "oculta"
// Esto evita que la clave sea visible como un string plano si alguien busca texto en el código
string obtenerClaveOculta() {
    string k = "";
    // Construcción dinámica de la clave de respaldo: "SECURE2024"
    k += (char)83; k += (char)69; k += (char)67; k += (char)85; 
    k += (char)82; k += (char)69; k += (char)50; k += (char)48; 
    k += (char)50; k += (char)52;
    return k;
}

// Función para cargar la configuración
EnvConfig leerEnv() {
    EnvConfig config;
    config.aesKey = obtenerClaveOculta(); // Cargamos el valor de respaldo oculto
    
    ifstream file(".env");
    if(file.is_open()) {
        string line;
        while(getline(file, line)) {
            // Si existe el archivo .env, sobreescribimos con la clave personalizada del usuario
            if(line.find("AES_KEY=") == 0) config.aesKey = line.substr(8);
        }
        file.close();
    }
    return config;
}

// Algoritmo de Encriptación XOR Manual
// Transforma el texto plano en una cadena hexadecimal segura para archivos .txt
string encriptar(const string& texto, const EnvConfig& config) {
    string res = "";
    for(size_t i = 0; i < texto.length(); i++) {
        // Operación binaria XOR entre el caracter y la clave secreta
        char c = texto[i] ^ config.aesKey[i % config.aesKey.length()];
        stringstream ss;
        // Convertimos el byte resultante a dos caracteres hexadecimales
        ss << hex << setw(2) << setfill('0') << (int)(unsigned char)c;
        res += ss.str();
    }
    return res;
}

// Algoritmo de Desencriptación XOR
// Revierte la cadena hexadecimal a su forma original usando la misma clave secreta
string desencriptar(const string& hex_texto, const EnvConfig& config) {
    string res = "";
    for(size_t i = 0; i < hex_texto.length(); i += 2) {
        // Extraemos cada par de caracteres hexadecimales (1 byte)
        string byteString = hex_texto.substr(i, 2);
        char c = (char)strtol(byteString.c_str(), NULL, 16);
        // La operación XOR es reversible: aplicándola de nuevo obtenemos el texto original
        char d = c ^ config.aesKey[(i/2) % config.aesKey.length()];
        res += d;
    }
    return res;
}

string generarPassword(int length = 8) {
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*";
    string result;
    for(int i = 0; i < length; i++) {
        result += charset[rand() % (sizeof(charset) - 1)];
    }
    return result;
}

// --- Clases Principales ---
struct Accionista {
    string nombre;
    string cedula;
    string acciones;
    string porcentaje;
    string passwordGenerado;
};

class ActaEmpresa {
public:

    void ProcesarDocumento() {
        ifstream archivo("Acta.txt");
        if(!archivo.is_open()) {
            cout << "[!] Error: No se pudo abrir Acta.txt" << endl;
            return;
        }

        // Leer todo el contenido del archivo a un string
        string contenido((istreambuf_iterator<char>(archivo)), istreambuf_iterator<char>());
        archivo.close();

        map<string, Accionista> mapa;
        string upper = contenido;
        // Convertir a mayúsculas para facilitar la búsqueda (insensible a minúsculas)
        for(auto &c : upper) c = toupper((unsigned char)c);

        size_t start = 0;
        // Buscar cada bloque que empiece por la palabra "ACCIONISTA"
        while((start = upper.find("ACCIONISTA", start)) != string::npos) {
            // Buscamos hasta el siguiente accionista o fin de archivo
            size_t next = upper.find("ACCIONISTA", start + 1);
            if(next == string::npos) next = upper.length();

            string frag = contenido.substr(start, next - start);
            string fragU = upper.substr(start, next - start);

            Accionista acc;
            
            // 1. Nombre: Se extrae el texto entre "ACCIONISTA" y la primera coma
            size_t c1 = fragU.find("ACCIONISTA") + 10;
            size_t c2 = fragU.find(",", c1);
            if(c2 != string::npos) {
                acc.nombre = frag.substr(c1, c2 - c1);
                acc.nombre.erase(0, acc.nombre.find_first_not_of(" \t\n\r"));
                acc.nombre.erase(acc.nombre.find_last_not_of(" \t\n\r") + 1);
            }

            // 2. Cédula: Se busca el prefijo V- o E-
            size_t cv = fragU.find("V-");
            if(cv == string::npos) cv = fragU.find("E-");
            if(cv != string::npos) {
                size_t cv_end = fragU.find_first_of(" ,)\n\r", cv);
                acc.cedula = frag.substr(cv, cv_end - cv);
            }

            // 3. Acciones: Se busca el número encerrado en paréntesis ( )
            size_t p1 = fragU.find("(");
            size_t p2 = fragU.find(")", p1);
            if(p1 != string::npos && p2 != string::npos) {
                acc.acciones = frag.substr(p1 + 1, p2 - p1 - 1);
            }

            // 4. Porcentaje: Se busca el símbolo %
            size_t pp = fragU.find("%");
            if(pp != string::npos) {
                size_t ps = fragU.rfind(" ", pp);
                if(ps == string::npos) ps = fragU.rfind("AL", pp) + 1;
                acc.porcentaje = frag.substr(ps + 1, pp - ps);
            }

            // Si tiene nombre y cédula, lo agregamos al mapa para procesar
            if(!acc.nombre.empty() && !acc.cedula.empty()) {
                mapa[acc.nombre] = acc;
            }
            start = next;
        }

        EnvConfig config = leerEnv();
        int count = 0;
        cout << "\n===== RESULTADOS DE LA BÚSQUEDA =====" << endl;
        for(auto const& it : mapa) {
            Accionista acc = it.second;
            // Generar clave aleatoria de 10 caracteres
            acc.passwordGenerado = generarPassword(10);
            // Encriptar la clave antes de guardarla
            string passEnc = encriptar(acc.passwordGenerado, config);

            // Guardar en la carpeta output usando la cédula como nombre de archivo
            string filename = "output/" + acc.cedula + ".txt";
            ofstream fileOut(filename);
            if(fileOut.is_open()) {
                fileOut << "Nombre=" << acc.nombre << endl;
                fileOut << "Cedula=" << acc.cedula << endl;
                fileOut << "Acciones=" << acc.acciones << endl;
                fileOut << "Porcentaje=" << acc.porcentaje << endl;
                fileOut << "ClaveEnc=" << passEnc << endl;
                fileOut.close();
                count++;
                cout << "[+] Accionista: " << acc.nombre << endl;
                cout << "    Cédula: " << acc.cedula << " | Acciones: " << (acc.acciones.empty() ? "N/A" : acc.acciones) << " (" << (acc.porcentaje.empty() ? "N/A" : acc.porcentaje) << ")" << endl;
                cout << "    Clave: " << acc.passwordGenerado << "\n" << endl;
            }
        }
        if(count == 0) cout << "[!] No se encontraron accionistas en el documento." << endl;
        else cout << ">> Total procesado: " << count << " accionistas con archivos generados." << endl;
        cout << "======================================\n" << endl;
    }

    void VerResumen() {
        ifstream archivo("Acta.txt");
        if(!archivo.is_open()) {
            cout << "[!] Error: No se pudo abrir Acta.txt" << endl;
            return;
        }

        string contenido((istreambuf_iterator<char>(archivo)), istreambuf_iterator<char>());
        archivo.close();

        string upper = contenido;
        for(auto &c : upper) c = toupper((unsigned char)c);

        // 1. Extraer Nombre de la Empresa (de la primera línea)
        string empresa = "No encontrada";
        size_t p_quote1 = contenido.find("\"");
        size_t p_quote2 = contenido.find("\"", p_quote1 + 1);
        if(p_quote1 != string::npos && p_quote2 != string::npos) {
            empresa = contenido.substr(p_quote1 + 1, p_quote2 - p_quote1 - 1);
        }

        // 2. Extraer Capital Social
        string capital = "No encontrado";
        size_t p_cap = upper.find("CAPITAL SOCIAL:");
        if(p_cap != string::npos) {
            // Buscamos el final de la frase (punto o la palabra 'dividido')
            size_t end = upper.find(", DIVIDIDO", p_cap);
            if(end == string::npos) end = contenido.find(".", p_cap);
            capital = contenido.substr(p_cap + 16, end - (p_cap + 16));
            // Limpiar espacios extras
            capital.erase(0, capital.find_first_not_of(" \t\n\r"));
        }

        // 3. Extraer Objetivos (de la línea 10 aprox)
        string objeto = "No encontrado";
        size_t p_obj = upper.find("OBJETO:");
        if(p_obj != string::npos) {
            size_t end = contenido.find("\n", p_obj);
            objeto = contenido.substr(p_obj + 8, end - (p_obj + 8));
        }

        cout << "\n===========================================================" << endl;
        cout << "                RESUMEN GENERAL DEL ACTA" << endl;
        cout << "===========================================================" << endl;
        cout << "EMPRESA: " << empresa << endl;
        cout << "CAPITAL: " << capital << endl;
        cout << "OBJETO:  " << objeto << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "ACCIONISTAS DETECTADOS EN EL DOCUMENTO:" << endl;
        cout << "-----------------------------------------------------------" << endl;

        // Re-usamos la lógica de extracción para mostrar el resumen
        size_t pos = 0;
        int count = 0;
        while((pos = upper.find("ACCIONISTA", pos)) != string::npos) {
            size_t next = upper.find("ACCIONISTA", pos + 1);
            if(next == string::npos) next = upper.length();
            string frag = contenido.substr(pos, next - pos);
            string fragU = upper.substr(pos, next - pos);

            string n = "N/A", c = "N/A", a = "0", p = "0%";
            
            size_t c1 = fragU.find("ACCIONISTA") + 10;
            size_t c2 = fragU.find(",", c1);
            if(c2 != string::npos) n = frag.substr(c1, c2 - c1);
            
            size_t cv = fragU.find("V-");
            if(cv == string::npos) cv = fragU.find("E-");
            if(cv != string::npos) {
                size_t cv_end = fragU.find_first_of(" ,)\n\r", cv);
                c = frag.substr(cv, cv_end - cv);
            }

            size_t p1 = fragU.find("(");
            size_t p2 = fragU.find(")", p1);
            if(p1 != string::npos && p2 != string::npos) a = frag.substr(p1 + 1, p2 - p1 - 1);

            size_t pp = fragU.find("%");
            if(pp != string::npos) {
                size_t ps = fragU.rfind(" ", pp);
                p = frag.substr(ps + 1, pp - ps);
            }

            // Limpieza básica de strings
            n.erase(0, n.find_first_not_of(" ")); n.erase(n.find_last_not_of(" ") + 1);

            if(n != "N/A") {
                cout << "  - " << n << " [" << c << "]" << endl;
                cout << "    Participación: " << a << " acciones (" << p << ")" << endl;
                count++;
            }
            pos = next;
        }
        cout << "-----------------------------------------------------------" << endl;
        cout << "TOTAL ACCIONISTAS: " << count << endl;
        cout << "===========================================================\n" << endl;
    }

    void IngresarSistema() {
        char tipo;
        string numero, clave;
        cout << "\n--- INGRESO AL SISTEMA ---" << endl;
        
        // Validación de Tipo (V/E)
        do {
            cout << "Ingrese su tipo de nacionalidad (V/E): ";
            cin >> tipo;
            tipo = toupper(tipo);
            if(tipo != 'V' && tipo != 'E') cout << "[!] Error: Debe ser V o E." << endl;
        } while(tipo != 'V' && tipo != 'E');

        // Validación de Número (Con puntos, sin comas)
        do {
            cout << "Ingrese su número de cédula (ej: 12.345.678): ";
            cin >> numero;
            if(numero.find(',') != string::npos) {
                cout << "[!] Error: No se permiten comas (,). Use puntos (.)" << endl;
                continue;
            }
            if(numero.find('.') == string::npos) {
                cout << "[!] Error: Debe incluir los puntos de separación." << endl;
                continue;
            }
            break;
        } while(true);

        cout << "Ingrese su contraseña: ";
        cin >> clave;

        string filename = "output/" + string(1, tipo) + "-" + numero + ".txt";
        ifstream file(filename);
        if(!file.is_open()) {
            cout << "\n[!] Error: Usuario no encontrado o archivo inexistente." << endl;
            return;
        }

        string line, nombre, cedula, acciones, porcentaje, claveEnc;
        while(getline(file, line)) {
            if(line.find("Nombre=") == 0) nombre = line.substr(7);
            if(line.find("Cedula=") == 0) cedula = line.substr(7);
            if(line.find("Acciones=") == 0) acciones = line.substr(9);
            if(line.find("Porcentaje=") == 0) porcentaje = line.substr(11);
            if(line.find("ClaveEnc=") == 0) claveEnc = line.substr(9);
        }
        file.close();

        EnvConfig config = leerEnv();
        string claveDec = desencriptar(claveEnc, config);

        if(clave == claveDec) {
            cout << "\n[+] Acceso Concedido." << endl;
            cout << "Bienvenido(a), " << nombre << "." << endl;
            cout << "--- SU PARTICIPACIÓN EN LA EMPRESA ---" << endl;
            cout << "Acciones poseídas: " << acciones << endl;
            cout << "Porcentaje del capital social: " << porcentaje << endl;
            cout << "--------------------------------------\n" << endl;
        } else {
            cout << "\n[!] Acceso Denegado: Contraseña incorrecta." << endl;
        }
    }
    
};

int main() {
    srand(time(0));
    ActaEmpresa app;
    int opcion = 0;

    do {
        cout << "\n===================================" << endl;
        cout << "      SISTEMA DE ACCIONISTAS" << endl;
        cout << "===================================" << endl;
        cout << "1. Leer el documento (Generar Usuarios)" << endl;
        cout << "2. Ingresar al sistema (Ver participación)" << endl;
        cout << "3. Ver resumen del acta" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                app.ProcesarDocumento();
                break;
            case 2:
                app.IngresarSistema();
                break;
            case 3:
                app.VerResumen();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    }while(opcion != 4);
    return 0;
}
