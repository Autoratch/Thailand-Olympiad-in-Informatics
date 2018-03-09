#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

vector<string> s;
int m,n;

int pof(int x,int y,int sz)
{
    vector<vector<bool> > visited(x+sz);

    for(int i = x;i < x+sz;i++) visited[i].assign(y+sz,false);

    int cn = 0;

    queue<pair<int,int> > q;

    for(int i = x;i < x+sz;i++) for(int j = y;j < y+sz;j++)
    {
        if(visited[i][j]) continue;
        if(s[i-1][j-1]!='P') continue;
        cn++;
//        cout << i << ' ' << j << ' ' << cn << endl;
        q.push({i,j});
        while(!q.empty())
        {
            int a = q.front().first,b = q.front().second;
            q.pop();
            for(int k = -1;k <= 1;k++) for(int l = -1;l <= 1;l++)
            {
                if(k==0 and l==0) continue;
                if(k!=0 and l!=0) continue;
                int ax = a+k,ay = b+l;
                if(ax<x or ax>=x+sz or ay<y or ay>=y+sz) continue;
                if(visited[ax][ay]) continue;
                if(s[ax-1][ay-1]!='P') continue;
                visited[ax][ay] = true;
                q.push({ax,ay});
            }
        }
    }

    return cn;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    s.resize(m);
    vector<vector<int> > p(m+1),t(m+1);

    for(int i = 0;i < m;i++) cin >> s[i];
    for(int i = 0;i <= m;i++){ p[i].resize(n+1); t[i].resize(n+1); }

    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1];
        t[i][j] = t[i-1][j]+t[i][j-1]-t[i-1][j-1];
        if(s[i-1][j-1]=='P') p[i][j]++;
        else if(s[i-1][j-1]=='T') t[i][j]++;
    }

    int ans = 0,po = INT_MAX;

    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) for(int k = 1;i+k-1 <= m and j+k-1 <= n;k++)
    {
        if(t[i+k-1][j+k-1]+t[i-1][j-1]-t[i+k-1][j-1]-t[i-1][j+k-1]) break;
        int tmp = pof(i,j,k);
        if(k*k>ans)
        {
            ans = k*k;
            po = tmp;
        }
        else if(k*k==ans) po = min(po,tmp);
  //      cout << i << ' ' << j << ' ' << k << ' ' << ans << ' ' << po << endl;
    }

    if(po==INT_MAX) po = 0;

    cout << ans << ' ' << po;
}
