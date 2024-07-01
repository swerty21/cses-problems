#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;

int p[maxn];

int main() {
  int n,x;
  cin >> n >> x;
  for(int i=0; i<n; ++i) cin >> p[i];
  sort(p,p+n);
  int i=0, ans = 0;
  for(int j=n-1; i<=j; --j){
    if(p[i]+p[j]<=x) i++;
    ans++;
  }
  cout << ans;
  return 0;
}
