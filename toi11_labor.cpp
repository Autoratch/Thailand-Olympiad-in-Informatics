#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

long long n,m;
long long k,l,r = INT_MAX,cnt;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    a.resize(n);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        if(a[i]<r) r = a[i];
    }
    r*=k;

    while(l<r)
    {
        m = (l/2+r/2);
        if(l%2 and r%2) m++;
        cnt = 0;
        for(int i = 0;i < n;i++) cnt+=m/a[i];
        if(cnt>=k) r = m;
        else l = m+1;
    }

    cout << l;
}
