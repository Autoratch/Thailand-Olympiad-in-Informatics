#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m,q,l;

    cin >> n >> m >> q >> l;

    vector<int> a(n);
    vector<bool> ans;

    for(int i = 0;i < n;i++) cin >> a[i];

    while(q--)
    {
        int cnt = 0;
        ans.assign(n,false);
        for(int i = 0;i < m;i++)
        {
            int x;
            cin >> x;
            auto lo = lower_bound(a.begin(),a.end(),x-l);
            auto up = upper_bound(a.begin(),a.end(),x+l);
            if(lo==a.end()) continue;
            if(*lo<x-l) lo++;
//            cout << *lo << ' ' << *up << endl;
            for(auto it = lo;it != up;it++)
            {
                if(!ans[it-a.begin()]) cnt++;
                ans[it-a.begin()] = true;
            }
        }
        cout << cnt << endl;
    }
}
