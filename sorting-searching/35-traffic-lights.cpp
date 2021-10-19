#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[maxn],ans[maxn];
set<int> lights;

int main() {
  int x, n;
  scanf("%d %d",&x,&n);
  for(int i=0; i<n; ++i){
    scanf("%d", &a[i]);
    lights.insert(a[i]);
  }
  lights.insert(0);
  lights.insert(x);
  ans[n-1] = 0;
  int prev = 0;
  for(auto e: lights){
    ans[n-1] = max(ans[n-1], e-prev);
    prev = e;
  }
  for(int i=n-2; i>=0; --i){
    auto it = lights.find(a[i+1]);
    auto it1 = it;
    it1--;
    auto it2 = it;
    it2++;
    ans[i] = max(ans[i+1],*it2-*it1);
    lights.erase(it);
  }
  for(int i=0; i<n; ++i) printf("%d ", ans[i]);
  return 0;
}
