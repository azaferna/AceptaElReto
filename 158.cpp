/*
 Mario se encuentra ante el castillo final. Puede verlo desde lo alto del muro en el que se encuentra. En breve podrá entrar en la Cámara de Koopa, enfrentarse (y vencer) al monstruo final y salvar a la princesa.
 
 Sin embargo, tiene ante sí una serie de muros que tendrá que sobrepasar. Para eso, saltará desde el primero de ellos, donde se encuentra, al siguiente, y desde él al siguiente, y así sucesivamente hasta llegar al último.
 
 La pregunta que nos hacemos es, ¿cuántos de estos saltos serán hacia arriba y cuántos hacia abajo? Mario realiza un salto hacia arriba cuando
 tiene que alcanzar un muro que está por encima de él, y hacia abajo cuando tiene que alcanzar un muro que está por debajo.
 
 ENTRADA
 El primer valor de la entrada es un número que indica la cantidad de casos de prueba a evaluar. Cada caso de prueba comienza con un entero mayor que cero y no mayor que 109 que indica el número de muros del escenario (recuerda que Mario se encuentra situado en la parte de arriba del primero). A continuación se proporciona la serie de enteros que indican la altura de cada uno de ellos.
 
 SALIDA
 Para cada caso de prueba se mostrará una línea en la que aparecerán dos enteros, uno con los saltos hacia arriba y otro con los saltos hacia abajo, separados por un espacio.
 
 EJEMPLO
 --ENTRADA--
 3
 8
 1 4 2 2 3 5 3 4
 2
 9 9
 5
 1 2 3 4 5
 
 --SALIDA--
 4 2
 0 0
 4 0
*/

#include<iostream>
using namespace std;
int main()
{
    int casos = 0;
        cin >> casos;
    
    
    for(int i = 0; i < casos; i++)
    {
        int nSaltos = 0;
        cin >> nSaltos;
        
        
        int ini = 0;
        int ant = 0;
        int arriba = 0;
        int abajo = 0;
        
        if(nSaltos > 0){
            cin >> ini;
            ant = ini;
        }
        for(int j = 0; j < nSaltos - 1; j++){
            if(ini > ant)
                arriba++;
            else if (ini < ant)
                abajo++;
            
            ant = ini;
            cin >> ini;
        }
        
        if(ini > ant)
            arriba++;
        else if (ini < ant)
            abajo++;
        
        cout << arriba << " " << abajo << "\n";
    
    
    }
   
    return 0;
}