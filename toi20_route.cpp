#include <bits/stdc++.h>
#include "route.h"

using namespace std;

vector<pair<int,int>> route(int N, vector<int> W){
  int M = W.size();
  int remove = M - N + 1;
  vector<pair<int,int>> answer;
  for(int i = 1; i < N; i++) {
    answer.emplace_back(i, i+1); // edges that will remain in the MST
    for (int j = 1; j < i; j++) {
      if (remove == 0) break;
      answer.emplace_back(j, i+1); // edges that will be removed
      remove--;
    }
  }
  return answer;
}
