#include<iostream>
#include<fstream>
using namespace std;

const int N = 1000000;
int cuenta(int v[], int n, int t);
int suma(int v[], int n);


int main()
{
    int v[N];
    int n = 0;
    
    cin >> n;
    while(n != 0){
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        cout << cuenta(v, n,  suma(v, n)) << "\n";
        cin >> n;
    }
    return 0;
    
}


/*
 Pre = (n >0)
 I= {(0 <= i <= N) && t = (sum j : 0 <= j < i : v[j])}
 Post = sum: 0 <= i < n : v[i]
 cota  = {(n - i) = 0}
 */
int suma(int v[], int n){
    int t= 0;
    for(int i = 0; i < n; i++){
        t += v[i];
    }
    return t;

}

/*
    pre = ((n > 0) && t = suma(v[], n))
    int cuenta (int v[], int n, int t) return r;
    r = {#k : 0<= k < n; suma(v[], k) == t - suma(v[], k)
     */

int cuenta(int v[], int n, int t){
    int k = 0;//empezamos a recorrer desde 0
    int i = v[0];// en izq cargamos el primer valor del vector
    int d = t - i;// en derecha cargamos el valor de la suma de todos los siguientes
    int cuenta = 0;
    
    if(t == 0)
        cuenta = 2;
    
    while (k < (n - 1)){
        d   = t - i;
        if(d == i)
            cuenta++;
        
        
        ++k;
        i += v[k];
    }
    return cuenta;
}
