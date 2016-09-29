/*
Enunciado
Tu primo Luis, de 12 años, está aprendiendo a usar la calculadora. Su profesor le ha dicho que calcule el factorial de varios números. Pero, para evitar que le tengan que copiar números muy largos en el cuaderno, les ha pedido únicamente el último dígito, el de más a la derecha.
Recordando que el factorial es la multiplicación de todos los números entre el número y el uno (por ejemplo, el factorial de 8, escrito 8!, 
es 8 · 7 · 6 · 5 · 4 · 3 · 2 · 1), demuestra a tu primo Luis que tú eres capaz de hacerlo mucho más rápido que él.



Entrada 
El programa recibirá en la primera línea de la entrada el número de casos de prueba. A continuación, cada caso de prueba estará compuesto de una única línea que contendrá un número (positivo).

Salida
Por cada caso de prueba n, se mostrará el último dígito (el de la derecha) de su factorial, n!.

Ejemplo
--Entrada--
3
2
3
4

--Salida--
2
6
4

*/

#include<iostream>
using namespace std;
int main()
{
    int casos;
    int fact = 0;
    int total = 1;
    cin >> casos;

    for(int i = 0; i < casos; i++){
        total = 1;
        cin >> fact;
        if(fact == 0)
            cout << 1 << "\n";
        if(fact == 1)
            cout << 1 << "\n";
        if(fact == 2)
            cout << 2 << "\n";
        if(fact == 3)
            cout << 6 << "\n";
        if(fact == 4)
            cout << 4 << "\n";
        if(fact >= 5 ) // A partir del cinco el resultado siempre es 0
            cout << 0 << "\n";
    }
    return 0;
}