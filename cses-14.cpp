#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;

vector<pii> solve(int n, int from, int to, int aux){
    vector<pii> res;
    if(n==1) {
        res.push_back({from,to});
        return res;
    }
    auto v1 = solve(n-1,from,aux,to);
    for(pii &e: v1) res.push_back(e);
    res.push_back({from,to});
    auto v2 = solve(n-1,aux,to,from);
    for(pii &e: v2) res.push_back(e);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<pii> ans = solve(n,1,3,2);
    cout << (int)ans.size() << "\n";
    for(pii &e : ans){
        cout << e.first << " " << e.second << "\n";
    }
    return 0;
}