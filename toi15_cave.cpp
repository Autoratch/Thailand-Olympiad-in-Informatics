#include <bits/stdc++.h>
using namespace std;

int N,E,Q,st,en;
vector<pair<int,int>> adj[2010];
vector<pair<long long,int>> dist[2010];
priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>> > q;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> st >> en >> E;
    for(int i=0;i<E;i++){
        int a,b,wt;
        cin >> a >> b >> wt;
        adj[a].push_back({wt,b});
    }
    q.push({0,{st,-1}});
    while(!q.empty())
    {
        long long d=q.top().first; int now=q.top().second.first,hop=q.top().second.second;
        q.pop();

        /*
        for(auto t:dist[now]) if(hop>=t.second && d>=t.first) status=true;
        if(status) continue;
        */

        dist[now].push_back({d,hop});
        for(auto t:adj[now])
        {
            int l=t.first,next=t.second;
            bool status=false;
            for(auto n:dist[next]) if(hop>=n.second && d>=n.first) status=true;
            if(status==false) q.push({d+l,{next,hop+1}});
        }
    }
    cin >> Q;
    for(int i=0;i<Q;i++)
    {
        int h;
        long long ans=INT_MAX;
        cin >> h;
        for(auto n : dist[en]) ans=min(ans,n.first+h*n.second);
        cout << ans << " ";
    }
}
/*
8 0 7 14
0 1 10
0 3 14
0 4 8
1 2 2
2 7 2
2 3 4
3 7 15
3 4 9
5 3 7
5 7 2
4 5 5
4 6 1
6 5 1
6 4 3
4
0 10 2 30
*/
