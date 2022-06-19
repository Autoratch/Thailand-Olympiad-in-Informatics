#include <bits/stdc++.h>
using namespace std;

const int MxN = 200020;
int a[MxN], l[MxN], r[MxN], dp[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int sz = 0, x;
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(dp, dp + sz, a[i]) - dp;
		sz += (sz == idx);
		dp[idx] = a[i];
		l[i] = idx;
	}
	reverse(a + 1, a + n + 1);
	sz = 0;
	for(int i=1, j=n; i<=n; ++i, --j){
		int idx = lower_bound(dp, dp + sz, a[i]) - dp;
		sz += (sz == idx);
		dp[idx] = a[i];
		r[j] = idx;
	}
	while(q--){
		cin >> x;
		++x;
		cout << min(l[x], r[x]) << "\n";
	}
	return 0;
}
