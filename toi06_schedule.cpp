#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int n,k,m;
vector<pair<int,int> > a(500001);
vector<int> s(500001);
bool ok[500001];

void update(int idx)
{
    while(idx<=500000)
    {
        s[idx]++;
        idx+=(idx & -idx);
    }
}

int read(int idx)
{
    int val = 0;
    while(idx > 0)
    {
        val+=s[idx];
        idx-=(idx & -idx);
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> m;

    for(int i = 0;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x] = {y,i};
    }

    for(int i = 1;i <= 500000;i++)
    {
        if(a[i].first==0) continue;
        if(read(500000)-read(i-1)>=k) continue;
        update(a[i].first);
        ok[a[i].second] = true;
    }

    while(m--)
    {
        int x;
        cin >> x;
        if(ok[x-1]) cout << "Y ";
        else cout << "N ";
    }
}
