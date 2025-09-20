// bad solution, too complicated

#include<bits/stdc++.h>
using namespace std;

int n;
string s;

long long triangle (long long n) {
  return n * (n + 1) / 2;
}

struct Accum { long long ind, val; };

long long solve () {
  long long ans = 0;
  long long acc = 0;

  long long size_of_t_chunk = 0;

  stack<Accum> accum_stack;
  for (int r = 0; r < n; r++) {
    if (s[r] == 'F') {
      for (int i = size_of_t_chunk; i >= 1; i--) {
        accum_stack.push({r-i, i});
      }
      size_of_t_chunk = 0;
    }
    else {
      size_of_t_chunk++;

      if (!accum_stack.empty() && size_of_t_chunk >= accum_stack.top().val) {
        auto top = accum_stack.top();

        acc -= (top.val-1) * (r - size_of_t_chunk - top.ind); // remove numbers after 
        accum_stack.pop();

        if (!accum_stack.empty()) acc -= top.val * (top.ind - accum_stack.top().ind);
        else acc -= top.val * top.ind;
        
      }

      if (accum_stack.empty()) {
        acc = (r + 1 - size_of_t_chunk) * size_of_t_chunk + triangle(size_of_t_chunk);
      }
      else {
        acc += size_of_t_chunk; // lengthen trailing triangle to

        long long until = r - size_of_t_chunk;
        long long start = accum_stack.empty() ? 0 : accum_stack.top().ind + 1;
        acc += size_of_t_chunk * (until - start + 1);
      }
    }
    ans += acc;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> s;
  cout << solve();

  return 0;
}

