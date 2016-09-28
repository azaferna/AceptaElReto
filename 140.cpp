/*
Enunciado
Se trata de implementar un programa que sume los dígitos de un número entero no negativo. Por ejemplo, la suma de los dígitos del 3433 es 13.
Para darle un poco más de emoción, el programa no se limitará a escribir el resultado de la suma, sino que también escribirá todos los sumandos 
utilizados: 3 + 4 + 3 + 3 = 13.

Entrada 
La entrada consta de una serie de casos de prueba terminados con un número negativo. Cada caso de prueba es una simple línea con un número no 
negativo no mayor que 109 del que habrá que sumar todos sus dígitos.

Salida
Para cada caso de prueba se mostrará una línea en la que aparecerán cada uno de los dígitos separados por el signo +, tras lo cual aparecerá el símbolo = y la suma de todos los dígitos.
Ten en cuenta que antes y después de cada símbolo (+ y =) hay un espacio.

Ejemplo
--Entrada--
3433
64323
8
-1

--Salida--
3 + 4 + 3 + 3 = 13
6 + 4 + 3 + 2 + 3 = 18
8 = 8


*/
#include<iostream>
#include<string>
using namespace std;


int main()
{
    int numero;
    int suma = 0;
    string s;
    cin >> numero;
  
    while(numero >= 0){
        suma = 0;
         s= "";
        if (numero < 10){
            suma = numero;
            cout << numero << " = " << suma << endl;
        }
        else{
            while (numero != 0){
            
                s = to_string(numero % 10) + s ;
                suma = suma + numero%10;
                numero = numero /10;
                if(numero != 0)
                    s = " + " + s;
            }
            
            cout << s << " = " << suma << endl;
        }
        cin >> numero;
        
    }
    return 0;
}