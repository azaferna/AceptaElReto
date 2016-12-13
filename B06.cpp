#include<iostream>
using namespace std;

const int K = 31543;
int recursion(long long n, long long b);

int main()
{
    long long b;
    long long n;
    cin >> b >> n;
    while(n != 0 || b != 0){
        cout << recursion(n, b) << endl;
        cin >> b >> n;
    }
}

int recursion(long long n, long long b){
    if( n == 0)
        return 1;
    int aux = recursion(n/2, b);
    aux = ( aux * aux )% K;
                 
    if(n % 2 == 0)
        return aux;
    else
        return (aux * b) % K;
    
}