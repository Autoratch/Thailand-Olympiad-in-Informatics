#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int a[300][300],m,n,ans;
vector<int> len;
queue<pair<pair<int,int>,pair<int,int> > > q;

void solve(int sx,int sy,char sd)
{
    while(!q.empty()) q.pop();

    if(sd=='u') q.push({{sx,sy},{sx-1,sy}});
    if(sd=='d') q.push({{sx,sy},{sx+1,sy}});
    if(sd=='l') q.push({{sx,sy},{sx,sy-1}});
    if(sd=='r') q.push({{sx,sy},{sx,sy+1}});

    int tmp = 0;

    while(!q.empty())
    {
        int x = q.front().first.first,y = q.front().first.second,ax,ay,px = q.front().second.first,py = q.front().second.second;
        q.pop();
        if(x<0 or x>=m or y<0 or y>=n) return;
        tmp++;
        if(tmp>1)
        {
            if(x==0 and (a[x][y]==11 or a[x][y]==12 or a[x][y]==21 or px==x+1 and a[x][y]==31))
            {
                len.push_back(tmp);
                if(a[x][y]==31)
                {
                    if(px!=x) a[x][y] = 22;
                    else a[x][y] = 21;
                }
                else a[x][y] = 0;
                return;
            }
            if(x==m-1 and (a[x][y]==13 or a[x][y]==14 or a[x][y]==21 or px==x-1 and a[x][y]==31))
            {
                len.push_back(tmp);
                if(a[x][y]==31)
                {
                    if(px!=x) a[x][y] = 22;
                    else a[x][y] = 21;
                }
                else a[x][y] = 0;
                return;
            }
            if(y==0 and (a[x][y]==11 or a[x][y]==13 or a[x][y]==22 or py==y+1 and a[x][y]==31))
            {
                len.push_back(tmp);
                if(a[x][y]==31)
                {
                    if(px!=x) a[x][y] = 22;
                    else a[x][y] = 21;
                }
                else a[x][y] = 0;
                return;
            }
            if(y==n-1 and (a[x][y]==12 or a[x][y]==14 or a[x][y]==22 or py==y-1 and a[x][y]==31))
            {
                len.push_back(tmp);
                if(a[x][y]==31)
                {
                    if(px!=x) a[x][y] = 22;
                    else a[x][y] = 21;
                }
                else a[x][y] = 0;
                return;
            }
        }
        else
        {
            if(x==0 and y==0 and a[x][y]==11){ len.push_back(tmp); a[x][y] = 0; return; }
            if(x==m-1 and y==0 and a[x][y]==13){ len.push_back(tmp); a[x][y] = 0; return; }
            if(x==0 and y==n-1 and a[x][y]==12){ len.push_back(tmp); a[x][y] = 0; return; }
            if(x==m-1 and y==n-1 and a[x][y]==14){ len.push_back(tmp); a[x][y] = 0; return; }
            if(x==0 and m==1 and px==x-1 and (a[x][y]==21 or a[x][y]==31))
            {
                len.push_back(tmp);
                if(a[x][y]==31)
                {
                    if(px!=x) a[x][y] = 22;
                    else a[x][y] = 21;
                }
                else a[x][y] = 0;
                return;
            }
            if(y==0 and n==1 and py==y-1 and (a[x][y]==22 or a[x][y]==31))
            {
                len.push_back(tmp);
                if(a[x][y]==31)
                {
                    if(px!=x) a[x][y] = 22;
                    else a[x][y] = 21;
                }
                else a[x][y] = 0;
                return;
            }
        }
        if(a[x][y]==11)
        {
            ax = x-1; ay = y;
            if(ax!=px or ay!=py)
            {
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
            else
            {
                ax = x; ay = y-1;
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
        }
        if(a[x][y]==12)
        {
            ax = x-1; ay = y;
            if(ax!=px or ay!=py)
            {
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
            else
            {
                ax = x; ay = y+1;
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
        }
        if(a[x][y]==13)
        {
            ax = x+1; ay = y;
            if(ax!=px or ay!=py)
            {
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
            else
            {
                ax = x; ay = y-1;
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
        }
        if(a[x][y]==14)
        {
            ax = x+1; ay = y;
            if(ax!=px or ay!=py)
            {
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
            else
            {
                ax = x; ay = y+1;
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
        }
        if(a[x][y]==21)
        {
            ax = x+1; ay = y;
            if(ax!=px or ay!=py)
            {
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
            else
            {
                ax = x-1; ay = y;
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
        }
        if(a[x][y]==22)
        {
            ax = x; ay = y+1;
            if(ax!=px or ay!=py)
            {
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
            else
            {
                ax = x; ay = y-1;
                q.push({{ax,ay},{x,y}});
                a[x][y] = 0;
                continue;
            }
        }
        if(a[x][y]==31)
        {
            if(px==x-1 and py==y)
            {
                ax = x+1; ay = y;
                q.push({{ax,ay},{x,y}});
                a[x][y] = 22;
                continue;
            }
            if(px==x+1 and py==y)
            {
                ax = x-1; ay = y;
                q.push({{ax,ay},{x,y}});
                a[x][y] = 22;
                continue;
            }
            if(px==x and py==y-1)
            {
                ax = x; ay = y+1;
                q.push({{ax,ay},{x,y}});
                a[x][y] = 21;
                continue;
            }
            if(px==x and py==y+1)
            {
                ax = x; ay = y-1;
                q.push({{ax,ay},{x,y}});
                a[x][y] = 21;
                continue;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];
    for(int i = 0;i < n;i++)
    {
        if(!(a[0][i]==11 or a[0][i]==12 or a[0][i]==21 or a[0][i]==31)) continue;
        solve(0,i,'u');
        ans++;
    }
    for(int i = 0;i < n;i++)
    {
        if(!(a[m-1][i]==13 or a[m-1][i]==14 or a[m-1][i]==21 or a[m-1][i]==31)) continue;
        solve(m-1,i,'d');
        ans++;
    }
    for(int i = 0;i < m;i++)
    {
        if(!(a[i][0]==11 or a[i][0]==13 or a[i][0]==22 or a[i][0]==31)) continue;
        solve(i,0,'l');
        ans++;
    }
    for(int i = 0;i < m;i++)
    {
        if(!(a[i][n-1]==12 or a[i][n-1]==14 or a[i][n-1]==22 or a[i][n-1]==31)) continue;
        solve(i,n-1,'r');
        ans++;
    }

    cout << ans << endl;

    for(int i = 0;i < ans;i++) cout << len[i] << ' ';
}
