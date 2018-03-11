#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n,sx,sy,ex,ey;

    cin >> m >> n >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;

    bool a[m][n];
    int d[m][n],b[m][n];
    queue<pair<int,int> > q;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++){ cin >> a[i][j]; d[i][j] = 0; b[i][j] = 0; }

    q.push({sx,sy});
    d[sx][sy] = 1;

    while(!q.empty())
    {
        int x = q.front().first,y = q.front().second;
        q.pop();
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(d[ai][aj]>0) continue;
            d[ai][aj] = d[x][y]+1;
            if(a[ai][aj]) q.push({ai,aj});
        }
    }

    int mn = INT_MAX,cnt = 0;

    q.push({ex,ey});
    b[ex][ey] = 1;

    while(!q.empty())
    {
        int x = q.front().first,y = q.front().second;
        q.pop();
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(b[ai][aj]>0) continue;
            if(d[ai][aj]>0){ mn = min(mn,b[x][y]+d[ai][aj]); cnt++; /*cout << x << ' ' << y << ' ' << b[x][y] << ' ' << ai << ' ' << aj << ' ' << d[ai][aj] << endl;*/ }
            b[ai][aj] = b[x][y]+1;
            if(a[ai][aj]) q.push({ai,aj});
        }
    }
/*
cout << endl;
    for(int i = 0;i < m;i++){ for(int j = 0;j < n;j++) cout << d[i][j] << ' '; cout << endl; }
*/
    cout << cnt << endl << mn;
}
