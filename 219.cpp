#include <iostream>
using namespace std;

int main(){

	int casos = 0;
	cin >> casos;
	
	for(int i = 0; i < casos; i++){
		int decimos = 0;
		int validos  = 0;
		cin >> decimos;
		for(int j = 0; j < decimos; j++){
			int dato;
			cin >> dato;
			if(dato%2  == 0)
				validos++;
		}
		cout << validos << "\n";
	}
	
	return 0;
}