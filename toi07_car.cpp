#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

vector<vector<int> > a,ans;
int m,n,s,e;
bool fin;

void solve(int lv,int idx)
{
    if(fin) return;
    if(lv==m){ fin = true; return; }
    if(abs(s-idx)>m-lv) return;
    for(int i = -1;i <= 1;i++)
    {
        int ai = idx+i;
        if(ai<0 or ai>=n) continue;
        if(a[m-lv-1][ai]) continue;
        if(i==-1) ans[m-lv-1][ai] = 2;
        else if(i==0) ans[m-lv-1][ai] = 3;
        else ans[m-lv-1][ai] = 1;
        solve(lv+1,ai);
        if(fin) return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s >> m;

    a.resize(m+1); s--; ans.resize(m+1);
    for(int i = 0;i <= m;i++)
    {
        a[i].assign(n,1);
        ans[i].resize(n);
        a[i][s] = 0;
        if(i==0) continue;
        for(int j = 0;j < n;j++) cin >> a[i][j];
    }

    vector<int> ae;

    for(int i = 0;i < n;i++) if(!a[m][i]) ae.push_back(i);

    for(int i = 0;i < ae.size();i++){ solve(0,ae[i]); if(fin) break; ans.clear(); }

    int idx = s;

    for(int i = 0;i < m;i++)
    {
        cout << ans[i][idx] << endl;
        if(ans[i][idx]==1) idx--;
        else if(ans[i][idx]==2) idx++;
    }
}
