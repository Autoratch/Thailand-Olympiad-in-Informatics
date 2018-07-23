#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n,k,t,m,ans,cnt;
vector<int> lv,de;
vector<vector<int> > adj,s;

int dfs(int p)
{
    cnt++;
    de[p] = 2;
    for(int i = 0;i < adj[p].size();i++)
    {
        if(de[adj[p][i]]==2){ cnt = 1e6; return 0; }
        else if(de[adj[p][i]]==0) dfs(adj[p][i]);
    }
    de[p] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> t;

    adj.resize(n);
    lv.resize(n);
    de.resize(n);
    s.resize(k+1);

    for(int i = 0;i < n;i++)
    {
        cin >> lv[i] >> m;
        s[lv[i]].push_back(i);
        while(m--)
        {
            int u;
            cin >> u;
            u--;
            adj[i].push_back(u);
        }
    }

    for(int i = 1;i <= k;i++)
    {
        for(int j = 0;j < s[i].size();j++) if(!de[s[i][j]]) dfs(s[i][j]);
        if(cnt>t) break;
        ans = i;
    }

    if(ans==0) cout << "-1";
    else cout << ans;
}
