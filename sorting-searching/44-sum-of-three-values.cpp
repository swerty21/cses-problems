#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[maxn];
vector<tii> sums;
unordered_map<int,vector<pii>> mp;

int main() {
  int n, x;
  cin >> n >> x;
  for(int i=0; i<n; ++i) scanf("%d", &a[i]);
  for(int i=1; i<n; ++i){
    for(int j=0; j<i; ++j){
      if(a[i]+a[j]>x) continue;
      sums.push_back({a[i]+a[j],i+1,j+1});
    }
  }
  sort(sums.begin(),sums.end());
  bool found = 0;
  int i=0, j=(int)sums.size()-1;
  while(i<j){
    if(get<0>(sums[i]) + get<0>(sums[j]) == x) {
      if(get<1>(sums[i])!=get<1>(sums[j]) and get<1>(sums[i])!=get<2>(sums[j]) and get<2>(sums[i])!=get<1>(sums[j]) and get<2>(sums[i])!=get<2>(sums[j])){
        printf("%d %d %d %d\n",get<1>(sums[i]),get<2>(sums[i]),get<1>(sums[j]),get<2>(sums[j]));
        found = 1;
        break;
      }
    }
    if(get<0>(sums[i]) + get<0>(sums[j]) >= x) --j;
    else ++i;
    if(found) break;
  }
  if(!found) cout << "IMPOSSIBLE" << endl;
  return 0;
}
