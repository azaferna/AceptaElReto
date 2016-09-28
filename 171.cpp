#include<iostream>
using namespace std;
const int N = 10;
int main()
{
    int nmontanas;
    cin >> nmontanas;
    while(nmontanas != 0){
        
        int tamanos[N];
        for (int i = 0; i < nmontanas; i++){
            cin >> tamanos[i];
        }
        int nabadias = 1;
        int pico = tamanos[nmontanas - 1];
        for(int i =nmontanas - 1; i > 0; i--){
            if(tamanos[i - 1] > pico){
                pico = tamanos[i -1];
                nabadias++;
            }
                
        }
        cout << nabadias << "\n";
        cin >> nmontanas;
        
    }
    return 0;
}