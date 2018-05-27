#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int n,t = 20;
string s;
bool visited[255][255][3],dp[255][255][3];

bool solve(int l,int r,int x)
{
    if(visited[l][r][x]) return dp[l][r][x];
    visited[l][r][x] = true;
    if(l==r){ if(s[l]==x) dp[l][r][x] = 1; return dp[l][r][x]; }
    for(int i = l+1;i <= r;i++)
    {
        if(x==0)
        {
            if(solve(l,i-1,0) and solve(i,r,2)){ dp[l][r][x] = true; break; }
        }
        else if(x==1)
        {
            if(solve(l,i-1,0) and solve(i,r,1)){ dp[l][r][x] = true; break; }
            if(solve(l,i-1,1) and solve(i,r,1)){ dp[l][r][x] = true; break; }
            if(solve(l,i-1,1) and solve(i,r,2)){ dp[l][r][x] = true; break; }
            if(solve(l,i-1,2) and solve(i,r,0)){ dp[l][r][x] = true; break; }
            if(solve(l,i-1,2) and solve(i,r,2)){ dp[l][r][x] = true; break; }
        }
        else
        {
            if(solve(l,i-1,0) and solve(i,r,0)){ dp[l][r][x] = true; break; }
            if(solve(l,i-1,1) and solve(i,r,0)){ dp[l][r][x] = true; break; }
            if(solve(l,i-1,2) and solve(i,r,1)){ dp[l][r][x] = true; break; }
        }
    }
    return dp[l][r][x];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(t--)
    {
        cin >> n >> s;
        for(int i = 0;i < n;i++) for(int j = i;j < n;j++) for(int k = 0;k < 3;k++) dp[i][j][k] = visited[i][j][k] = false;
        for(int i = 0;i < n;i++) s[i]-='0';
        if(solve(0,n-1,0)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}
