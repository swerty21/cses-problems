#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}
	for(int i=1; i<n; ++i){
		ans += max(arr[i-1]-arr[i], 0);
		arr[i] = max(arr[i-1],arr[i]);
	}
	cout << ans;
	return 0;
}