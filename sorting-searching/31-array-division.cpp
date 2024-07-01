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

bool check(ll maxsum, int n, int k){
  int groups = 0;
  ll curr = 0;
  for(int i=0; i<n; ++i){
    if(a[i] > maxsum) return false;
    if(curr + a[i] > maxsum){
      groups++;
      curr = 0;
    }
    curr += a[i];
  }
  if(curr > 0) groups++;
  return (groups <= k);
}

int main() {
  int n,k;
  cin >> n >> k;
  for(int i=0; i<n; ++i) scanf("%d", &a[i]);
  ll left = 0, right = (ll)1e18;
  ll ans = 0;
  while(left <= right){
    ll mid = (left + right) >> 1;
    if(check(mid,n,k)) {
      right = mid-1;
      ans = mid;
    }
    else left = mid+1;
  }
  cout << ans << endl;
  return 0;
}
