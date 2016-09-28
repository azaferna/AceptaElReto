#include<iostream>
using namespace std;
const int N = 100000;
int main()
{
    int casos;
    cin >> casos;
    while(casos != 0){
        long long elementos  = 0;
        long long parejas = 0;
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