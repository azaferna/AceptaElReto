#include<iostream>
using namespace std;

int pajaritas(int x, int y);

int main()
{

    int x = 0, y = 0;
    
    cin >> x >> y;
    
    while( x != 0 && y != 0){
        cout << pajaritas(x, y) << endl;
        cin >> x >> y;
    }

}

int pajaritas(int x, int y){
    
    if((x < 10) || (y < 10))
        return 0;
    
    else if  ( x == y )
       return 1;
    else{
        if(x > y)
            return pajaritas(x%y, y) + x/y;
        else
            return pajaritas(x,y%x) + y/x;
    }
}

