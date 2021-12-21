#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

vector<string> v;
vector<ll> LCM;
int n;
char k;
ll ans = LLONG_MAX;

ll calc(ll a, ll b){
	return a / __gcd(a, b) * b;
}

void rec(ll click, int layer){
	if(layer == n){
		ans = min(ans, click);
		return ;
	}
	for(ll i=0; i<=LCM[layer + 1] && i + click < ans; i+=LCM[layer]){
		if(v[layer][(i + click) % v[layer].size()] == k){
			rec(click + i, layer + 1);
		}
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		string s;
		cin >> s;
		v.push_back(s);
	}
	LCM.push_back(1);
	for(auto x: v){
		LCM.push_back(calc(LCM.back(), x.size()));
	}
	rec(1, 0);
	cout << ans << "\n";
	return 0;
}
