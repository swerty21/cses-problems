#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;

map<int,int> mp;

int main() {
  int n,x;
  cin >> n >> x;
  int ans1, ans2;
  bool found = false;
  for(int i=0; i<n; ++i) {
    int a; cin >> a;
    if(mp.count(x-a)>0){
      ans1 = mp[x-a]+1;
      ans2 = i+1;
      found = true;
    }
    mp[a] = i;
  }
  if(found) cout << ans1 << " " << ans2 << endl;
  else cout << "IMPOSSIBLE";
  return 0;
}
