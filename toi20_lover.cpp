#include<bits/stdc++.h>
using namespace std;

int qs_odd[10010], qs_evn[10010];
int cnt[10010];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, v, w; cin >> n >> v >> w;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    qs_odd[i] = qs_odd[i-1];
    qs_evn[i] = qs_evn[i-1];
    if (x&1) qs_odd[i] += x;
    else     qs_evn[i] += x;
    cnt[i] = 1e9;
  }

  cnt[0] = 0;
  for (int i = 2; i <= n; i+=2) {
    for (int j = 1; j < i; j+=2) {
      int mid = (i+j)/2;
      int odd = qs_odd[mid]-qs_odd[j-1];
      int evn = qs_evn[i]  -qs_evn[mid];
      if (odd <= v && evn <= w) cnt[i] = min(cnt[i], cnt[j-1] + 1);
    }
  }

  cout << (cnt[n]==1e9 ? -1 : cnt[n]);

  return 0;
}
