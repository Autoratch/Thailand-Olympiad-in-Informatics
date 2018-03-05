#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int a,b;
vector<vector<char> > > s1,s2;
vector<int> x1,x2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;

    s1.resize(a); s2.resize(b);
    x1.resize(a); x2.resize(b);

    for(int i = 0;i < a;i++) s1[i].resize(3);
    for(int i = 0;i < b;i++) s2[i].resize(3);

    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < a;j++)
        {
            s1[j][i].resize(3);
            for(int k = 0;k < 3;k++)
            {
                char c;
                c = getchar();
                s[j][i][k] = c;
            }
        }
        getchar();
    }

    for(int i = 0;i < a;i++) x1[i] = val(s1[i]);
    for(int i = 0;i < b;i++) x2[i] = val(s2[i]);

    pl();
}
