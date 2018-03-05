#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int a,b;
vector<vector<vector<char> > > s1,s2;
vector<int> x1,x2;

int val(vector<vector<char> > x)
{
    if(x[0][1]==' ')
    {
        if(x[1][0]==' ') return 1;
        else return 4;
    }
    if(x[2][1]==' ') return 7;
    if(x[1][0]==' ' and x[2][0]==' ') return 3;
    if(x[1][0]==' ') return 2;
    if(x[1][1]==' ') return 0;
    if(x[2][0]==' ')
    {
        if(x[1][2]!='|') return 5;
        else return 9;
    }
    if(x[1][2]!='|') return 6;
    return 8;
}

void pl()
{
    reverse(x1.begin(),x1.end());
    reverse(x2.begin(),x2.end());
    for(int i = a;i < max(a,b);i++) x1.push_back(0);
    for(int i = b;i < max(a,b);i++) x2.push_back(0);
    vector<int> ans;
    for(int i = 0;i < max(a,b);i++)
    {
        if(x1[i]+x2[i]>9){ ans.push_back((x1[i]+x2[i])%10); if(i==max(a,b)-1) ans.push_back(1); else x1[i+1]++; }
        else ans.push_back(x1[i]+x2[i]);
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();i++) cout << ans[i];
}

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
                s1[j][i][k] = c;
            }
            getchar();
        }
    }
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < b;j++)
        {
            s2[j][i].resize(3);
            for(int k = 0;k < 3;k++)
            {
                char c;
                c = getchar();
                s2[j][i][k] = c;
            }
            getchar();
        }
    }
    for(int i = 0;i < a;i++) x1[i] = val(s1[i]);
    for(int i = 0;i < b;i++) x2[i] = val(s2[i]);
    pl();
}
