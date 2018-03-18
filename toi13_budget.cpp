#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m,s,e,k;

    cin >> n >> m >> s >> e >> k;

    vector<vector<pair<int,int> > > adj(n);

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }

    vector<int> fw(n,INT_MAX),bw(n,INT_MAX);

    fw[s] = 0;

    vector<bool> visited(n);

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

    q.push({0,s});

    while(!q.empty())
    {
        int w = q.top().first,p = q.top().second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        for(int i = 0;i < adj[p].size();i++)
        {
            if(fw[p]+adj[p][i].first<fw[adj[p][i].second] and fw[p]+adj[p][i].first<=k)
            {
                fw[adj[p][i].second] = fw[p]+adj[p][i].first;
                q.push({fw[adj[p][i].second],adj[p][i].second});
            }
        }
    }

    if(fw[e]<INT_MAX){ cout << e << ' ' << fw[e] << ' ' << "0"; return 0; }

    int mb = INT_MAX,idx = INT_MAX;

    bw[e] = 0;
    visited.assign(n,false);

    q.push({0,e});

    while(!q.empty())
    {
        int w = q.top().first,p = q.top().second;
        q.pop();
        if(fw[p]<INT_MAX)
        {
            if(bw[p]<mb)
            {
                mb = bw[p];
                idx = p;
            }
            else if(bw[p]<mb and p<idx) idx = p;
        }
        if(visited[p]) continue;
        visited[p] = true;
        for(int i = 0;i < adj[p].size();i++)
        {
            if(bw[p]+adj[p][i].first<bw[adj[p][i].second])
            {
                bw[adj[p][i].second] = bw[p]+adj[p][i].first;
                q.push({bw[adj[p][i].second],adj[p][i].second});
            }
        }
    }

    cout << idx << ' ' << fw[idx] << ' ' << bw[idx];
}
