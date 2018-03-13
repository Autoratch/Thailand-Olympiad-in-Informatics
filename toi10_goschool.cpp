#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n,k;

    cin >> m >> n >> k;

    vector<vector<long long> > a(m);

    for(int i = 0;i < m;i++) a[i].resize(n);
    for(int i = 0;i < k;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x-1][y-1] = -1;
    }

    bool f = false;

    for(int i = 0;i < m;i++)
    {
        if(a[i][0]==-1) f = true;
        if(f) a[i][0] = 0;
        else a[i][0] = 1;
    }

    f = false;

    for(int i = 0;i < n;i++)
    {
        if(a[0][i]==-1) f = true;
        if(f) a[0][i] = 0;
        else a[0][i] = 1;
    }

    for(int i = 1;i < m;i++) for(int j = 1;j < n;j++)
    {
        if(a[i][j]==-1) a[i][j] = 0;
        else a[i][j] = a[i-1][j]+a[i][j-1];
    }

    cout << a[m-1][n-1];
}
