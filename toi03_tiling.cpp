#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int a[17][17],n,ans;
bool visited[17][17];

void bfs(int x,int y)
{
    queue<pair<int,int> > q;
    vector<pair<int,int> > di;

    q.push({x,y});
    visited[x][y] = true;
    int cn = 0;

    while(!q.empty())
    {
        x = q.front().first,y = q.front().second;
        q.pop();
        cn++;
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj= y+j;
            if(ai<0 or ai>=n or aj<0 or aj>=n) continue;
            if(a[ai][aj]!=a[x][y]) continue;
            if(visited[ai][aj]) continue;
            di.push_back({i,j});
            q.push({ai,aj});
            visited[ai][aj] = true;
        }
    }
    if(cn!=3) return;
    if(di[0]==di[1]) return;
    ans++;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> a[i][j];
    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
    {
        if(visited[i][j]) continue;
        if(a[i][j]==0) continue;
        bfs(i,j);
    }

    cout << ans;
}
