#include<iostream>
#include<string>
using namespace std;


int main()
{
    int numero;
    int suma = 0;
    string s;
    cin >> numero;
  
    while(numero >= 0){
        suma = 0;
         s= "";
        if (numero < 10){
            suma = numero;
            cout << numero << " = " << suma << endl;
        }
        else{
            while (numero != 0){
            
                s = to_string(numero % 10) + s ;
                suma = suma + numero%10;
                numero = numero /10;
                if(numero != 0)
                    s = " + " + s;
            }
            
            cout << s << " = " << suma << endl;
        }
        cin >> numero;
        
    }
    return 0;
}