#include <bits/stdc++.h>
using namespace std;

int n,m,s,e;
vector<pair<int,pair<int,int> > > adj;
vector<int> dist;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> e;

    adj.resize(m);
    dist.assign(n,INT_MAX);

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[i] = {d,{a,b}};
    }

    dist[0] = 0;
    for(int i = 0;i < n-1;i++) for(int j = 0;j < m;j++)
    {
        int a = adj[i].second.first,b = adj[i].second.second,d = adj[i].first;
        if(dist[a]!=INT_MAX and dist[a]+d<dist[b]) dist[b] = dist[a]+d;
    }

    cout << dist[e];
}
