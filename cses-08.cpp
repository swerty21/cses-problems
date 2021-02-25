#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<int> gr1;

int main() {
	int n;
    ll sum;
	cin >> n;
    sum = 1LL*n*(n+1)/2;
    if(sum %2 == 0){
        cout << "YES" << endl;
        ll curr_sum = 0;
        for(int i=n; curr_sum+i<sum/2; --i){
            gr1.insert(i);
            curr_sum += i;
        }
        gr1.insert((int)(sum/2-curr_sum));
        cout << n - gr1.size() << endl;
        for(int i=1; i<=n; ++i){
            if(gr1.count(i)==0) cout << i << " ";
        }
        cout << endl;
        cout << gr1.size() << endl;
        for(int e: gr1) cout << e << " ";
    }else cout << "NO" << endl;
	return 0;
}