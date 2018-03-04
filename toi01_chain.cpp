#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int l,n;

    cin >> l >> n;

    vector<string> s(n);

    for(int i = 0;i < n;i++) cin >> s[i];

    int ans = 0;

    for(int i = 1;i < n;i++)
    {
        int cn = 0;
        for(int j = 0;j < l;j++) if(s[i][j]!=s[i-1][j]) cn++;
        if(cn>2) break;
        ans = i;
    }

    cout << s[ans];
}
