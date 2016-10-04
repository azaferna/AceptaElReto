/*
 Un buen corredor de San Fermines intenta mantener la emoción para fomentar el espectáculo. Este tipo de corredores está muy en forma y son capaces de correr mucho más deprisa que los toros. Sin embargo, para mantener la emoción, no lo hacen. Se limitan a mantener una velocidad adecuada para que los toros se mantenga siempre cerca, pero no lleguen a pillarles.
 
 El problema consiste en, dadas las velocidades de todos los toros que participan en los San Fermines (y que se suponen constantes), ¿a qué velocidad deben ir estos corredores expertos para mantener el espectáculo conservando su integridad?
 
 ENTRADA
 La entrada consta de una serie de casos de prueba, cada uno en una línea. El primer número de la misma indica el número de toros que intervienen en la carrera (n ≥ 1). A continuación aparece un entero por cada uno de los toros, indicando la velocidad a la que correrá ese toro (recuerda, es velocidad constante). La velocidad es siempre positiva y no excede 10^9.
 SALIDA
 Para cada caso de prueba se mostrará una línea en la que aparecerá la velocidad a la que deberán ir los corredores expertos para mantener el espectáculo.
 
 EJEMPLO
 --ENTRADA--
 7 1 9 8 7 10 3 12
 1 10
 --SALIDA
 12
 10
 */

#include<iostream>
using namespace std;
int main()
{
    long int casos;
    long int max = 0;
    long int dato;
    bool ok = true;
    
    cin >> casos;
    while(cin){
      
        for(int i = 0; i< casos; i++){
            cin >> dato;
            if(dato > max)
                max = dato;
            else
                ok = false;
        }
        cout << max << "\n";
        max = 0;
        cin >> casos;
    }
    
    return 0;
}

