#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = (int)1e9 + 7;

int main() {
	int n;
    cin >> n;
    for(int i=0; i<(1<<n); ++i){
    	int ngray = i^(i>>1);
    	for(int j=n-1; j>=0; --j) {
    		int b = (ngray&(1<<j))>>j;
    		cout << b ;
    	}
        cout << endl;
    }
	return 0;
}