#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a,b;
    int n;

    cin >> a >> b >> n;

    bool dp[a.length()+1][b.length()+1];

    while(n--)
    {
        string s;
        cin >> s;
        for(int i = 0;i <= a.length();i++) for(int j = 0;j <= b.length();j++)
        {
            if(i==0 and j==0) dp[i][j] = 1;
            else if(i==0) dp[i][j] = dp[i][j-1] & b[j-1]==s[i+j-1];
            else if(j==0) dp[i][j] = dp[i-1][j] & a[i-1]==s[i+j-1];
            else dp[i][j] = (dp[i][j-1] & b[j-1]==s[i+j-1])|(dp[i-1][j] & a[i-1]==s[i+j-1]);
        }
        if(dp[a.length()][b.length()]) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
}
