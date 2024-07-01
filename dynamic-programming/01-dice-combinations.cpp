#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e6+10;
const int INF = (int)2e9;


ll dp[maxn];

int main() {
  int n;
  cin >> n;
  dp[0] = 1;
  for(int i=1; i<=n; ++i){
    dp[i] = 0;
    for(int j=1; j<=min(i,6); ++j){
      dp[i] = (dp[i] + dp[i-j])%MOD;
    }
  }
  cout << dp[n] << endl;
  return 0;
}
