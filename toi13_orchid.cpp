#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(n),l;

    for(int i = 0;i < n;i++) cin >> a[i];

    vector<int> s;

    for(int i = 0;i < n;i++)
    {
        auto it = upper_bound(l.begin(),l.end(),a[i]);
        if(it==l.end()) l.push_back(a[i]);
        else *it = a[i];
    }

    cout << n-l.size();
}
