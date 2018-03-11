#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7
#define pii pair<int,int>

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;

    cin >> n >> k;

    vector<int> a(n),s(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    priority_queue<pii,vector<pii>,greater<pii> > q;

    q.push({a[0],0});

    for(int i = 1;i < n;i++)
    {
        while(i-q.top().second>k) q.pop();
        s[i] = a[i]+q.top().first;
        q.push({s[i],i});
    }

    cout << s[n-1];
}
