#include<iostream>
#include<string>
using namespace std;


void ramaC(int nC, int nV, string comb, string& combF);
void ramaV(int nC, int nV, string comb, string& combF);

int main()
{
    int nCasos;
    cin >> nCasos;
    for(int i = 0; i < nCasos; i++){
        int nC, nV;
        cin >> nC >> nV;
        
            string comb = "";
            string combF = "";
        ramaC(nC, nV, comb, combF);
        ramaV(nC, nV, comb, combF);
        
        //cout << comb.size();
        combF.erase(combF.size() - 1);
        cout << combF <<endl;
    }
}



void ramaC(int nC, int nV, string comb, string& combF){
   
    comb += "C";
     nC--;
    if(nC > 0)
        ramaC(nC, nV, comb, combF);
    if(nV > 0)
        ramaV(nC, nV, comb, combF);
    if(nC == 0 && nV == 0)
        combF += comb + " ";
}

void ramaV(int nC, int nV, string comb, string& combF){
    comb += "V";
    nV--;
    
    if(nC > 0)
        ramaC(nC, nV, comb, combF);
    if(nV > 0)
        ramaV(nC, nV, comb, combF);
    if(nC == 0 && nV == 0)
        combF += comb + " ";
}