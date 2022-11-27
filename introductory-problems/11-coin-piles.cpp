#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = (int)1e9 + 7;

int main() {
    int t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a>b) swap(a,b);
        a -= (b-a);
        if(a<0) cout << "NO" << endl;
        else if(a%3==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}