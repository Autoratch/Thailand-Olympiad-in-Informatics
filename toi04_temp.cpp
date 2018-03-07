#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,x,y;

    cin >> n >> y >> x;
    x--; y--;

    vector<vector<int> > a(n);

    for(int i = 0;i < n;i++)
    {
        a[i].resize(n);
        for(int j = 0;j < n;j++) cin >> a[i][j];
    }

    int ans = 0;

    queue<pair<int,int> > q;

    q.push({x,y});

    while(!q.empty())
    {
        x = q.front().first; y = q.front().second;
        q.pop();
        ans = max(ans,a[x][y]);
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=n or aj<0 or aj>=n) continue;
            if(a[ai][aj]==100) continue;
            if(a[ai][aj]<=a[x][y]) continue;
            q.push({ai,aj});
        }
    }

    cout << ans;
}
