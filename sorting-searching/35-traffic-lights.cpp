#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[maxn];
set<int> lights;
multiset<int> pass_lens;

int main() {
  int x, n;
  scanf("%d %d",&x,&n);
  lights.insert(0);
  lights.insert(x);
  pass_lens.insert(x);
  for(int i=0; i<n; ++i) {
    int v; cin >> v;
    auto itend = lights.upper_bound(v);
    auto itbegin = itend;
    itbegin--;
    int oldlen = *itend - *itbegin;
    //cout << oldlen << endl;
    int len1 = (*itend - v), len2 = (v - *itbegin);
    //cout << len1 << " " << len2 << endl;
    lights.insert(v);
    auto jlen = pass_lens.lower_bound(oldlen);
    pass_lens.erase(jlen);
    pass_lens.insert(len1);
    pass_lens.insert(len2);
    printf("%d ",*pass_lens.rbegin());
  }
  return 0;
}
