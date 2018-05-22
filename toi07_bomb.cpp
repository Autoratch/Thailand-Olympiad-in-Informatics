#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    pair<int,int> a[n];

    for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;
    sort(a,a+n);
    reverse(a,a+n);

    int all = 0,ex = 0,p = -1;

    for(int i = 0;i < n;i++)
    {
        if(a[i].first!=p){ ex = all; p = a[i].first; }
        if(ex<=a[i].second) cout << a[i].first << ' ' << a[i].second << endl;
        all = max(all,a[i].second);
    }
}
