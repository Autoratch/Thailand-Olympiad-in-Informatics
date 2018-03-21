#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

vector<long long> f(100001),e(100001);

long long read(int idx)
{
    long long val = 0;
    while(idx>0)
    {
        val+=f[idx];
        idx-=(idx & -idx);
    }
    return val;
}

void update(int idx,int val)
{
    while(idx<=100000)
    {
        f[idx]+=val;
        idx+=(idx & -idx);
    }
}

long long read1(int idx)
{
    long long val = 0;
    while(idx>0)
    {
        val+=e[idx];
        idx-=(idx & -idx);
    }
    return val;
}

void update1(int idx)
{
    while(idx<=100000)
    {
        e[idx]++;
        idx+=(idx & -idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<pair<int,int> > a(n);

    for(int i = 0;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
    }

    sort(a.begin(),a.end());

    long long ans = 0;

    for(int i = 0;i < n;i++)
    {
        ans+=read(100000)-read(a[i].second);
        ans+=(a[i].first*(read1(100000)-read1(a[i].second)));
        update(a[i].second,a[i].first);
        update1(a[i].second);
    }

    cout << ans;
}
