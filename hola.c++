#include <isotream>
// #include <stdlib.h>
#include <conio.h>

using namespace std;

int main (){
    // int anoUser= 0;
     char sex;


     cout << "ingresa tu ano de nacimiento : ";
     cin >> anoUser;

     cout << "ingresa tu sexo f o m :";

     cin >> sex;

     const int anoActual = 2026;

     int restaUser= anoActual - anoUser;

     if (restaUSer >= 18 && sex == 'f'){

        cout<< "Bienvenido"<< endl;
     }else{

        cout << "fuera" << endl;
     }

}



// investigar 

// serie fibonachi , numero romanos , numeros primos ,factorial , a;o bisiesto , capicua , palindromo
