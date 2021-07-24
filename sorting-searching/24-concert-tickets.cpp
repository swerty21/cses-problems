#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;

multiset<int> h;

int main() {
  int n,m;
  cin >> n >> m;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    h.insert(-x);
  }
  for(int i=0; i<m; ++i) {
    int x; cin >> x;
    auto it = h.lower_bound(-x);
    if(it!=h.end()){
      cout << -(*it) << endl;
      h.erase(it);
    }else cout << -1 << endl;
  }
  return 0;
}
