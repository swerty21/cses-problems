#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;

pii x[maxn];

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i){
    int a; cin >> a;
    x[i]={a,i};
  }
  sort(x,x+n);
  int ans = 1;
  for(int i=1; i<n; ++i){
    if(x[i].second < x[i-1].second) ans++;
  }
  cout << ans << endl;
  return 0;
}
