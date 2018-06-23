#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int m,n,a,b,c;
bool visited[1000][1000];
vector<string> s;
queue<pair<int,int> > q;

void solve(int x,int y)
{
    q.push({x,y});
    int ul = INT_MAX,lr = 0,cu = 0,cl = 0;
    while(!q.empty())
    {
        x = q.front().first; y = q.front().second;
        q.pop();
        if(x+y<ul){ ul = x+y; cu = 1; }
        else if(x+y==ul) cu++;
        if(x+y>lr){ lr = x+y; cl = 1; }
        else if(x+y==lr) cl++;
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ax = x+i,ay = y+j;
            if(ax<0 or ax>=m or ay<0 or ay>=n) continue;
            if(s[ax][ay]=='0') continue;
            if(visited[ax][ay]) continue;
            visited[ax][ay] = true;
            q.push({ax,ay});
        }
    }
    if(cu==1 and cl==1) a++;
    else if(cu==1 or cl==1) c++;
    else b++;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    s.resize(m);

    for(int i = 0;i < m;i++) cin >> s[i];
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(s[i][j]=='0') continue;
        if(visited[i][j]) continue;
        visited[i][j] = true;
        solve(i,j);
    }

    cout << a << ' ' << b << ' ' << c;
}
