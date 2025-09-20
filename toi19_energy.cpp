#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int N, K, D;
int a[310], qs[310];
long long answer[10][310][310];

int range_sum(int l, int r) { return qs[r]-qs[l-1]; }

long long solve (int l, int r, int k = K) {
  if (k == 1) return 1;
  if (answer[k][l][r] != -1) return answer[k][l][r];
  long long ans = 0;
  for (int i = l; i < r; i++) {
    if (abs(range_sum(l, i) - range_sum(i+1, r)) <= D) {

      long long first_half = solve(l, i, k-1);
      if (first_half == 0) continue;

      ans += (first_half * solve(i+1, r, k-1)) % mod;
      ans %= mod;
    }
  }
  return answer[k][l][r] = ans;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> N >> K >> D;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    qs[i] = qs[i-1] + a[i];
  }

  memset(answer, -1, sizeof answer);

  cout << solve(1, N);

  return 0;
}
