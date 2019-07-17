#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 

const int N = 3e3;

int n,m,t,ans;
vector<pair<int,int> > adj[N];
vector<pair<int,int> > cost;
priority_queue<pii,vector<pii>,greater<pii> > q;
bool visited[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b,d,e;
        cin >> a >> b >> d >> e;
        if(e) d = 0;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }

    cin >> t;

    while(t--)
    {
        int a,b;
        cin >> a >> b;
        cost.push_back({a,b});
    }

    sort(cost.begin(),cost.end());

    for(int i = cost.size()-2;i >= 0;i--) cost[i].second = min(cost[i].second,cost[i+1].second);

    q.push({0,0});

    while(!q.empty())
    {
        int w = q.top().first,p = q.top().second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        if(w)
        {
            auto it = lower_bound(cost.begin(),cost.end(),make_pair(w,INT_MIN));
            ans+=it->second;
        }
        for(pair<int,int> i : adj[p]) q.push(i);
    }

    cout << ans;
}
