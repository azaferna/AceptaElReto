//221

#include<iostream>
using namespace std;
int main()
{
    int casos;
    
    cin >> casos;
    for (int i = 0; i < casos; i ++)
    {
        int fila = 0;
        bool par = false;
        bool correcto = true;
        int butacas = 0;
        cin >> butacas;
        for (int j = 0; j < butacas; j ++)
        {
            int x;
            cin >> x;
            if(x%2 == 0 && !par)
                fila ++;
            if(x%2 == 0 && par)
                correcto = false;
            if(x%2 != 0 && !par )
                par = true;
        }
        if(correcto)
            cout << "SI " << fila<<"\n";
        else{cout << "NO\n";}
        
        
    }
    return 0;
}