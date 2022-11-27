#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	while(n!=1){
		cout << n << " ";
		if(n%2==1) n = n*3+1;
		else n >>= 1;
	}
	cout << n;
	return 0;
}

//comentario añadido 26/11/2022