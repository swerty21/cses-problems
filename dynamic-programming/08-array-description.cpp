#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e5+10;
const int INF = (int)2e9;

ll dp[maxn][105];

bool inlimits(int v, int m){
  return v >= 1 and v <= m;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];
  if(a[0] != 0){
    dp[0][a[0]] = 1;
  }else{
    for(int i=1; i<=m; ++i) dp[0][i] = 1;
  }
  for(int i=1; i<n; ++i){
    if(a[i] != 0){
      for(int v = a[i]-1; v <= a[i]+1; ++v){
        if(inlimits(v,m)) {
          dp[i][a[i]] += dp[i-1][v];
          dp[i][a[i]] %= MOD; 
        }
      }
    }
    else{
      for(int j=1; j<=m; ++j){
        for(int v=j-1; v <= j+1; ++v){
          if(inlimits(v,m)){
            dp[i][j] += dp[i-1][v];
            dp[i][j] %= MOD;
          }
        }
      }
    }
  }
  ll ans = 0L;
  for(int i=1; i<=m; ++i){
    ans += dp[n-1][i];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
