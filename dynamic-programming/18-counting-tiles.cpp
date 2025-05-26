#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

ll dp[1010][(1<<10)];
int n,m;

void calc_ways(int idx, int curr_mask, int next_mask, int col){
  if(idx == n){
    dp[col+1][next_mask] = (dp[col+1][next_mask] + dp[col][curr_mask])%MOD;
    return;
  }

  //pass if the digit is set:
  if(curr_mask&(1<<idx)){
    calc_ways(idx+1,curr_mask,next_mask,col);
  }else{
    //insert a 1x2 tile:
    calc_ways(idx+1,curr_mask,next_mask | (1<<idx),col);
    //insert a 2x1 tile, if the next digit is unset:
    if(idx+1<n && ((curr_mask&(1<<(idx+1)))==0)){
      calc_ways(idx+2,curr_mask,next_mask,col);
    }
  }
}

int main() {
  cin >> n >> m;
  //base case:
  dp[0][0] = 1LL;
  for(int col=0; col<m; ++col){
    for(int curr_mask=0; curr_mask<(1<<n); ++curr_mask){
      if(dp[col][curr_mask]>0){
        calc_ways(0,curr_mask,0,col);
      }
    }
  }
  cout << dp[m][0] << endl;
  return 0;
}
