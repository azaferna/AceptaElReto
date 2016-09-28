/*
Enunciado
Es bien sabido que los monjes, en las abadías, se levantan muy temprano para rezar durante maitines, observando la salida del sol.
La localización de las abadías y monasterios es por tanto de vital importancia para que se pueda observar el sol aparecer en el horizonte. 
Los monjes prefieren las localizaciones que no tengan montañas altas hacia el Este, que les impedirían ver salir el sol.
Esto es un problema especial en los Pirineos, la cordillera montañosa que va de Oeste a Este y separa la Península Ibérica del resto del 
continente europeo. Los Pirineos están llenos de lugares tranquilos y mágicos, por lo que son emblemáticos para la meditación y el rezo. 
Pero al estar orientados de Oeste a Este, tienen una limitación en el número de localizaciones candidatas a construir abadías, es decir las que 
reciben el sol en los primeros momentos de la mañana. Este problema lo sufren también otras cordilleras en todo el mundo.

Entrada 
La entrada estará compuesta de multiples casos de prueba.
Cada caso de prueba comenzará con un número indicando el número de montañas de una determinada cordillera montañosa que avanza de Oeste a Este.
A continuación se indicarán las alturas (en metros, sin decimales) de cada una de esas montañas, comenzando con la situada más al Oeste. 
Ninguna cordillera tendrá más de 100.000 montañas.
La entrada terminará con una cordillera sin montañas, que no debe procesarse.

Salida
Para cada caso de prueba se debe indicar el número máximo de abadías que se pueden construir en esa cordillera montañosa.
Sólo se pueden construir abadías en las cimas que sean más altas que todas las montañas que tengan al Este.

Ejemplo
--Entrada--
5 3000 3500 3200 3400 3200
4 4000 3500 3500 3200
0

--Salida--
3
3


*/

#include<iostream>
using namespace std;
const int N = 10;
int main()
{
    int nmontanas;
    cin >> nmontanas;
    while(nmontanas != 0){
        
        int tamanos[N];
        for (int i = 0; i < nmontanas; i++){
            cin >> tamanos[i];
        }
        int nabadias = 1;
        int pico = tamanos[nmontanas - 1];
        for(int i =nmontanas - 1; i > 0; i--){
            if(tamanos[i - 1] > pico){
                pico = tamanos[i -1];
                nabadias++;
            }
                
        }
        cout << nabadias << "\n";
        cin >> nmontanas;
        
    }
    return 0;
}