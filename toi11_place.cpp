#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m;

    cin >> n >> m;

    vector<vector<pair<int,int> > > adj(n);

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        a--; b--; d--;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }

    priority_queue<pair<int,int> > q;

    q.push({0,0});

    long long ans = 0;

    vector<bool> visited(n,false);

    while(!q.empty())
    {
        int p = q.top().second,w = q.top().first;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        ans+=w;
        for(int i = 0;i < adj[p].size();i++) if(!visited[adj[p][i].second]) q.push(adj[p][i]);
    }

    cout << ans;
}
