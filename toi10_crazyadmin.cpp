#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int k,n,s = 0,mx = 0;

    cin >> k >> n;

    vector<int> a(n);

    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        s+=a[i];
        mx = max(mx,a[i]);
    }

    int l = mx,r = s;

    while(l<r)
    {
        int m = (l+r)/2;
        s = 0; mx = 1;
        for(int i = 0;i < n;i++)
        {
            if(s+a[i]>m){ s = a[i]; mx++; }
            else s+=a[i];
        }
        if(mx>k) l = m+1;
        else r = m;
    }

    cout << l;
}
