#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = pair<pii,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

struct range {
  int l, r, i;

  bool operator <(const range& o) const {
    if( l == o.l) return r > o.r;
    return l < o.l;
  }
} a[maxn];

oset<pii> b,c;
int ans[maxn];

int main() {
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; ++i){
    scanf("%d %d", &a[i].l, &a[i].r);
    a[i].i = i;
  }
  sort(a,a+n);
  fill(ans,ans+n,0);
  for(int i=n-1; i>=0; --i){
    ans[a[i].i] = b.order_of_key({a[i].r,INF});
    b.insert({a[i].r,a[i].i});
  }
  for(int i=0; i<n; ++i) printf("%d ",ans[i]);
  printf("\n");
  fill(ans,ans+n,0);
  for(int i=0; i<n; ++i){
    ans[a[i].i] = i - c.order_of_key({a[i].r,-1});
    c.insert({a[i].r,a[i].i});
  }
  for(int i=0; i<n; ++i) printf("%d ",ans[i]);
  printf("\n");  
  return 0;
}
