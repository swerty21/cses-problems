#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e6+10;
const int INF = (int)2e9;

int dp[5005][5005];

int main() {
  string s1,s2;
  cin >> s1 >> s2;
  int n1 = s1.size();
  int n2 = s2.size();
  for(int i=0; i<5005; ++i) {
    for(int j=0; j<5005; ++j){
      if(i==0 || j==0){
        dp[0][i] = i;
        dp[i][0] = i;
      }else{
        dp[i][j] = INF;
      }
    }
  }
  for(int i=1; i<=n1; ++i){
    for(int j=1; j<=n2; ++j){
      if(s1[i-1]==s2[j-1]){
        dp[i][j] = dp[i-1][j-1];
      }else{
        dp[i][j] = min(dp[i][j],1+dp[i][j-1]);
        dp[i][j] = min(dp[i][j],1+dp[i-1][j]);
        dp[i][j] = min(dp[i][j],1+dp[i-1][j-1]);
      }
    }
  }
  cout << dp[n1][n2] << endl;
  return 0;
}
