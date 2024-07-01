#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e6+10;
const int INF = (int)2e9;

ll dp[maxn][2];

int main() {
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i=1; i<n; ++i){
      dp[i][0] = (dp[i-1][0]*2 + dp[i-1][1])%MOD;
      dp[i][1] = (dp[i-1][1]*4 + dp[i-1][0])%MOD;
    }
    ll ans = (dp[n-1][0] + dp[n-1][1]) % MOD;
    cout << ans << endl;
  }
  return 0;
}
