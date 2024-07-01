#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e6+10;
const int INF = (int)2e9;

int dp[505][505];

int main() {
  int a,b;
  cin >> a >> b;
  if(b>a) swap(a,b);
  for(int i=0; i<=a+1; ++i){
    fill(dp[i],dp[i]+a+1+1,INF);
  }
  for(int i=0; i<=a; ++i) dp[i][i] = 0;
  for(int l1=1; l1<=a; ++l1){
    for(int l2=1; l2<=a; ++l2){
      if(dp[l1][l2] != INF) continue;
      for(int i=1; i<l1; ++i){
        dp[l1][l2] = min(dp[l1][l2], 1 + dp[i][l2] + dp[l1-i][l2]);
      }
      for(int i=1; i<l2; ++i){
        dp[l1][l2] = min(dp[l1][l2], 1 + dp[l1][i] + dp[l1][l2-i]);
      }
      dp[l2][l1] = dp[l1][l2];
    }
  }
  cout << dp[a][b] << endl;
  return 0;
}
