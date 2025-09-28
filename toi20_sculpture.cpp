#include<bits/stdc++.h>
using namespace std;

long long w[20010], l[20010];
long long dp[2][20010]; // dp[0] - forward / dp[1] - backward
int mx[2][20010];
const long long INF = 1e18;

int main(){

  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> w[i] >> l[i];
  
  for (int j = 1; j <= n; j++) {
    dp[0][j] = INF;
    dp[1][j] = -1;
  }

  dp[0][0] = 0;
  dp[1][0] = INF;

  for (int i = 1; i <= n; i++) {
    for (int j = n; j >= 1; j--) {
      if (dp[0][j-1] <= l[i]) {
        dp[0][j] = min(dp[0][j], dp[0][j-1] + w[i]);
        mx[0][i] = max(mx[0][i], j); 
        // mx[0][i] means ending exactly at i
      }
    } 
  }
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      if (w[i] <= dp[1][j-1])    dp[1][j] = max(dp[1][j], min(dp[1][j-1] - w[i], l[i]));
      if (dp[1][j] > -1)         mx[1][i] = max(mx[1][i], j);
    } 
  }

  int ans = 0;
  for (int i = 1; i < n; i++) ans = max(ans, mx[0][i] + mx[1][i+1]);

  cout << ans << endl;
  for (int i = 1; i < n; i++) {
    if (mx[0][i] + mx[1][i+1] == ans) cout << i << ' ';
  }

  return 0;
}
