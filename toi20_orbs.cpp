#include<bits/stdc++.h>
using namespace std;

vector<int> v;
multiset<int> head, mid, tail; // ath is last in head, bth is first is tail 

int main(){
  int n, l; scanf("%d %d", &n, &l);
  int a, b; scanf("%d %d", &a, &b);
  v.resize(n);
  for (auto &x : v) scanf("%d", &x); 
  
  sort(v.begin(), v.end());

  head = multiset<int>(v.begin(), v.begin()+a);
  mid  = multiset<int>(v.begin()+a, v.begin()+b-1);
  tail = multiset<int>(v.begin()+b-1, v.end());

  for (int i = 0; i < l; i++) {
    int x = *--head.end();
    int y = *tail.begin();
    head.erase(--head.end());
    tail.erase(tail.begin());
    mid.insert(y-x);
    mid.insert((x+y)/2);
    head.insert(*mid.begin());
    mid.erase(mid.begin());
    tail.insert(*--mid.end());
    mid.erase(--mid.end());
  }

  for (auto x : head) printf("%d ", x);
  for (auto x : mid)  printf("%d ", x);
  for (auto x : tail) printf("%d ", x);

  return 0;
}
