#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = pair<pii,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int main() {
  int n;
  cin >> n; 
  ll n_max = 0, sum_n = 0;
  for(int i=0; i<n; ++i) {
    ll x;
    cin >> x;
    sum_n += x;
    n_max = max(n_max,x);
  }
  if(n_max > (sum_n >> 1)) cout << n_max * 2 << endl;
  else cout << sum_n << endl;
  return 0;
}
