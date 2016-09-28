#include<iostream>

using namespace std;


int main()
{
    int in;
    cin >> in;
    
    while(in != 0){
        if(in % 2 == 0 )
            cout << "DERECHA" << endl;
        else
            cout << "IZQUIERDA" << endl;
        cin >> in;
    }
        
    return 0;
}