#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int m,n,q;
string s;
vector<string> a;

bool ch(int x,int y)
{
    for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
    {
        if(i==0 and j==0) continue;
        if(i==-1 and x<s.length()-1) continue;
        if(i==1 and m-x<s.length()) continue;
        if(j==-1 and y<s.length()-1) continue;
        if(j==1 and n-y<s.length()) continue;
        bool ok = true;
        int ai = x,aj = y;
        for(int k = 0;k < s.length();k++)
        {
            if(s[k]!=a[ai][aj]){ ok = false; break; }
            ai+=i; aj+=j;
        }
        if(ok) return true;
    }
    return false;

}

void solve()
{
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) if(ch(i,j)){ cout << i << ' ' << j << endl; return; }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    a.resize(m);
    for(int i = 0;i < m;i++)
    {
        cin >> a[i];
        for(int j = 0;j < n;j++) if(a[i][j]>'Z') a[i][j]+=('A'-'a');
    }

    cin >> q;

    while(q--)
    {
        cin >> s;
        for(int i = 0;i < s.length();i++) if(s[i]>'Z') s[i]+=('A'-'a');
        solve();
    }
}
