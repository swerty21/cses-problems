#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set st;
int a[maxn];

int main() {
  int n,k;
  cin >> n >> k;
  for(int i=0; i<n; ++i) scanf("%d", &a[i]);
  for(int i=0; i<n; ++i){
    st.insert({a[i],i});
    if(i >= k){
      st.erase(st.lower_bound({a[i - k], 0}));
    }
    if(i >= k-1){
      printf("%d ", (*st.find_by_order((k - 1) / 2)).first);
    }
  }
  return 0;
}
