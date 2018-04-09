#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int m,n,q,ans;
vector<string> s;
vector<vector<bool> > visited;

bool bmb()
{
    queue<pair<int,int> > q;
    bool chg = false;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) if(s[i][j]>='A' and s[i][j]<='Z')
    {
        q.push({i,j});
        int cnt = 0;
        for(int k = 0;k < m;k++) visited[k].assign(n,false);
        visited[i][j] = true;
        while(!q.empty())
        {
            int x = q.front().first,y = q.front().second;
            q.pop();
            cnt++;
            for(int a = -1;a <= 1;a++) for(int b = -1;b <= 1;b++)
            {
                if(a==0 and b==0) continue;
                if(a!=0 and b!=0) continue;
                int ai = x+a,aj = y+b;
                if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
                if(visited[ai][aj]) continue;
                if(s[ai][aj]!=s[i][j]) continue;
                visited[ai][aj] = true;
                q.push({ai,aj});
                s[ai][aj] = '-';
            }
        }
        if(cnt>1)
        {
            ans+=(cnt*5);
            s[i][j] = '-';
            chg = true;
        }
    }

    return chg;
}

void fll()
{
    for(int i = 1;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(s[i][j]!='-') continue;
        if(!(s[i-1][j]>='A' and s[i-1][j]<='Z')) continue;
        int x = i,y = j;
        while(true)
        {
            s[x][y] = s[x-1][y];
            s[x-1][y] = '-';
            x--;
            if(x==0) break;
            if(s[x-1][y]=='-') break;
            if(s[x-1][y]=='#') break;
        }
    }
}

void mov(int x,int y,char c)
{
    if(c=='L') s[x][y-1] = s[x][y];
    else s[x][y+1] = s[x][y];
    s[x][y] = '-';
    while(true)
    {
        fll();
        if(!bmb()) break;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    s.resize(m);
    visited.resize(m);
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        char x;
        cin >> x;
        s[i].push_back(x);
    }

    cin >> q;

    while(q--)
    {
        int x,y;
        char c;
        cin >> x >> y >> c;
        bool ok = true;
        if(s[x][y]=='-') ok = false;
        else if(s[x][y]=='#') ok = false;
        else
        {
            if(c=='L')
            {
                if(s[x][y-1]!='-') ok = false;
            }
            else
            {
                if(s[x][y+1]!='-') ok = false;
            }
        }
        if(!ok) ans-=5;
        else mov(x,y,c);
    }

    cout << ans << endl;

    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++) cout << s[i][j] << ' ';
        cout << endl;
    }
}
