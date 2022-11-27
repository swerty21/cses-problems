#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;


ll x[maxn], presum[maxn];
multiset<ll> window;
ll ans = -2e18;

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  for(int i=1; i<=n; ++i) scanf("%lld", &x[i]);
  presum[0] = 0;
  for(int i=1; i<=n; ++i) presum[i] = presum[i-1] + x[i];
  for(int i=a; i<=n; ++i){
    window.insert(presum[i-a]);
    if(i>b) window.erase(window.find(presum[i-b-1]));
    ans = max(ans,presum[i] - *window.begin());
  }
  cout << ans;
  return 0;
}
