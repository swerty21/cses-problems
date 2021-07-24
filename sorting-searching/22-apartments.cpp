#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;

int a[maxn], b[maxn];

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=0; i<n; ++i) cin >> a[i];
  for(int i=0; i<m; ++i) cin >> b[i];
  sort(a,a+n);
  sort(b,b+m);
  int ans=0, j=0;
  for(int i=0; i<n; ++i){
    for(; b[j]<a[i]-k and j<m; ++j);
    if(j<m and b[j]<=a[i]+k) {
      j++;
      ans++;
    }
  }
  cout << ans;
  return 0;
}
