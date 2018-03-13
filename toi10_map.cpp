#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n,in;

    cin >> m >> n;
    in = m*n;

    vector<int> u(in,-1),d(in,-1),l(in,-1),r(in,-1);
    vector<vector<int> > ans(m);

    for(int i = 0;i < m;i++) ans[i].resize(n);

    for(int i = 0;i < in-1;i++)
    {
        int a,b;
        char c;
        cin >> a >> c >> b;
        if(c=='L'){ r[a] = b; l[b] = a; }
        else{ d[a] = b; u[b] = a; }
    }

    int ul = 0,mx = 0;

    queue<pair<int,pair<int,int> > > q;
    vector<bool> visited(in,false);

    q.push({0,{0,0}});
    visited[0] = true;

    while(!q.empty())
    {
        int p = q.front().first,x = q.front().second.first,y = q.front().second.second;
        q.pop();
        if(x+y>mx){ ul = p; mx = x+y; }
        if(l[p]!=-1) if(!visited[l[p]]){ q.push({l[p],{x,y+1}}); visited[l[p]] = true; }
        if(r[p]!=-1) if(!visited[r[p]]){ q.push({r[p],{x,y-1}}); visited[r[p]] = true; }
        if(u[p]!=-1) if(!visited[u[p]]){ q.push({u[p],{x+1,y}}); visited[u[p]] = true; }
        if(d[p]!=-1) if(!visited[d[p]]){ q.push({d[p],{x-1,y}}); visited[d[p]] = true; }
    }

    q.push({ul,{0,0}});
    visited.assign(in,false);
    visited[ul] = true;

    while(!q.empty())
    {
        int p = q.front().first,x = q.front().second.first,y = q.front().second.second;
        q.pop();
        ans[x][y] = p;
        if(l[p]!=-1) if(!visited[l[p]]){ q.push({l[p],{x,y-1}}); visited[l[p]] = true; }
        if(r[p]!=-1) if(!visited[r[p]]){ q.push({r[p],{x,y+1}}); visited[r[p]] = true; }
        if(u[p]!=-1) if(!visited[u[p]]){ q.push({u[p],{x-1,y}}); visited[u[p]] = true; }
        if(d[p]!=-1) if(!visited[d[p]]){ q.push({d[p],{x+1,y}}); visited[d[p]] = true; }
    }

    for(int i = 0;i < m;i++){ for(int j = 0;j < n;j++) cout << ans[i][j] << ' '; cout << endl; }
}
