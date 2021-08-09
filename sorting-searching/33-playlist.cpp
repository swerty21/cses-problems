#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[maxn];
set<int> seq;

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) cin >> a[i];
  int ans=0, curr_len=0;
  int j=0;
  for(int i=0; i<n; ++i){
    while(j<n and seq.count(a[j])==0){
      seq.insert(a[j]);
      curr_len++;
      ans = max(ans,curr_len);
      j++;
    }
    seq.erase(a[i]);
    curr_len--;
  }
  cout << ans << endl;
  return 0;
}
