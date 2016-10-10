#include<iostream>
using namespace std;

int nPicos(int v[], int n);
int nValles(int v[], int n);

int main()
{
    const int N = 10000;
    int casos;
    int v[N];
    cin >> casos;
    for (int i = 0; i < casos; i ++)
    {
        int ndatos;
        cin >> ndatos;
        for(int j = 0; j < ndatos; j++){
            cin >> v[j];
        }
        
        cout << nPicos(v, ndatos) << " " << nValles(v, ndatos) << "\n";
        
    }
    
    return 0;
}


    //PRE  = { 0 < n  <= 10000}
    int nPicos(int v[], int n){
        int picos = 0;
        for(int j = 1; j < n - 1; j++){
            
            if(v[j - 1] < v[j] && v[j + 1] < v[j])
                picos++;
        }
        
        return picos;
    }
    //POST  = {picos = (#j : 1 <= j < n - 1 : v[j - 1] < v[j] > v[j+1] )}
    

    //PRE  = { 0 < n  <= 10000}
    int nValles(int v[], int n){
        int valles = 0;
        for(int j = 1; j < n - 1; j++){
            
            if(v[j - 1] > v[j] && v[j + 1] > v[j])
                valles++;
        }
        return valles;
    }
    //POST  = {valles = (#j : 1 <= j < n - 1: v[j - 1] > v[j] < v[j+1] )}
    
