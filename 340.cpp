/*
Enunciado
Hay múltiples juegos y acertijos que empiezan con cerillas en una mesa colocadas formando cuadrados como en la figura:
                _ _ _
               |_|_|_|
               |_|_|_|
               |_|_|_|

Las preguntas suelen ser del estilo de "¿Cuántas cerillas hay que quitar como mínimo para conseguir tres rectángulos?". 
Nosotros nos planteamos algo más sencillo: ¿cuántas cerillas se necesitan para crear una figura con N×M cuadrados?


Entrada 
La entrada comienza con un número que indica cuántos casos de prueba vendrán a continuación, cada uno en una línea.

Cada caso de prueba contiene dos números indicando el número de cuadrados que se quieren formar en horizontal y vertical respectivamente. 
Ambos son mayores que 0 y menores que 1.000.

Salida
Para cada caso de prueba se escribirá una línea indicando el número de cerillas necesarias para construir el tablero solicitado.

Ejemplo
--Entrada--
2
1 1
3 3

--Salida--
4
24

*/
#include<iostream>
using namespace std;

int main()
{
    int casos;
    int max = 0;
    int dato;
    bool ok = true;
    
    while(ok){
        cin >> casos;
        if (!cin)
            ok = false;
        else{
            for(int i = 0; i< casos; i++){
                cin >> dato;
                if(dato > max)
                        max = dato;
                else
                    ok = false;
            }
            cout << max << "\n";
            max = 0;
        }
    }
   
    return 0;
}