#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tst = 2,m,n;
    vector<vector<int> > a;

    while(tst--)
    {
        cin >> m >> n;
        int s;
        cin >> s;
        a.resize(m+1);
        for(int i = 0;i <= m;i++) a[i].assign(n+1,0);
        while(s--)
        {
            int x,y;
            cin >> x >> y;
            a[x+1][y+1] = 1;
        }
        for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) a[i][j] = a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        int mx = 0;
        for(int i = 1;i <= m;i++) for(int j = 1;j <= m;j++)
        {
            int sz = min(m-i+1,n-j+1);
            if(sz<mx) continue;
            for(int k = 1;k <= sz;k++)
            {
                int all = a[i+k-1][j+k-1]+a[i-1][j-1]-a[i-1][j+k-1]-a[i+k-1][j-1];
                int in = a[i+k-2][j+k-2]+a[i][j]-a[i][j+k-2]-a[i+k-2][j];
                if(all-in==0) mx = max(mx,k);
            }
        }
        cout << mx << endl;
    }
}
