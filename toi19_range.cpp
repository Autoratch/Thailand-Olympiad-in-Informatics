#include<bits/stdc++.h>
using namespace std;

struct Range { 
  int l, r, ind;
  bool operator < (const Range & o) const {
    if (r == o.r) return l > o.l;
    return r < o.r;
  }
};

vector<Range> triangles;
vector<int> answer;
vector<int> lis;

int main () {

  int n; cin >> n;
  triangles.resize(n);
  answer.resize(n);
  int cnt = 0;
  for (auto & tr: triangles) {
    cin >> tr.l >> tr.r;
    tr.ind = cnt++;
  }

  sort(triangles.begin(), triangles.end());

  for (auto t : triangles) {
    int idx = upper_bound(lis.begin(), lis.end(), -t.l) - lis.begin();
    if (idx == lis.size()) lis.push_back(-t.l);
    else lis[idx] = -t.l;
    answer[t.ind] = idx+1;
  }

  int mx = 0;
  for (int i = 0; i < n; i++) mx = max(mx, answer[i]);
  cout << mx << endl;
  for (int i = 0; i < n; i++) {
    cout << answer[i] << ' ';
  }

  return 0;
}

/*

*/
