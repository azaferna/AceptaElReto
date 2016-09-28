/*
Enunciado
Es bien sabido que los monjes, en las abadías, se levantan muy temprano para rezar durante maitines, observando la salida del sol.
La localización de las abadías y monasterios es por tanto de vital importancia para que se pueda observar el sol aparecer en el horizonte. 
Los monjes prefieren las localizaciones que no tengan montañas altas hacia el Este, que les impedirían ver salir el sol.
Esto es un problema especial en los Pirineos, la cordillera montañosa que va de Oeste a Este y separa la Península Ibérica del resto del 
continente europeo. Los Pirineos están llenos de lugares tranquilos y mágicos, por lo que son emblemáticos para la meditación y el rezo. 
Pero al estar orientados de Oeste a Este, tienen una limitación en el número de localizaciones candidatas a construir abadías, es decir las que 
reciben el sol en los primeros momentos de la mañana. Este problema lo sufren también otras cordilleras en todo el mundo.
Cuando necesitamos llegar a una dirección específica, es útil conocer la manera en la que las casas se numeran dentro de una calle para no perder
demasiado tiempo buscando. Dependiendo de las reglas urbanísticas de cada lugar, esa numeración seguirá unas reglas u otras. En Japón, por ejemplo,
los números se asignan por orden de construcción de los edificios, lo que no es algo particularmente amigable para un despistado turista.
En la mayoría de las ciudades y pueblos de Europa, sin embargo, se utiliza un mecanismo que facilita la búsqueda, aunque dificulta los cambios si se construyen o derrumban edificios. En concreto, se elige uno de los extremos como el inicio de la calle, utilizándose normalmente como criterio aquél que esté más cerca de un punto significativo de la ciudad (el centro urbano, el ayuntamiento, un río, el mar…). Una vez hecho eso, las viviendas que quedan al lado izquierdo (respecto al punto inicial) reciben números impares consecutivos, y las que quedan al lado derecho números pares consecutivos. Dependiendo del tamaño de cada edificio, a menudo ocurre que los números se descompensan y hay portales que tienen enfrente otros con números muy diferentes.


Entrada 
El programa recibirá, por la entrada estándar, un conjunto de casos de prueba, cada uno en una línea. Cada caso de prueba estará compuesto
de un número de vivienda. Se garantiza que nunca será mayor que 1.000.
El último caso, que no deberá procesarse, será el número 0.


Salida
Para cada caso de prueba el programa escribirá "IZQUIERDA" (sin las comillas) si la vivienda está situada a la izquierda de la calle, 
y "DERECHA" si está a la derecha.

Ejemplo
--Entrada--
3
10
41
0

--Salida--
IZQUIERDA
DERECHA
IZQUIERDA


*/#include<iostream>

using namespace std;


int main()
{
    int in;
    cin >> in;
    
    while(in != 0){
        if(in % 2 == 0 )
            cout << "DERECHA" << endl;
        else
            cout << "IZQUIERDA" << endl;
        cin >> in;
    }
        
    return 0;
}