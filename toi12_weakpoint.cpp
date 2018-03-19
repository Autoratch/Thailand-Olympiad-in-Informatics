#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int n,k;
vector<vector<int> > adj;
vector<int> cycle;
vector<bool> incy;
vector<bool> visited;
bool fic,cy;

void findcycle(vector<int> b,int p,int pr)
{
    vector<bool> visited(n);
    for(int i = 0;i < b.size();i++) visited[b[i]] = true;
    b.push_back(p);
    for(int i = 0;i < adj[p].size();i++)
    {
        if(!visited[adj[p][i]]){ findcycle(b,adj[p][i],p); if(fic) return; }
        else if(pr==p) continue;
        else if(adj[p][i]!=pr)
        {
            for(int j = b.size()-1;j >= 0;j--)
            {
                cycle.push_back(b[j]);
                incy[b[j]] = true;
                if(b[j]==k) cy = true;
                if(b[j]==adj[p][i]){ fic = true; return; }
            }
        }
    }
}

int solve1(int x)
{
    queue<int> q;

    q.push(x);
    visited[x] = true;
    int ans = 0;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        ans++;
        for(int i = 0;i < adj[p].size();i++)
        {
            if(visited[adj[p][i]]) continue;
            if(incy[adj[p][i]]) continue;
            visited[adj[p][i]] = true;
            q.push(adj[p][i]);
        }
    }

    return ans-1;
}

int solve2(int x)
{
    queue<int> q;

    q.push(x);
    visited[x] = true;
    int ans = 0;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        ans++;
        for(int i = 0;i < adj[p].size();i++)
        {
            if(visited[adj[p][i]]) continue;
            if(adj[p][i]==k) continue;
            visited[adj[p][i]] = true;
            q.push(adj[p][i]);
        }
    }

    return ans-1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    adj.resize(n); incy.resize(n); visited.resize(n);
    k--;
    for(int i = 0;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> tm;

    findcycle(tm,k,k);

    int mx = 0,idx = INT_MAX;

    if(cy)
    {
        for(int i = 0;i < adj[k].size();i++)
        {
            if(incy[adj[k][i]]) continue;
            int tmp = solve1(adj[k][i]);
            if(tmp>mx)
            {
                mx = tmp;
                idx = adj[k][i];
            }
            else if(tmp==mx) idx = min(idx,adj[k][i]);
        }
        for(int i = 0;i < cycle.size();i++)
        {
            if(cycle[i]==k) continue;
            int tmp = solve1(cycle[i]);
            if(tmp>mx)
            {
                mx = tmp;
                idx = adj[k][i];
            }
            else if(tmp==mx) idx = min(idx,cycle[i]);
        }
    }
    else
    {
        for(int i = 0;i < adj[k].size();i++)
        {
            int tmp = solve2(adj[k][i]);
            if(tmp>mx)
            {
                mx = tmp;
                idx = adj[k][i];
            }
            else if(tmp==mx) idx = min(idx,adj[k][i]);
        }
    }

    cout << idx+1 << endl << mx;
}
