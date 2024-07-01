#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[105];

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) cin >> a[i];
  vector<bool> v(maxn,false);
  v[0] = 1;
  for(int i=0; i<n; ++i){
    for(int j=100000; j>=0; --j){
      if(v[j]) v[j+a[i]] = 1;
    }
  }
  int res =0;
  for(int i=1; i<maxn; ++i){
    if(v[i]) res++;
  }
  cout << res << "\n";
  for(int i=1; i<maxn; ++i){
    if(v[i]) printf("%d ",i);
  }
  cout << endl;
  return 0;
}
