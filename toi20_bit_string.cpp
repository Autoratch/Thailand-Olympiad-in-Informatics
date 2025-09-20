#include<bits/stdc++.h>
using namespace std;

long long cost[1100000], dp[1100000];

int n;

int string_to_int (string s) {
  int cost = 0;
  for (int i = 0; i < n; i++) {
    cost *= 2; 
    cost += (s[i] - '0');
  }
  return cost;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q; cin >> n >> q;

  for (int i = 0; i < (1<<n); i++) {
    string s; int w; 
    cin >> s >> w; 
    cost[string_to_int(s)] = w;
    dp[i] = -1e18;
  }

  dp[0] = 0;
  for (int i = 0; i < (1<<n); i++) {
    for (int j = 0; j < n; j++) {
      if ((i&(1<<j)) == (1<<j)) continue;
      dp[i|(1<<j)] = max(dp[i|(1<<j)], dp[i] + cost[i|(1<<j)]);
    }
    for (int j = 0; j < n-1; j++) {
      if ((i&(3<<j)) == (3<<j)) continue;
      dp[i|(3<<j)] = max(dp[i|(3<<j)], dp[i] + cost[i|(3<<j)]);
    }
  }

  while (q--) {
    string s; cin >> s;
    cout << dp[string_to_int(s)] << '\n';
  }

  return 0;
}
