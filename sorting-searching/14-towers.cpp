#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[maxn];
multiset<int> tower;

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    auto it = tower.upper_bound(x);
    if(it != tower.end()){
      tower.erase(it);
      tower.insert(x);
    }else{
      tower.insert(x);
    }
  }
  cout << (int)tower.size() << endl;
  return 0;
}
