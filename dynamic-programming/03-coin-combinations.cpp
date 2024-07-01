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
  dp[0] = 1;
  for(int i=0; i<=x; ++i){
    for(int c=0; c<n ; ++c){
      if(coins[c] > i) continue;
      dp[i] = ( dp[i] + dp[i-coins[c]] ) % MOD;
    }
  }
  cout << dp[x] << endl;
  return 0;
}
