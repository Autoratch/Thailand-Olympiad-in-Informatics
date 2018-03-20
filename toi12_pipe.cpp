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

    vector<int> x(n),y(n),a(n,INT_MAX);
    vector<int> ans;

    for(int i = 0;i < n;i++) cin >> x[i] >> y[i];

    int p = 0;

    while(true)
    {
        int mn = INT_MAX,idx = -1;
        a[p] = -1;
        for(int i = 0;i < n;i++)
        {
            if(a[i]==-1) continue;
            a[i] = min(a[i],abs(x[p]-x[i])+abs(y[p]-y[i]));
            if(mn>a[i]){ mn = a[i]; idx = i; }
        }
        if(idx==-1) break;
//        cout << p << ' ' << mn << endl;
        p = idx;
        ans.push_back(mn);
    }

    int cnt = 0;

    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());

    for(int i = k-1;i < n-1;i++) cnt+=ans[i];

    cout << cnt;
}
