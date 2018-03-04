#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(300,0),l(n),h(n),r(n);

    for(int i = 0;i < n;i++)
    {
        cin >> l[i] >> h[i] >> r[i];
        for(int j = l[i];j < r[i];j++) a[j] = max(a[j],h[i]);
    }

    int pr = 0;

    for(int i = 1;i <= 256;i++)
    {
        if(a[i]!=pr)
        {
            cout << i << ' ' << a[i] << ' ';
            pr = a[i];
        }
    }
}
