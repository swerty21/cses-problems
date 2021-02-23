#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,y,x;
    long long ans;
	cin >> t;
    for(int i=0; i<t; ++i){
        cin >> y >> x;
        if(y>x){
            if(y%2==0) ans = (1LL)*y*y - x + 1;
            else ans = (1LL)*(y-1)*(y-1) + 1 + x - 1;
        }else{
            if(x%2==0) ans = (1LL)*(x-1)*(x-1) + 1 + y - 1;
            else ans = (1LL)*x*x - y + 1;
        }
        cout << ans << endl;
    }
	return 0;
}