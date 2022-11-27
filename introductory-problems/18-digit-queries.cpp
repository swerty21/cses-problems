#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;

ll ans = 0;
int col[20], diag1[20], diag2[20];
int mx[20][20];

void solve(int n, int r0){
  if (n==8){
    ans++;
    return;
  }
  for (int i=r0; i<8; ++i){
    for (int j=0; j<8; ++j){
      if(col[j] or diag1[i+j] or diag2[i+7-j] or mx[i][j]) continue;
      col[j] = diag1[i+j] = diag2[i+7-j] = 1;
      solve(n+1,i+1);
      col[j] = diag1[i+j] = diag2[i+7-j] = 0;
    }
  }
}

int main() {
  for(int i=0; i<8; ++i){
    string s;
    cin >> s;
    for(int j=0; j<8; ++j) {
      if (s[j]=='*') mx[i][j] = 1;
      else mx[i][j] = 0;
    }
  }
  solve(0,0);
  cout << ans << endl;
  return 0;
}
