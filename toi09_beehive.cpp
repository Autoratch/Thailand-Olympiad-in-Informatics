#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n;

    cin >> m >> n;

    int a[m][n],dp[m][n],mx = 0,cnt = 0,am[m][n];

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++){ cin >> a[i][j]; dp[i][j] = 0; am[i][j] = 0; }

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(i==0){ dp[i][j] = a[i][j]; am[i][j] = 1; }
        else if(i%2==1)
        {
            int tmp = 0;
            tmp = max(tmp,dp[i-1][j]+a[i][j]);
            if(j+1<n) tmp = max(tmp,dp[i-1][j+1]+a[i][j]);
            dp[i][j] = tmp;
            if(dp[i-1][j]+a[i][j]==tmp) am[i][j]+=am[i-1][j];
            if(j+1<n) if(dp[i-1][j+1]+a[i][j]==tmp) am[i][j]+=am[i-1][j+1];
        }
        else
        {
            int tmp = 0;
            tmp = max(tmp,dp[i-1][j]+a[i][j]);
            if(j-1>=0) tmp = max(tmp,dp[i-1][j-1]+a[i][j]);
            dp[i][j] = tmp;
            if(dp[i-1][j]+a[i][j]==tmp) am[i][j]+=am[i-1][j];
            if(j-1>=0) if(dp[i-1][j-1]+a[i][j]==tmp) am[i][j]+=am[i-1][j-1];
        }
        if(i==m-1)
        {
            if(dp[i][j]>mx)
            {
                mx = dp[i][j];
                cnt = am[i][j];
            }
            else if(dp[i][j]==mx) cnt+=am[i][j];
        }
    }

    cout << mx << ' ' << cnt;
}
