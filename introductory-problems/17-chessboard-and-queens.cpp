#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;

ll pow10[50];

void powcalc(){
    pow10[0] = 1;
    for(int i=1; i<=18; ++i) pow10[i] = pow10[i-1] * 10;
}

vector<int> todigits(ll n){
    vector<int> res;
    while(n>0){
        res.push_back(n%10);
        n/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

vector<ll> precalc(){
    vector<ll> res;
    int i=1;
    ll curr = 1;
    while(curr <= (ll)1e18){
        res.push_back(curr);
        curr = curr + 9LL*pow10[i-1]*i;
        i++;
    }
    return res;
}

int main() {
    int q;
    cin >> q;
    powcalc();
    vector<ll> seg = precalc();
    for(int i=0; i<q; ++i){
        ll k;
        cin >> k;
        int nd = (int)seg.size()-1;
        while(seg[nd] > k) --nd;
        ll diff = k - seg[nd];
        ll num = pow10[nd] + diff/(nd+1);
        int offset = diff % (nd+1);
        cout << todigits(num)[offset] << endl;
    }
    return 0;
}