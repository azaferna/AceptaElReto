#include<iostream>
#include<fstream>
using namespace std;

//const int N = 1000000;
int nNinos(int n);

int main()
{
    int n = 0;
    
    cin >> n;
    while(n != 0){
        cout << nNinos(n) << "\n";
        
        cin >> n;
    }
    return 0;
    
}


int nNinos (int n){
    int i = 0; // 1?
    int ninos = 0;
    int acum = 0;
    int dato;
    cin >> dato;
    int maxMin = dato;
    int max= maxMin;
    
    // cout << "maxMin | max | acum | ninos | dato " << endl;
    while( i < n){
        
        if( dato <= maxMin){
            ninos = i + 1;
            maxMin = max;
        }
        else if(dato > max){//maxMin
            max = dato;
        }
        //  cout << "  " << maxMin << "       " << max << "      " << acum << "      " << ninos << "      " << dato << endl;
        i++;
        if(i < n)
            cin >> dato;
    }
    
    
    return ninos;
}