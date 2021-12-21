#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1e7 + 20;
int n, m, x;
int p[15], a[15], l[15], s[15], qr[15], qs[MxN];

bool solve(int t){
	vector<int> mark(n + 1);
	for(int j, i=1; i<=n; ++i){
		for(j=1; j<=n; ++j){
			if(mark[j]){
				continue;
			}
			int lb = p[i];
			int rb = p[i + 1];
			int cnt = 0, ch = 1;
			while(ch && lb < rb){
				++cnt;
				int idx = upper_bound(qs + lb, qs + rb, l[j] - a[i] + qs[lb - 1]) - qs;
				if(idx == lb){
					ch = 0;
				}
				lb = idx;
			}
			if(ch && cnt <= t){
				mark[j] = 1;
				break;
			}
		}
		if(j == n + 1){
			return false;
		}
	}
	return true;
}

bool calc(int query){
	for(int i=1; i<=n; ++i){
		cin >> p[i];
	}
	p[n + 1] = m + 1;
	do{
		if(solve(query)){
			return true;
		}
	}while(next_permutation(a + 1, a + n + 1));
	return false;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m >> x;
	for(int i=1; i<=n; ++i){
		cin >> l[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> qs[i];
		qs[i] += qs[i - 1];
	}
	for(int i=1; i<=x; ++i){
		cin >> qr[i];
	}
	sort(l + 1, l + n + 1);
	for(int i=1; i<=x; ++i){
		cout << (calc(qr[i]) ? "P": "F") << "\n";
	}
	return 0;
}
