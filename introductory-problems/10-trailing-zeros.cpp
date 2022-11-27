#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = (int)1e9 + 7;

int main() {
	int n, ans = 0;
	cin >> n;
    while(n>1){
        ans += (n/5);
        n /= 5;
    }
    cout << ans << endl;
	return 0;
}