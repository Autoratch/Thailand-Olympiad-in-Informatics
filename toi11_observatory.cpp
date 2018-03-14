#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n,k;

    cin >> m >> n >> k;

    vector<vector<int> > a(m+1),s(m+1),l(m+1),r(m+1),t(m+1);

    for(int i = 0;i <= m;i++)
    {
        a[i].resize(n+2);
        s[i].resize(n+2);
        l[i].resize(n+2);
        r[i].resize(n+2);
        t[i].resize(n+2);
        if(i==0) continue;
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        s[i][j] = a[i][j]+s[i][j-1]+s[i-1][j]-s[i-1][j-1];
        l[i][j] = l[i-1][j-1]+s[i][j]-s[i-1][j];
    }

    for(int i = 1;i <= m;i++) for(int j = n;j >= 1;j--)
    {
        t[i][j] = a[i][j]+t[i][j+1]+t[i-1][j]-t[i-1][j+1];
        r[i][j] = r[i-1][j+1]+t[i][j]-t[i-1][j];
    }

    int mx = INT_MIN;

    for(int i = k;i <= m;i++) for(int j = k;j <= n;j++) mx = max(mx,l[i][j]-l[i-k][j-k]-s[i][j-k]+s[i-k][j-k]);
    for(int i = k;i <= m;i++) for(int j = 1;j+k-1 <= n;j++) mx = max(mx,r[i][j]-r[i-k][j+k]-t[i][j+k]+t[i-k][j+k]);

    cout << mx;
}
