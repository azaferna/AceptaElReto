#include<iostream>
using namespace std;


bool gana(int acum, int dig);//, int turn);
void calculaValidos(int digito, int validos[]);
int fila(int digito);
int columna(int digito);



const int calc[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int acum, dig;
        cin >> acum >> dig;
        
        if(!gana(acum, dig))
            cout << "GANA"   << endl;
        else
            cout << "PIERDE" << endl;
        
        /*int validos[4];
         calculaValidos(dig, validos);
         for (int x = 0; x < 4; x++)
         cout << validos[x] << endl;
         */
        
    }
}

int fila(int digito){ return ((digito - 1) / 3 ) ; }

int columna(int digito){ return ((digito - 1)) % 3 ; }

void calculaValidos(int digito, int validos[]){
    int f = fila(digito);
    int c = columna(digito);
    int cont = 0;
    
    //Fila
    for(int i = 0; i < 3; i++){
        if(calc[f][i] != digito)
            validos[cont++] = calc[f][i];
    }
    
    //Col
    for(int j = 0; j < 3; j++){
        if(calc[j][c] != digito)
            validos[cont++] = calc[j][c];
    }
}


bool gana(int acum, int dig){//, int turn){
    
    int validos[4];
    calculaValidos(dig, validos);
    
    
    //cout << "Turno: " << turn << " DIG: " << dig << " ACUM: " << acum << endl;
    if(acum >= 31)
        return false;
    
    else{
            bool ok = false;
            if(!gana(acum + validos[0], validos[0]))
                if(!gana(acum + validos[1],  validos[1]))
                    if(!gana(acum + validos[2],  validos[2]))
                        if(!gana(acum + validos[3],  validos[3]))
                            ok = true;
            return ok;
        
    }
} 

