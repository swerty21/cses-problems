#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = pair<pii,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

tii a[maxn];
int ans[maxn];

int main() {
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; ++i){
    scanf("%d %d", &a[i].first.first, &a[i].first.second);
    a[i].first.second = -a[i].first.second;
    a[i].second = i;
  }
  sort(a,a+n);
  fill(ans,ans+n,0);
  int min_end = (int)2e9;
  for(int i=n-1; i>=0; --i){
    if(-a[i].first.second >= min_end) ans[a[i].second] = 1;
    min_end = min(min_end,-a[i].first.second);
  }
  for(int i=0; i<n; ++i) printf("%d ",ans[i]);
  printf("\n");
  fill(ans,ans+n,0);
  int max_end = 0;
  for(int i=0; i<n; ++i){
    if(-a[i].first.second <= max_end) ans[a[i].second] = 1;
    max_end = max(max_end,-a[i].first.second);
  }
  for(int i=0; i<n; ++i) printf("%d ",ans[i]);
  printf("\n");  
  return 0;
}
