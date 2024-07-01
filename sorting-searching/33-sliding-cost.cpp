#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5+10;
const int INF = (int)2e9;

ll x[maxn];
ll sumlow, sumup;
multiset<ll> slow, sup;

void balance(){
  while((int)slow.size() < (int)sup.size()){
    ll temp = *sup.begin();
    slow.insert(temp);
    sumlow += temp;
    sup.erase(sup.find(temp));
    sumup -= temp;
  }
  while((int)sup.size() < (int)slow.size()-1){
    ll temp = *slow.rbegin();
    sup.insert(temp);
    sumup += temp;
    slow.erase(slow.find(temp));
    sumlow -= temp;
  }
}

void addel (ll a){
  if(slow.empty() or a <= *slow.rbegin()) {
    slow.insert(a);
    sumlow += a;
  }else {
    sup.insert(a);
    sumup += a;
  }
  balance();
}

void eraseel(ll a){
  if(sup.count(a)>0) {
  	sup.erase(sup.find(a));
  	sumup -= a;
  }
  else {
  	slow.erase(slow.find(a));
  	sumlow -= a;
  }
  balance();
}

int main() {
  int n,k;
  cin >> n >> k;
  for(int i=0; i<n; ++i) scanf("%lld", &x[i]);
  sumup = 0, sumlow = 0;
  for(int i=0; i<n; ++i) {
    addel(x[i]);
    if(i>=k) eraseel(x[i-k]);
    if(i>=k-1) {
      ll median = *slow.rbegin();
      cout << median * (int)slow.size() - sumlow + sumup - median * (sup.empty() ? 0:(int)sup.size()) << " ";
    }
  }
  return 0;
}
