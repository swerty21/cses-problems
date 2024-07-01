#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = pair<pii,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

vector<pii> tasks;

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) {
    int a, d;
    cin >> a >> d;
    tasks.push_back({a,d});
  }
  sort(tasks.begin(),tasks.end());
  ll ans = 0, curr_t = 0;
  for(auto e: tasks){
    curr_t += e.first;
    ans += (e.second - curr_t);
  }
  cout << ans << endl;
  return 0;
}
