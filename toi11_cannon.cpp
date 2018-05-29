#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m,k,l;

    cin >> n >> m >> k >> l;

    vector<int> a(n);

    for(int i = 0;i < n;i++) cin >> a[i];
    while(k--)
    {
        auto lo = a.begin(),up = a.begin();
        int ans = 0;
        for(int i = 0;i < m;i++)
        {
            int x;
            cin >> x;
            lo = lower_bound(up,a.end(),x-l);
            up = upper_bound(up,a.end(),x+l);
            if(lo==a.end()) continue;
            ans+=(up-lo);
        }
        cout << ans << endl;
    }
}
