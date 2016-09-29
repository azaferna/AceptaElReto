/*
Enunciado
Es conocida la afición existente entre los universitarios españoles al mus, un juego de cartas para cuatro personas con más de 200 años 
de historia que también es muy jugado en algunos países de Hispanoamérica e incluso en algunas regiones del sur de Francia.
Cuando esos españoles consiguen una beca erasmus para estudiar durante unos meses en otro país de Europa, es fácil entender,
pues, que no falte una baraja de cartas entre su equipaje, por lo que pueda ocurrir. En su afán de evangelización muchos de 
estos estudiantes de erasmus intentan que el juego se extienda, y se empeñan en explicar las reglas a sus compañeros de otros países.
Como a buen seguro sabrás, al mus se juega por parejas, de forma que una pareja de jugadores se enfrenta a otra. Desgraciadamente,
a la hora de hacer esas parejas la mayoría de las veces los españoles "se buscan" entre sí, de forma que las partidas terminan 
siendo competiciones entre países (juegan dos españoles contra dos italianos, por ejemplo).
En esta ocasión, sin embargo, un grupo de estudiantes de erasmus se ha propuesto formar parejas heterogéneas, por lo que no 
van a aceptar parejas cuyos dos componentes sean de la misma nacionalidad. A la vista de cuántos estudiantes hay de cada país, 
¿cuántas parejas distintas pueden formarse?

Entrada 
La entrada estará compuesta por varios casos de prueba terminados con una línea con un 0.
Cada caso de prueba tendrá dos líneas. En la primera aparecerá un único entero que indica el número de países totales representados 
(un número entre 1 y 100.000). La segunda línea contendrá un número por cada país, representando la cantidad de estudiantes de ese país
que quieren jugar al mus. El número de estudiantes de cada país no excederá nunca 10^9.

Salida
Por cada caso de prueba, el programa escribirá el número de parejas distintas que pueden formarse sin que una pareja tenga a sus dos 
integrantes de la misma nacionalidad. Se garantiza que la respuesta no será nunca superior a 10^18.

Ejemplo
--Entrada--
2
1 1
2
2 2
3
2 2 1
0


--Salida--
1
4
8


*/#include<iostream>
using namespace std;
const int N = 100000;
int main()
{
    int casos;
    cin >> casos;
    while(casos != 0){
        long long elementos  = 0; //Ojo con el long en el enunciado dice que cada pais puede tener 10^9 partcipantes
        long long parejas = 0; //Ojo con el long en el enunciado dice que pueden formarse hasta 10^18 parejas
        int pais[N];
        for (int i = 0; i < casos; i++){
            cin >> pais[i];
            elementos += pais[i];
        }
        
        for(int i = 0; i < casos; i++){
            elementos -= pais[i];
            parejas += pais[i]*elementos;
        }
        cout << parejas << "\n";
        cin >> casos;
        
    }
    return 0;
}