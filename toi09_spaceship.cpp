#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int k,n,ans = INT_MAX;
int sx,sy,sz;
vector<int> x,y,z;
vector<int> a,b,c;

void dfs(int p,int visited,int ua,int ub,int uc,int dist)
{
    if(ua>=k and ub>=k and uc>=k){ ans = min(ans,dist); return; }
    vector<bool> t(n+1,false);
    int cnt = 0;
    int tmp = visited;
    while(tmp)
    {
        t[cnt] = tmp%2;
        tmp = tmp>>1; cnt++;
    }
    for(int i = 1;i <= n;i++) if(!t[i]) dfs(i,visited+(1<<i),ua+a[i],ub+b[i],uc+c[i],dist+(x[p]-x[i])*(x[p]-x[i])+(y[p]-y[i])*(y[p]-y[i])+(z[p]-z[i])*(z[p]-z[i]));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> sx >> sy >> sz >> n;

    x.resize(n+1); y.resize(n+1); z.resize(n+1);
    a.resize(n+1); b.resize(n+1); c.resize(n+1);

    x[0] = sx; y[0] = sy; z[0] = sz;
    for(int i = 1;i <= n;i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        cin >> a[i] >> b[i] >> c[i];
    }

    dfs(0,1,0,0,0,0);

    cout << ans;
}
