#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> dp(n+20,INT_MAX);

    dp[0] = 0;

    for(int i = 1;i <= n+15;i++)
    {
        dp[i] = min(dp[max(i-1,0)]+500,dp[i]);
        dp[i] = min(dp[max(i-2,0)]+800,dp[i]);
        dp[i] = min(dp[max(i-5,0)]+1500,dp[i]);
        dp[i] = min(dp[max(i-15,0)]+3000,dp[i]);
    }

    int ans = INT_MAX;

    for(int i = n;i <= n+15;i++) ans = min(ans,dp[i]);

    cout << ans;
}
