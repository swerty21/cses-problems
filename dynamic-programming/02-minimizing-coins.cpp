#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e6+10;
const int INF = (int)2e9;


ll dp[maxn];
int coins[maxn];

int main() {
  int n,x;
  cin >> n >> x;
  for(int i=0; i<n; ++i){
    cin >> coins[i];
  }
  for(int i=0; i<=1e6; ++i) dp[i] = INF;
  dp[0] = 0;
  for(int i=0; i<=x; ++i){
    for(int c=0; c<n ; ++c){
      if(coins[c] > i) continue;
      dp[i] = min(dp[i],1+dp[i-coins[c]]);
    }
  }
  if(dp[x]==INF) cout << -1 << endl;
  else cout << dp[x] << endl;
  return 0;
}
