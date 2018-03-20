#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    long long l = 0,r = INT_MAX,k;

    cin >> n >> k;

    vector<long long> a(n);

    for(int i = 0;i < n;i++){ cin >> a[i]; r = min(r,a[i]); }
    r*=k;

    while(l<r)
    {
        long long m = (l+r)/2,x = 0;
        for(int i = 0;i < n;i++) x+=(m/a[i]);
        if(x<k) l = m+1;
        else r = m;
    }

    cout << l;
}
