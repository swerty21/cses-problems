#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = (int)1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> freq(26,0);
    for(char c: s){
        freq[c - 'A']++;
    }
    string ans = "";
    vector<int> odds;
    for(int i=0; i<26; ++i){
        int nchars = freq[i]/2;
        for(int j=0; j<nchars; ++j){
            ans += char('A'+i);
        }
        freq[i] -= nchars*2;
        if(freq[i]==1) odds.push_back(i);
    }
    if((int)odds.size()>1) cout << "NO SOLUTION";
    else {
        string ans1 = ans;
        if ((int)odds.size()==1) ans1 += char('A'+odds[0]);
        reverse(ans.begin(),ans.end());
        ans1 += ans;
        cout << ans1;
    }
    return 0;
}