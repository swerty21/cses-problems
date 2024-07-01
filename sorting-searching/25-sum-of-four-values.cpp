#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

vector<tii> sums;
map<int,vector<pii>> mp;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> arr(n+1);
  for(int i=0; i<n; ++i) scanf("%d", &arr[i+1]);
  for(int i=1; i<=n; ++i){
    for(int j=i+1; j<=n; ++j){
      if(arr[i]+arr[j]>x) continue;
      mp[arr[i]+arr[j]].push_back({i,j});
    }
  }
  bool found = false;
  int a,b,c,d;
  for(int i=1; i<=n; ++i){
    for(int j=i+1; j<=n; ++j){
      if(arr[i] + arr[j] > x) continue;
      int rest = x - arr[i] - arr[j];
      if(mp.count(rest) > 0){
        for(auto e: mp[rest]){
          if(i != e.first and i != e.second and j != e.first and j != e.second){
            found = true;
            a = i, b = j, c = e.first, d = e.second;
            break;
          }
        }
      }
      if(found) break;
    }
    if(found) break;
  }
  if(found) {
    printf("%d %d %d %d\n", a, b, c, d);
  }else{
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
