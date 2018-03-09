#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,s = 0;

    cin >> n;

    vector<int> a(n),b(n);

    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i = 0;i < n;i++) s+=(abs(a[i]-b[i]));

    cout << s;
}
