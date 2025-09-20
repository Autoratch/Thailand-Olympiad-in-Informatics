#include<bits/stdc++.h>
#include <queue>
using namespace std;

const int INF = 1e9;

int w[100100], poison[100100], cure[100100];
int dist[1100000]; 

int n; 

vector<pair<int,int>> graph[1100100];

struct HeapElement {
  int state, dis;
  bool operator < (const HeapElement & o) const {
    return dis > o.dis;
  }
};

int main () {
  int s; cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    for (int j = 0; j < s; j++) {
      int x; cin >> x;
      if (x == -1) poison[i] |= (1<<j);
      if (x == 1)  cure[i]   |= (1<<j);
    }
    graph[poison[i]].push_back({cure[i], w[i]});
  }

  for (int i = 0; i < (1<<s); i++) dist[i] = INF;

  priority_queue<HeapElement> heap;
  heap.push({0, 0});
  while (!heap.empty()) {
    auto [state, dis] = heap.top(); heap.pop();

    for (auto x : graph[state]) {
      if (dist[x.first] <= dis + x.second) continue;
      dist[x.first] = dis + x.second;
      heap.push({x.first, dis + x.second});
    }
    for (int i = 0; i < s; i++) {
      if (dist[state & ~(1<<i)] <= dis) continue;
      dist[state & ~(1<<i)] = dis;
      heap.push({state & ~(1<<i), dis});
    }
  }

  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[poison[i]] == INF) continue;
    mx = max(mx, dist[poison[i]]);
  } 

  cout << mx;

  return 0;
}

/*
4 2
5 0 1
6 -1 1
7 1 0
8 -1 -1

5 3
1 -1 1 0
1 1 0 0
1 0 0 -1
1 0 -1 1
1 -1 1 0
*/
