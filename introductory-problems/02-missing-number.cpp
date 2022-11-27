#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x;
    cin >> n;
	vector<bool> f(n+1,false);
	for(int i = 1; i <= n-1; ++i){
		cin >> x;
		f[x] = true;
	}
	for(int i=1; i<=n; ++i){
		if(!f[i]) {
			cout << i;
			break;
		}
	}
	return 0;
}