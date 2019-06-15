#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;

int n;
int a[N],b[N];
int mn = INT_MAX,mx = INT_MIN;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    sort(a,a+n),sort(b,b+n);

    for(int i = 0;i < n;i++) a[i]+=b[n-1-i];

    for(int i = 0;i < n;i++) mn = min(mn,a[i]),mx = max(mx,a[i]);

    cout << mx-mn;
}
