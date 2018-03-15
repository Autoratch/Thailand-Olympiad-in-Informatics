#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

string s;
int dp[256][256][3],n;

int solve(int l,int r,int x)
{
    if(dp[l][r][x]>0) return dp[l][r][x];
    if(l==r)
    {
        int tmp;
        if(s[l]-'0'==x) tmp = 1;
        else tmp = 2;
        dp[l][r][x] = tmp;
//    cout << l << ' ' << x << ' ' << dp[l][r][x] << endl;
        return dp[l][r][x];
    }
    if(x==0)
    {
        for(int i = l+1;i <= r;i++)
        {
            if(solve(l,i-1,0)==1 and solve(i,r,2)==1)
            {

//                cout << l << ' ' << i << ' ' << r << ' ' << dp[l][r][x] << endl;
                dp[l][r][x] = 1;
                return 1;
            }
        }
        dp[l][r][x] = 2;
        return dp[l][r][x];
    }
    if(x==1)
    {
        for(int i = l+1;i <= r;i++)
        {
            if(solve(l,i-1,0)==1 and solve(i,r,1)==1)
            {
                dp[l][r][x] = 1;
                return 1;
            }
            if(solve(l,i-1,1)==1 and solve(i,r,1)==1)
            {
                dp[l][r][x] = 1;
                return 1;
            }
            if(solve(l,i-1,1)==1 and solve(i,r,2)==1)
            {
                dp[l][r][x] = 1;
                return 1;
            }
            if(solve(l,i-1,2)==1 and solve(i,r,0)==1)
            {
                dp[l][r][x] = 1;
                return 1;
            }
            if(solve(l,i-1,2)==1 and solve(i,r,2)==1)
            {
                dp[l][r][x] = 1;
                return 1;
            }
        }
        dp[l][r][x] = 2;
        return dp[l][r][x];
    }
    if(x==2)
    {
        for(int i = l+1;i <= r;i++)
        {
            if(solve(l,i-1,0)==1 and solve(i,r,0)==1)
            {
                dp[l][r][x] = 1;
                return 1;
            }
            if(solve(l,i-1,1)==1 and solve(i,r,0)==1)
            {
                dp[l][r][x] = 1;
                return 1;
            }
            if(solve(l,i-1,2)==1 and solve(i,r,1)==1)
            {
                dp[l][r][x] = 1;
                return 1;
            }
        }
        dp[l][r][x] = 2;
        return dp[l][r][x];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tst = 20;

    while(tst--)
    {
        cin >> n >> s;
        for(int i = 0;i < n;i++) for(int j = i;j < n;j++) for(int k = 0;k < 3;k++) dp[i][j][k] = 0;
        if(solve(0,n-1,0)==1) cout << "yes\n";
        else cout << "no\n";
//        for(int i = 0;i < n;i++) for(int j = i;j < n;j++) for(int k = 0;k < 3;k++) cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
    }
}
