#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int n,m;
bool fb[10];

void solve(vector<int> a)
{
    if(a.size()==n){ for(int i = 0;i < n;i++) cout << a[i] << ' '; cout << endl; return; }
    vector<bool> t(n+1,false);
    for(int i = 0;i < a.size();i++) t[a[i]] = true;
    for(int i = 1;i <= n;i++)
    {
        if(t[i]) continue;
        a.push_back(i);
        solve(a);
        a.resize(a.size()-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++){ int x; cin >> x; fb[x] = true; }

    vector<int> b;

    b.push_back(0);

    for(int i = 1;i <= n;i++) if(!fb[i])
    {
        b[0] = i;
        solve(b);
    }
}
