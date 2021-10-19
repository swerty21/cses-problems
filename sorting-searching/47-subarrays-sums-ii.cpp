#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[maxn];
map<ll,int> mp;

int main() {
  int n,x;
  cin >> n >> x;
  for(int i=0; i<n; ++i) scanf("%d", &a[i]);
  ll presum = 0, ans = 0;
  mp[0] = 1;
  for(int i=0; i<n; ++i){
    presum += a[i];
    if(mp.count(presum-x)>0) ans+=mp[presum-x];
    mp[presum]++;
  }
  cout << ans << endl;
  return 0;
}
