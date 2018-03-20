#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int n,k,st;
vector<vector<int> > adj;
vector<int> cycle;
vector<bool> incy;
vector<bool> visited,visit;
bool fic,cy,fin;

bool findcycle(int p,int pr)
{
    vector<bool> visited = visit;
    visited[p] = true;
    visit[p] = true;
    for(int i = 0;i < adj[p].size();i++)
    {
        if(!visited[adj[p][i]])
        {
            if(findcycle(adj[p][i],p))
            {
                if(adj[p][i]==st or fin){ fin = true; return true; }
                else{ cycle.push_back(adj[p][i]); incy[adj[p][i]] = true; return true; }
            }
            else if(fin or fic) return false;
        }
        else if(pr==p) continue;
        else if(adj[p][i]!=pr)
        {
            fic = true;
            st = adj[p][i];
            cycle.push_back(st);
            if(st==k) cy = true;
            incy[st] = true;
            return true;
        }
    }
    return false;
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

    adj.resize(n); incy.resize(n); visited.resize(n); visit.resize(n);
    k--;
    for(int i = 0;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    findcycle(k,k);

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
