#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[maxn];
map<int,int> mp;

int main() {
  int n,k;
  cin >> n >> k;
  for(int i=0; i<n; ++i) scanf("%d", &a[i]);
  ll ans = 0;
  int j=0;
  for(int i=0; i<n; ++i){
    for(; j<n && mp.size() + (1-mp.count(a[j])) <= k; ++j){
      mp[a[j]]++;
      ans += j-i+1;
    }
    // while(j+1<n && mp.size() + (1-mp.count(a[j+i])) <= k){
    //   mp[a[j+1]]++;
    //   j++;
    // }
    mp[a[i]]--;
    if(mp[a[i]]==0) mp.erase(a[i]);
  }
  cout << ans << endl;
  return 0;
}
