#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int m,n;
vector<vector<double> > a;
double mn = INT_MAX;

void solve(vector<vector<double> > b,int lv,double val)
{
    if(lv==m*n){ if(val<mn) mn = val; return; }
    vector<vector<double> > c;
    c = b;
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(b[i][j]==0) continue;
        int x = i,y = j;
        for(int k = -1;k <= 1;k++) for(int l = -1;l <= 1;l++)
        {
            if(k==0 and l==0) continue;
            int ax = x+k,ay = y+l;
            if(ax<0 or ax>=m or ay<0 or ay>=n) continue;
            if(b[ax][ay]==0) continue;
            b[ax][ay]+=(b[i][j]/10.0);
        }
        double tmp = b[i][j];
        b[i][j] = 0;
        solve(b,lv+1,val+tmp);
        b = c;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    a.resize(m);

    for(int i = 0;i < m;i++)
    {
        a[i].resize(n);
        for(int j = 0;j < n;j++) cin >> a[i][j];
    }

    solve(a,0,0.0);

    cout << fixed;
    cout << setprecision(2) << mn;
}
