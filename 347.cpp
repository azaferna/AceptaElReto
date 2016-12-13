
#include<iostream>
using namespace std;

int meteLasBolas(int desde, int hasta, int n);

int main()
{
    int z;
    cin >> z;
    
    while (cin) {
       if(z >0)
        cout << meteLasBolas(0, z, 1) << endl;
        else
            cout << 0 << endl;
        
        cin >> z;
    }

}

int meteLasBolas(int desde, int hasta, int n){
    int cuantas = (desde + hasta) /2;
    if(cuantas >= 1){
        n = meteLasBolas(desde, (desde + hasta)/2, n);
        return n +1;
    }
    else
        return 1;
}