#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int a[maxn];
vector<pii> st;

int main() {
  int n,x;
  cin >> n >> x;
  for(int i=0; i<n; ++i) scanf("%d", &a[i]);
  int sum = 0, ans = 0;
  for(int j=0, i=0; j<n; ++j){
    sum += a[j];
    while(i<j and sum>x) sum -= a[i++];
    if(sum==x) ans++;
  }
  cout << ans << endl;
  return 0;
}
