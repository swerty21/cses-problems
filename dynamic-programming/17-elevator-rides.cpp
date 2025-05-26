#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> weight(n);
  for(int i=0; i<n; ++i) cin >> weight[i];
  vector<pii> dp(1<<n,{INF,0});
  dp[0] = {1,0LL};
  for(int mask = 0; mask<(1<<n); ++mask){
    for(int i = 0; i<n; ++i){
      if(mask & (1<<i)) continue;
      int new_mask = mask | (1<<i);
      auto [r,w] = dp[mask];
      if(w + weight[i] <= x){
        dp[new_mask] = min(dp[new_mask],{r, w+weight[i]});
      }else{
        dp[new_mask] = min(dp[new_mask],{r+1, weight[i]});
      }
    }
  }
  cout << dp[(1<<n)-1].first << endl;
  return 0;
}
