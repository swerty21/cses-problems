#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[maxn];
map<int,int> mp;

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) scanf("%d", &a[i]);
  int presum = 0;
  mp[0] = 1;
  for(int i=0; i<n; ++i){
    presum = ((presum+a[i])%n+n)%n;
    mp[presum]++;
  }
  ll ans = 0;
  for(auto e: mp){
    ans += 1LL*(e.second)*(e.second-1)/2;
  }
  cout << ans << endl;
  return 0;
}
