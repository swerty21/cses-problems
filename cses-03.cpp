#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	char prev = '.';
	int ans = 0, curr = 0;
	for(int i=0; i<s.length(); ++i){
		if(s[i]!=prev){
			ans = max(ans,curr);
			curr = 1;
			prev = s[i];
		}else curr++;
	}
	cout << max(ans,curr);
	return 0;
}