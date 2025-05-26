#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int main() {
  int n;
  cin >> n;
  set<int> days;
  vector<tii> input;
  for(int i=0; i<n; ++i){
    int a,b,p;
    scanf("%d %d %d",&a,&b,&p);
    input.emplace_back(a,b+1,p);
    days.insert(a);
    days.insert(b+1);
  }
  int nc = 0;
  map<int,int> tr;
  for(auto &e: days){
    tr[e] = nc++;
  }
  vector<vector<pii>> ends(nc);
  for(auto &e: input){
    int a,b,p;
    tie(a,b,p) = e;
    ends[tr[b]].push_back({tr[a],p});
  }
  vector<ll> dp(nc);
  for(int i=0; i<nc; ++i){
    if(i>0) dp[i] = dp[i-1];
    for(auto &e: ends[i])
      dp[i] = max(dp[i],dp[e.first] + e.second);
  }
  cout << dp.back() << endl;
  return 0;
}
