#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;

ll solve(ll w1, ll w2, int idx, vector<int> &v){
    int n = (int)v.size();
    if(idx == n) return abs(w2-w1);
    return min(solve(w1+v[idx],w2,idx+1,v),solve(w1,w2+v[idx],idx+1,v));
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin>>v[i];
    cout << solve(0LL,0LL,0,v) << endl;
    return 0;
}