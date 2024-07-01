#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e6+10;
const int INF = (int)2e9;

int dp[1010][1010];
string mx[1010];

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) cin >> mx[i];
  if(mx[0][0]=='*') {
  	cout << 0 << endl;
  	return 0;
  }
  dp[0][0] = 1;
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      if(mx[i][j]=='*') continue;
      if(i>0 and mx[i-1][j]=='.') dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
      if(j>0 and mx[i][j-1]=='.') dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
    }
  }
  cout << dp[n-1][n-1] << endl;
  return 0;
}
