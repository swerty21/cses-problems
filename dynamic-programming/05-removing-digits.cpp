#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e6+10;
const int INF = (int)2e9;

int dp[maxn];
int coins[110];

int main() {
  int n;
  cin >> n;
  fill(dp,dp+n+1,INF);
  dp[0]=0;
  for(int i=1; i<=n; ++i){
    vector<int> digits;
    int num = i;
    while(num>0) {
      digits.push_back(num%10);
      num /= 10;
    }
    for(auto &e: digits) {
      dp[i] = min(dp[i],dp[i-e] +1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
