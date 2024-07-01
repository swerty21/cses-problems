#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int ans[maxn];
vector<pii> st;

int main() {
  int n,x;
  cin >> n;
  for(int i=0; i<n; ++i){
    scanf("%d", &x);
    while(!st.empty() and st.back().first >= x) st.pop_back();
    if(st.empty()){
      ans[i] = 0;
    }else ans[i] = st.back().second;
    st.push_back({x,i+1});
  }
  for(int i=0; i<n; ++i) cout << ans[i] << " ";
  return 0;
}
