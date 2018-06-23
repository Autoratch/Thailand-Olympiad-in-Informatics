#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7
#define pii pair<pair<int,int>,pair<int,bool> >

int n,m,s,e,k,ans = INT_MAX;
bool visited[100][101][2];
int dist[100][101][2],c[100];
vector<vector<pair<int,int> > > adj;
priority_queue<pii,vector<pii>,greater<pii> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> c[i];
    adj.resize(n);

    cin >> s >> e >> k >> m;
    s--; e--;

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        a--; b--;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }

    for(int i = 0;i < n;i++) for(int j = 0;j <= k;j++) dist[i][j][0] = dist[i][j][1] = INT_MAX;

    q.push({{0,0},{s,0}});
    dist[s][0][0] = 0;

    while(!q.empty())
    {
        int w = q.top().first.first,f = q.top().first.second,p = q.top().second.first;
        bool used = q.top().second.second;
        q.pop();
        if(p==e)
        {
            if(!used) ans = min(ans,w);
            else ans = min(ans,w+c[e]*(k-f));
        }
        if(visited[p][f][used]) continue;
        visited[p][f][used] = true;
        for(int i = 0;i < adj[p].size();i++)
        {
            if(!used)
            {
                if(w<dist[adj[p][i].second][k-adj[p][i].first][true])
                {
                    dist[adj[p][i].second][k-adj[p][i].first][true] = w;
                    q.push({{w,k-adj[p][i].first},{adj[p][i].second,true}});
                }
            }
            for(int j = 0;j+f <= k;j++)
            {
                if(j+f<adj[p][i].first) continue;
                if(w+(j*c[p])<dist[adj[p][i].second][j+f-adj[p][i].first][used])
                {
                    dist[adj[p][i].second][j+f-adj[p][i].first][used] = w+(j*c[p]);
                    q.push({{w+(j*c[p]),j+f-adj[p][i].first},{adj[p][i].second,used}});
                }
            }
        }
    }

    cout << ans;
}
