#include<iostream>
using namespace std;

const int K = 31543;
int eleva(int n, int k);

int main()
{
    long long n;
    int k;
    cin >> n >> k;
    while(n != 0 && k != 0){
        if (k != 0)
            cout << eleva(n % K, k) << endl;
        else
            cout << 1;
        cin >> n >> k;
    }

}
int eleva(int n, int k){

    if(k == 1)
        return n % K;
    else
        return (n * eleva(n, k -1)%K) % K;
}