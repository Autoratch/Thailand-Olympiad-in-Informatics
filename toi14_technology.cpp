#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n,k,t;
vector<int> lv,pa;
vector<bool> notcy;
vector<vector<int> > adj;
queue<pair<int,int> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> t;

    adj.resize(n);
    lv.resize(n);
    pa.resize(n);
    notcy.resize(n);

    for(int i = 0;i < n;i++)
    {
        cin >> lv[i];
        int tmp;
        cin >> tmp;
        while(tmp--)
        {
            int tm;
            cin >> tm;
            tm--;
            adj[i].push_back(tm);
            pa[tm]++;
        }
    }

    for(int i = 0;i < n;i++) if(!pa[i]) q.push({i,lv[i]});

    while(!q.empty())
    {
        int p = q.front().first,l = q.front().second;
        q.pop();
        if(notcy[p]) continue;
        notcy[p] = true;
        l = min(l,lv[p]);
        lv[p] = l;
        for(int i = 0;i < adj[p].size();i++)
        {
            if(notcy[adj[p][i]] or pa[adj[p][i]]==0) continue;
            pa[adj[p][i]]--;
            if(pa[adj[p][i]]==0) q.push({adj[p][i],l});
        }
    }

    adj.clear();
    adj.resize(k+1);
    int mx = k+1,tmp = 0;

    for(int i = 0;i < n;i++) if(!notcy[i]) mx = min(mx,lv[i]); else adj[lv[i]].push_back(i);
    mx--;

    for(int i = 1;i <= mx;i++)
    {
        tmp+=adj[i].size();
        if(tmp>t){ mx = i-1; break; }
    }

    if(mx==0) cout << "-1";
    else cout << mx;
}
