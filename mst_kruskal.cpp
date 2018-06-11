#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7
#define pii pair<int,pair<int,int> >

int n,m;
vector<int> pa;
priority_queue<pii,vector<pii>,greater<pii> > q;

int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x] = root(pa[x]);
}

int kruskal()
{
    int ans = 0;

    pa.resize(n);
    for(int i = 0;i < n;i++) pa[i] = i;

    while(!q.empty())
    {
        int w = q.top().first,x = q.top().second.first,y = q.top().second.second;
        q.pop();
        if(root(x)==root(y)) continue;
        ans+=w;
        pa[root(x)] = pa[root(y)];
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        q.push({d,{a,b}});
    }

    cout << kruskal();
}
