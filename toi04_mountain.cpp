#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,mxh = 0,mxw = 0;

    cin >> n;

    vector<int> s(n),h(n);

    for(int i = 0;i < n;i++){ cin >> s[i] >> h[i]; mxh = max(mxh,h[i]); mxw = max(mxw,s[i]+(h[i]*2)-1); }

    vector<vector<char> > c(mxh+1);

    for(int i = 1;i <= mxh;i++) c[i].assign(mxw+1,'.');

    for(int i = 0;i < n;i++)
    {
        for(int j = s[i];j < s[i]+h[i];j++){ if(c[j-s[i]+1][j]=='\\') c[j-s[i]+1][j] = 'v'; else c[j-s[i]+1][j] = '/'; }
        for(int j = s[i]+h[i];j < s[i]+h[i]+h[i];j++){ if(c[h[i]-(j-s[i]-h[i])][j]=='/') c[h[i]-(j-s[i]-h[i])][j] = 'v'; else  c[h[i]-(j-s[i]-h[i])][j] = '\\'; }
    }

    for(int i = 1;i <= mxh;i++)
    {
        int lv = 0,f = 0,b = 0; // 0-. 1-/
        for(int j = 1;j <= mxw;j++)
        {
            if(c[i][j]=='/') f++;
            else if(c[i][j]=='\\') b++;
            if(lv==0 and c[i][j]=='/') lv = 1;
            else if(lv==1 and c[i][j]!='v' and f>b) c[i][j] = 'X';
            else if(lv==1 and c[i][j]=='\\' and f==b) lv = 0;
        }
    }

    for(int i = mxh;i >= 1;i--){ for(int j = 1;j <= mxw;j++) cout << c[i][j]; cout << endl; }
}
