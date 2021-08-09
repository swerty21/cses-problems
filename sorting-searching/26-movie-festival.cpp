#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;

pii t[maxn];

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) {
    int a,b; cin >> a >> b;
    t[i] = {b,a};
  }
  sort(t,t+n);
  int ans = 0, curr_end = 0;
  for(int i=0; i<n; ++i){
    if(t[i].second >= curr_end) {
      ans++;
      curr_end = t[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}
