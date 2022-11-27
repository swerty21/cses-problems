#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

pii a[maxn];
multiset<ll> endtimes;
int ans = 0;

int main() {
  int n,k;
  cin >> n >> k;
  for(int i=0; i<n; ++i) scanf("%d %d", &a[i].second, &a[i].first);
  sort(a,a+n);
  for(int i=0; i<k; ++i) endtimes.insert(0);
  for(int i=0; i<n; ++i) {
    auto it = endtimes.lower_bound(-a[i].second);
    if(it == endtimes.end()) continue;
    endtimes.erase(it);
    endtimes.insert(-a[i].first);
    ans++;
  }
  cout << ans;
  return 0;
}
