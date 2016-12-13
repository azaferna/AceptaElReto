#include<iostream>
using namespace std;

const int K = 46337;

typedef struct {
    long long a;
    long long b;
    long long c;
    long long d;
}tMatriz;

tMatriz prod(tMatriz m1, tMatriz m2);
tMatriz eleva();
tMatriz recursion(int n, tMatriz m);

int main()
{
    tMatriz m = eleva();
    int n;
    cin >> n;
    while(n != 0){
        m = eleva();
        m = recursion(n, m);
        cout << m.b << endl;
        cin >> n;
    }

}


tMatriz prod(tMatriz m1, tMatriz m2){
    tMatriz m;
    m.a = (m1.a * m2.a % K + m1.b * m2.c % K) % K;
    m.b = (m1.a * m2.b % K + m1.b * m2.d % K) % K;
    m.c = (m1.c * m2.a % K + m1.d * m2.c % K) % K;
    m.d = (m1.c * m2.b % K + m1.d * m2.d % K) % K;
    
    return m;
}

tMatriz eleva(){
    tMatriz m;
    m.a = 0;
    m.b = 1;
    m.c = 1;
    m.d = 1;
    
    return m;
}

tMatriz recursion(int n, tMatriz m){
    if( n == 0)
        return eleva();
    if(n == 1)
        return eleva();

    tMatriz aux = recursion(n/2, m);
    
    aux = prod(aux, aux);
                 
    if(n % 2 == 0)
        return aux;
    else
        return prod( aux, eleva() );
    
}