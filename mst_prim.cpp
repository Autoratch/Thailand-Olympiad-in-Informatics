#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int n,m,ans;
vector<bool> visited;
vector<vector<pair<int,int> > > adj;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    adj.resize(n);
    visited.resize(n);

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }

    q.push({0,0});

    while(!q.empty())
    {
        int w = q.top().first,p = q.top().second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        ans+=w;
        for(int i = 0;i < adj[p].size();i++) if(!visited[adj[p][i].second]) q.push(adj[p][i]);
    }

    cout << ans;
}
