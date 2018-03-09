#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'

int idx[60001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;

    cin >> n >> k;

    vector<int> a(n+1);

    for(int i = 1;i <= n;i++){ cin >> a[i]; idx[a[i]] = i; }

    int t = 0,mx = -1;

    for(int i = 0;i <= 60000;i++) if(idx[i]==0) idx[i] = t; else t = idx[i];
    for(int i = 1;i <= n;i++) mx = max(mx,idx[min(a[i]+k,60000)]-i);

    cout << mx;
}
