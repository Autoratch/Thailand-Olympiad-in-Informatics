#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MxN = 500050;
ll a[MxN], cost[MxN], score[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i] >= 0){
			score[i] += a[i];
		}
		else{
			cost[i] -= a[i];
		}
		score[i] += score[i - 1];
		cost[i] += cost[i - 1];
	}
	int idx, x;
	while(q--){
		cin >> idx >> x;
		int id = lower_bound(cost + 1, cost + n + 1, x + cost[idx]) - (cost + 1);
		cout << score[id] - score[idx] << "\n";
	}
	return 0;
}
