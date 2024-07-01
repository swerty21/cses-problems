#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

pair<ll,ll> dp[5005][5005];
ll a[5005];

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) cin >> a[i];
  for(int i=0; i<n; ++i){
    dp[i][i] = {a[i],0LL};
  }
  for(int l=2; l<=n; ++l){
    for(int i=0; i+l-1<n; ++i){
      int j = i+l-1;
      dp[i][j].first = max(a[i] + dp[i+1][j].second, a[j] + dp[i][j-1].second);
      dp[i][j].second = min(dp[i+1][j].first, dp[i][j-1].first);
    }
  }
  cout << dp[0][n-1].first << endl;
  return 0;
}
