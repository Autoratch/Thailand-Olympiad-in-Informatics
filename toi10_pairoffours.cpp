#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int dp[1000][1000],n;
char a[1000];

int solve(int l,int r)
{
    if(dp[l][r]>-1) return dp[l][r];
    int tmp = 0;
    if(l==r) tmp = 0;
    else if(l+1==r and a[l]==a[r]) tmp = 1;
    else if(l+1==r) tmp = 0;
    else if(a[l]==a[r]) tmp = solve(l+1,r-1)+1;
    else for(int i = l+1;i <= r;i++) tmp = max(tmp,solve(l,i-1)+solve(i,r));
    dp[l][r] = tmp;
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) dp[i][j] = -1;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << solve(0,n-1);
/*
    cout << endl;
    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cout << i << ' ' << j << ' ' << dp[i][j] << endl;
*/
}
