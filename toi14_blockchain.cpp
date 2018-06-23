#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int m,n;
map<vector<pair<int,int> >,int> s;
vector<vector<pair<int,int> > > a;
vector<pair<int,int> > b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    a.resize(m);

    for(int i = 0;i < m;i++)
    {
        int sz;
        cin >> sz;
        for(int j = 1;j < sz;j++)
        {
            int x,y;
            cin >> x >> y;
            x--; y--;
            a[i].push_back({min(x,y),max(x,y)});
        }
        sort(a[i].begin(),a[i].end());
        s[a[i]]++;
    }

    for(int i = 0;i < n;i++)
    {
        int sz;
        cin >> sz;
        b.resize(0);
        for(int j = 1;j < sz;j++)
        {
            int x,y;
            cin >> x >> y;
            x--; y--;
            b.push_back({min(x,y),max(x,y)});
        }
        sort(b.begin(),b.end());
        cout << s[b] << endl;
    }
}
