#include<bits/stdc++.h>
using namespace std;

struct Point {
  long long x, y;

  Point operator + (const Point & other) const {
    return {x + other.x, y + other.y};
  }

};

struct compare_x {
  bool operator () (const Point & a, const Point & b) const {
    return (a.x == b.x) ? a.y < b.y : a.x < b.x;
  }
};

struct compare_y {
  bool operator () (const Point & a, const Point & b) const {
    return (a.y == b.y) ? a.x < b.x : a.y < b.y;
  }
};

struct GraphAdj { int v; Point p; }; 
vector<GraphAdj> g[200100];

int n; 
vector<Point> points;

const long long INF = 1e18;

void dfs (int u, Point acc = {0, 0}) {
  if (u == n) points.push_back(acc);
  for (auto [x, p] : g[u]) {
    dfs (x, acc + p);
  }
}

long long dist (Point a, Point b) {
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

long long closest_pair () {
  sort(points.begin(), points.end(), compare_x());

  long long mn_dist = INF;
  long long delta = sqrt(mn_dist);
  set<Point,compare_y> s; 
  s.insert(points[0]);

  int j = 0;
  for (int i = 1; i < points.size(); i++) {
    
    while (j < i && points[j].x < points[i].x - delta) {
      s.erase(points[j++]);
    }

    auto l = s.lower_bound({0, points[i].y - delta});

    while (l != s.end()) {
      if (l->y > points[i].y + delta) break;
      long long d = dist(points[i], *l);
      mn_dist = min(mn_dist, d);
      delta = sqrt(mn_dist);
      l++;
    }
    
    s.insert(points[i]);

  }

  return mn_dist;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int m, l; cin >> n >> m >> l;
  
  int x; for (int i = 1; i <= l; i++) cin >> x;

  for (int i = 1; i <= m; i++) {
    int u, v, s, w; cin >> u >> v >> s >> w; 
    Point p = s == 1 ? (Point){w, 0} : (Point){0, w};
    g[u].push_back({v, p});
  }

  dfs (1);
  cout << closest_pair() << endl;

  return 0;
}
