#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;

    cin >> n >> k;

    vector<int> f(n+1),b(n+1);

    for(int i = 1;i < n;i++) f[i] = i+1;
    for(int i = 2;i <= n;i++) b[i] = i-1;
    f[n] = 1;
    b[1] = n;

    int idx = 1;

    for(int cn = 0;cn < n;cn++)
    {
        for(int i = 1;i < k;i++) idx = f[idx];
        cout << idx << ' ';
        b[f[idx]] = b[idx];
        f[b[idx]] = f[idx];
        idx = f[idx];
    }
}
