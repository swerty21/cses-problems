#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

int v[maxn], idx[maxn];

int main() {
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; ++i){
    int x; cin >> x;
    v[i]=x, idx[x] = i;
  }
  idx[0] = idx[n+1] = INF;
  int rounds = 0;
  for(int i=1; i<=n; ++i){
    if(idx[i]<idx[i-1]) rounds++;
  }
  for(int i=0; i<m; ++i){
    int a,b;
    cin >> a >> b;
    if(v[a]>v[b]) swap(a,b);
    if(idx[v[a]] < idx[v[a]-1]) rounds--;
    if(idx[v[a]+1] < idx[v[a]]) rounds--;
    if(idx[v[b]] < idx[v[b]-1] and v[b]-1 > v[a]) rounds--;
    if(idx[v[b]+1] < idx[v[b]]) rounds--;
    idx[v[a]] = b, idx[v[b]] = a;
    swap(v[a],v[b]);
    if(idx[v[b]] < idx[v[b]-1]) rounds++;
    if(idx[v[b]+1] < idx[v[b]]) rounds++;
    if(idx[v[a]] < idx[v[a]-1] and v[a]-1 > v[b]) rounds++;
    if(idx[v[a]+1] < idx[v[a]]) rounds++;
    cout << rounds << endl;
  }
  return 0;
}
