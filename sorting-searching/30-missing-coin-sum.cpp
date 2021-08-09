#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;

int x[maxn];

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) cin >> x[i];
  sort(x,x+n);
  ll ans = 1;
  for(int i=0; i<n; ++i){
    if(x[i]>ans) break;
    ans+=x[i];
  }
  cout << ans << endl;
  return 0;
}
