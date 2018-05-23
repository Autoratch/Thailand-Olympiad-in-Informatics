#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int m,n,mx,cnt,dp[1000][1000],t[1000][1000],a[1000][1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++){ cin >> a[i][j]; dp[i][j] = a[i][j]; t[i][j] = 1; }
    for(int i = 1;i < m;i++) for(int j = 0;j < n;j++)
    {
        for(int k = -1;k <= 1;k++)
        {
            int ai = j+k;
            if(i%2==0 and k==1) continue;
            if(i%2==1 and k==-1) continue;
            if(ai<0 or ai>=n) continue;
            if(dp[i-1][ai]+a[i][j]>dp[i][j])
            {
                dp[i][j] = dp[i-1][ai]+a[i][j];
                t[i][j] = t[i-1][ai];
            }
            else if(dp[i-1][ai]+a[i][j]==dp[i][j]) t[i][j]+=t[i-1][ai];
        }
        if(dp[i][j]>mx){ mx = dp[i][j]; cnt = t[i][j]; }
        else if(dp[i][j]==mx) cnt+=t[i][j];
    }

    cout << mx << ' ' << cnt;
}
