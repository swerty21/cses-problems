#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = (int)1e9 + 7;

int main() {
	int n;
    ll ans = 1;
	cin >> n;
    for(int i=1; i<=n; ++i){
        ans = (ans<<1)%MOD;
    }
    cout << ans << endl;
	return 0;
}