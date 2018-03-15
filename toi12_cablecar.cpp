#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m;

    cin >> n >> m;

    vector<vector<pair<int,int> > > adj(n),adj2(n);
    vector<bool> visited(n,false);

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a-1].push_back({d,b-1});
        adj[b-1].push_back({d,a-1});
    }

    int s,e,num;

    cin >> s >> e >> num;
    s--; e--;

    priority_queue<pair<int,pair<int,int> > > q;

    q.push({0,{0,0}});

    while(!q.empty())
    {
        int w = q.top().first,p = q.top().second.first,pr = q.top().second.second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        if(p or pr)
        {
            adj2[p].push_back({w,pr});
            adj2[pr].push_back({w,p});
        }
        for(int i = 0;i < adj[p].size();i++) if(!visited[adj[p][i].second]) q.push({adj[p][i].first,{adj[p][i].second,p}});
    }

    visited.assign(n,false);

    queue<pair<int,int> > q2;

    q2.push({s,INT_MAX});
    visited[s] = true;

    while(!q2.empty())
    {
        int p = q2.front().first,w = q2.front().second;
        q2.pop();
        if(p==e)
        {
            w--;
            if(num%w) num = (num/w)+1;
            else num/=w;
            cout << num; return 0;
        }
        for(int i = 0;i < adj2[p].size();i++) if(!visited[adj2[p][i].second]){ q2.push({adj2[p][i].second,min(adj2[p][i].first,w)}); visited[adj2[p][i].second] = true; }
    }
}
