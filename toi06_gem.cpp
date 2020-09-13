#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 1;

int n,m;
vector<int> adj[N],rev[N];
stack<int> st;
set<int> now;
bool visited[N];

void dfs(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    for(int v : adj[u]) dfs(v);
    st.push(u);
}

void dfs2(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    now.insert(u);
    for(int v : rev[u]) dfs2(v);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 5;
    while(t--)
    {
        cin >> m >> n;
        for(int i = 1;i <= n*2;i++) adj[i].clear(),rev[i].clear(),visited[i] = false;
        for(int i = 1;i <= m;i++)
        {
            int a,b;
            cin >> a >> b;
            adj[a+n].push_back(b);
            adj[b+n].push_back(a);
            rev[b].push_back(a+n);
            rev[a].push_back(b+n);
        }
        for(int i = 1;i <= n/2;i++)
        {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b+n);
            adj[b].push_back(a+n);
            rev[b+n].push_back(a);
            rev[a+n].push_back(b);
        }
        for(int i = 1;i <= n*2;i++) if(!visited[i]) dfs(i);
        for(int i = 1;i <= n*2;i++) visited[i] = false;
        bool ok = true;
        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            if(visited[u]) continue;
            now.clear();
            dfs2(u);
            for(int x : now) if(now.find(x+n)!=now.end()) ok = false;       
        }
        if(ok) cout << 'Y';
        else cout << 'N';
    }
}
