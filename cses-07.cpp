#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> ans(10001);

int main() {
    ans[1] = 0, ans[2] = 6, ans[3] = 28, ans[4] = 96, ans[5] = 252;
    for(int i=6; i<=10000; ++i){
        ans[i] = (1LL)*i*i*(i*i-1) - (2*4 + 3*8 + 4*4*(i-4) + 4*4 + 6*4*(i-4) + 8*(i-4)*(i-4));
        ans[i] /= 2;
    }
	int n;
	cin >> n;
    for(int i=1; i<=n; ++i) cout << ans[i] << endl;
	return 0;
}