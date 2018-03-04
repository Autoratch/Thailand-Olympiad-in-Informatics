#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n;

    cin >> m >> n;

    vector<string> s(m);

    for(int i = 0;i < m;i++) cin >> s[i];

    for(int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        if(s[0][i]=='O') continue;
        int f = 0;
        while(true)
        {
            if(s[f][i]=='O') break;
            f++;
            if(f>=m) break;
        }
        if(f==m) continue;
        int x = f-1,cn = 0;
        while(true)
        {
            if(cn==a) break;
            if(x<0) break;
            s[x][i] = '#';
            cn++; x--;
        }
    }

    for(int i = 0;i < m;i++) cout << s[i] << endl;
}
