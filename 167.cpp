#include<iostream>

int fractales(int n);
int main()
{
    int n = 0;
    std :: cin >> n;
    while(std :: cin){
        std :: cout << fractales(n) << "\n";
        std :: cin >> n;
    }
    return 0;

}

int fractales(int n){
    if(n == 1)
        return 4;
    else
        return 4*n + 4*fractales(n/2);
}