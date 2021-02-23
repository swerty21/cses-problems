#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,c;
	cin >> n;
	vector<int> ans(n);
	if (n==1) cout << 1 <<endl;
	else if(n<4) cout << "NO SOLUTION";
	else{
		c = 1;
		for(int i=1; i<n; i+=2){
			ans[i] = c;
			c++;
		}
		for(int i=0; i<n; i+=2){
			ans[i] = c;
			c++;
		}
		for(int i=0; i<n; ++i) cout << ans[i] << " ";
	}
	return 0;
}