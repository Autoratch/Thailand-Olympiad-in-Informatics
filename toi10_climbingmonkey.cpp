#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n,k,s,mxa = 0;

    cin >> m >> n >> k;

    vector<int> a(n);
    vector<vector<pair<int,int> > > adj(n);

    for(int i = 0;i < n;i++){ cin >> a[i]; mxa = max(mxa,a[i]); }
    for(int i = 0;i < k;i++)
    {
        int idx,h;
        cin >> idx >> h;
        adj[idx-1].push_back({h,1});
        adj[idx].push_back({h,-1});
    }

    for(int i = 0;i < n;i++) sort(adj[i].begin(),adj[i].end());

    cin >> s; s--;

    queue<pair<pair<int,int>,bool> > q;

    int mx = 0,us;

    q.push({{s,0},0});

    while(!q.empty())
    {
        int p = q.front().first.first,h = q.front().first.second;
        bool used = q.front().second;
        q.pop();
        auto it = lower_bound(adj[p].begin(),adj[p].end(),make_pair(h,2));
        if(it==adj[p].end())
        {
            if(a[p]>mx){ mx = a[p]; us = used; }
            if(used) continue;
        }
        if(!used)
        {
            if(p>0)
            {
                auto it2 = lower_bound(adj[p-1].begin(),adj[p-1].end(),make_pair(h,2));
                if(it!=adj[p].end()) for(;it2-1 != adj[p-1].end() and it2->first<it->first;it2++)
                {
                    q.push({{p-1,it2->first-1},true});
                    auto it3 = it2; it3++;
                    if(it3==adj[p-1].end()) q.push({{p-1,it2->first},true});
                }
                else for(;it2 != adj[p-1].end();it2++)
                {
                    q.push({{p-1,it2->first-1},true});
                    auto it3 = it2; it3++;
                    if(it3==adj[p-1].end()) q.push({{p-1,it2->first},true});
                }
            }
            if(p+1<n)
            {
                auto it2 = lower_bound(adj[p+1].begin(),adj[p+1].end(),make_pair(h,2));
                if(it!=adj[p].end()) for(;it2-1 != adj[p+1].end() and it2->first<it->first;it2++)
                {
                    q.push({{p+1,it2->first-1},true});
                    auto it3 = it2; it3++;
                    if(it3==adj[p+1].end()) q.push({{p+1,it2->first},true});
                }
                else for(;it2 != adj[p+1].end();it2++)
                {
                    q.push({{p+1,it2->first-1},true});
                    auto it3 = it2; it3++;
                    if(it3==adj[p+1].end()) q.push({{p+1,it2->first},true});
                }
            }
        }
        if(it!=adj[p].end()) q.push({{p+(it->second),it->first},used});
    }

    cout << mx;
    if(us) cout << "\nUSE";
    else cout << "\nNO";
}
