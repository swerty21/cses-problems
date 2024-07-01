#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = pair<pii,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[maxn];

int main() {
  int n; ll t;
  scanf("%d %lld", &n, &t);
  for(int i=0; i<n; ++i) scanf("%d",&a[i]);
  ll low = (t+n-1) / n * *min_element(a,a+n);
  ll high = (t+n-1) / n * *max_element(a,a+n);
  while (low<high){
    ll mid = (low + high) >> 1;
    ll created = 0;
    for(int i=0; i<n; ++i) created += mid/a[i];
    if(created < t) low = mid+1;
    else high = mid;
  }
  printf("%lld\n", low);
  return 0;
}
