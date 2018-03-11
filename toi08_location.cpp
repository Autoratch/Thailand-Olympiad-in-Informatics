#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n,k,mx = 0;

    cin >> m >> n >> k;

    vector<vector<int> > a(m+1);

    a[0].resize(n+1);
    for(int i = 1;i <= m;i++)
    {
        a[i].resize(n+1);
        for(int j = 1;j <= n;j++){ cin >> a[i][j]; a[i][j] = a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1]; }
    }
    for(int i = 1;i+k-1 <= m;i++) for(int j = 1;j+k-1 <= n;j++) mx = max(mx,a[i+k-1][j+k-1]+a[i-1][j-1]-a[i-1][j+k-1]-a[i+k-1][j-1]);

    cout << mx;
}
