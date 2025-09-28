#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> x, y, s, t; 

int sum_until (vector<int> & ref_arr, vector<int> & sum_arr, long long until) {
  int idx = upper_bound(ref_arr.begin(), ref_arr.end(), until) - ref_arr.begin();
  return sum_arr[idx-1];
}

int solve () {
  int a, b, k; cin >> a >> b >> k;
  long long l = -1e7, r = 1e9;

  while (l < r) {
    int mid = (l+r) < 0 ? (l+r-1)/2 : (l+r)/2;
    int ans = sum_until(x, s, mid) + sum_until(y, t, (mid - b) / a);

    if (ans >= k) r = mid;
    else          l = mid+1;
  }

  return l;
}

int main () {
  int q; cin >> n >> m >> q;
  x.resize(n+1); s.resize(n+1);
  y.resize(m+1); t.resize(m+1);
  int temp;
  for (int i = 1; i <= n; i++) { cin >> x[i]; }
  for (int i = 1; i <= n; i++) { cin >> temp; s[i] = s[i-1] + temp; }
  for (int i = 1; i <= m; i++) { cin >> y[i]; }
  for (int i = 1; i <= m; i++) { cin >> temp; t[i] = t[i-1] + temp; }
  while (q--) cout << solve () << '\n';
  return 0;
}

/*
9 8 8
1 2 3 4 5 6 7 8 10
1 2 1 3 5 7 6 2 1
1 2 4 5 6 7 9 10
1 2 4 6 3 2 2 1
1 0 1 1 0 2 1 0 3 1 0 8 2 -5 1 2 -5 2 2 -5 3 2 -5 8

5 2 6
1 2 3 4 5 1 1 1 1 1
1 5 1 1
1 0 1 1 0 3 1 1 1 1 1 3 1 -2 1 1 -2 3
*/
