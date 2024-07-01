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
  vector<int> dp;
  for(int i=0; i<n; ++i){
    int x;
    cin >> x;
    int pos = lower_bound(dp.begin(),dp.end(),x) - dp.begin();
    if(pos == (int)dp.size()){
      dp.push_back(x);
    }else{
      dp[pos] = x;
    }
  }
  cout << dp.size() << endl;
  return 0;
}
