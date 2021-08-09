#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;

int p[maxn];

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) cin >> p[i];
  sort(p,p+n);
  int ref = p[n/2];
  ll ans = 0;
  for(int i=0; i<n; ++i){
    ans += abs(ref-p[i]);
  }
  cout << ans << endl;
  return 0;
}
