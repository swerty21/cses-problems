#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e5+10;
const int INF = (int)2e9;

int dp[maxn];

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> p(n+1), a(n+1);
  for(int i=1; i<=n; ++i) cin >> p[i];
  for(int i=1; i<=n; ++i) cin >> a[i];
  fill(dp,dp+x+1,0);
  for(int i=1; i<=n; ++i){
    for(int xi = x; xi >= 0; --xi){
      if(xi >= p[i]) dp[xi] = max(dp[xi], a[i] + dp[xi - p[i]]);
    }
  }
  cout << dp[x] << endl;
  return 0;
}
