#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

ll dp[maxn];

ll modinv(ll a, int m){
  int b = m-2;
  ll res = 1;
  while(b > 0){
    if(b&1) res = (res * a)%m;
    a = (a * a)%m;
    b >>= 1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  dp[0] = 1;
  for(int i=1; i<=n; ++i){
    int n1 = i*(i-1)/2;
    for(int j=n1; j>=0; --j){
      dp[j+i] = (dp[j+i] + dp[j])%MOD;
    }
  }
  int total_sum = n*(n+1)/2;
  if(total_sum&1) cout << 0 << endl;
  else cout << (dp[total_sum/2] * modinv(2LL,MOD))%MOD << endl;
  return 0;
}
