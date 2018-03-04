#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

vector<vector<char> > s(50001);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;

    cin >> q;

    int m = 0,n = 70;

    for(int i = 0;i <= 50000;i++) s[i].resize(200);

    while(q--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        m = max(m,a);
        for(int i = b;i < b+c;i++) s[a][i] = 'x';
    }

    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++) if(s[i][j]=='x') cout << 'x'; else cout << 'o';
        cout << endl;
    }
}
