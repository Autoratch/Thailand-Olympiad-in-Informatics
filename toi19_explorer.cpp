#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int cnt[500100];
long long fact[500100];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int N; cin >> N;

  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = i * fact[i-1]; 
    fact[i] %= mod;
  }

  for (int i = 1; i <= 2*N-1; i++) {
    int x; cin >> x; 
    cnt[x]++;
  }

  long long ans = 1;
  for (int i = 1; i <= N; i++) {
    ans *= fact[cnt[i]-1];
    ans %= mod;
  }

  cout << ans;

  return 0;
}
