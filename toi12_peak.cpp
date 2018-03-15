#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;

    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    priority_queue<int> q;

    for(int i = 0;i < n;i++)
    {
        if(i==0)
        {
            if(a[i]>a[i+1]) q.push(a[i]);
            continue;
        }
        if(i==n-1)
        {
            if(a[i]>a[i-1]) q.push(a[i]);
            continue;
        }
        if(a[i]>a[i-1] and a[i]>a[i+1]) q.push(a[i]);
    }

    if(q.empty()){ cout << "-1"; return 0; }

    vector<int> ans;
    int m = 0,p = 0;

    while(!q.empty())
    {
        if(q.top()!=p){ ans.push_back(q.top()); m++; if(m==k) break; p = q.top(); }
        q.pop();
    }

    if(m<k) for(int i = ans.size()-1;i >= 0;i--) cout << ans[i] << endl;
    else for(int i = 0;i < ans.size();i++){ if(i==k) return 0; cout << ans[i] << endl; }
}
