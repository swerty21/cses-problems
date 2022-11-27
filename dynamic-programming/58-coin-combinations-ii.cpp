#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e6+10;
const int INF = (int)2e9;


int dp[110][maxn];
int coins[110];

int main() {
  int n,x;
  cin >> n >> x;
  for(int i=0; i<n; ++i){
    cin >> coins[i];
  }
  dp[0][0] = 1;
  for(int c=1; c<=n; ++c){
    for(int i=0; i<=x; ++i){
      dp[c][i] = dp[c-1][i];
      if(i >= coins[c-1])
      dp[c][i] = (dp[c][i] + dp[c][i - coins[c-1]])%MOD;
    }
  }
  cout << dp[n][x] << endl;
  return 0;
}
