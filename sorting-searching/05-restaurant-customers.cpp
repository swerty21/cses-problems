#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;

pii t[maxn*2];

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) {
    int a,b; cin >> a >> b;
    t[2*i] = {a,0};
    t[2*i+1] = {b,1};
  }
  sort(t,t+2*n);
  int ans = (int)-1e9, curr = 0;
  for(int i=0; i<n*2; ++i){
    if(t[i].second == 0) {
      curr++;
      ans = max(ans,curr);
    }else if(t[i].second == 1) curr--;
  }
  cout << ans << endl;
  return 0;
}
