#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;

int x[maxn];

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) cin >> x[i];
  ll curr_sum = 0, max_sum = (int)-2e9;
  for(int i=0; i<n; ++i){
    curr_sum += x[i];
    max_sum = max(max_sum,curr_sum);
    if(curr_sum<0) curr_sum = 0;
  }
  cout << max_sum << endl;
  return 0;
}
