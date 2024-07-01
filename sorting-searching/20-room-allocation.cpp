#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = pair<pii,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

vector<tii> t;
int ans[maxn];

int main() {
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; ++i){
    int a,b;
    scanf("%d %d", &a, &b);
    t.push_back({{a,1},i});
    t.push_back({{b+1,-1},i});
  }
  sort(t.begin(),t.end());
  vector<int> free;
  int k = 0, curr = 1;
  for(int i=0; i<(int)t.size(); ++i){
    if(t[i].first.second == 1){
      if(free.empty()){
        k = max(k,curr);
        ans[t[i].second] = curr++;
      }else {
        ans[t[i].second] = free.back();
        free.pop_back();
      }
    }else{
      free.push_back(ans[t[i].second]);
    }
  }
  printf("%d\n", k);
  for(int i=0; i<n; ++i) printf("%d ", ans[i]);
  return 0;
}
