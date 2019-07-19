#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;

int n;
long long s,ans = LLONG_MAX,idx,mxh = LLONG_MAX;
long long a[N],b[N];
pair<long long,long long> res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> b[i],mxh = min(mxh,b[i]);
    for(int i = 0;i < n;i++) cin >> a[i],s+=a[i];
    for(int i = 0;i < n;i++) res[i] = {a[i],b[i]};

    sort(res,res+n);

    for(int i = 1;i < n;i++) res[i].second+=res[i-1].second;
    for(int i = 0;i < n;i++)
    {
        long long h = 0;
        if(i) h = res[i-1].second;
        res[i].first = min(res[i].first,mxh);
        long long tmp = h-res[i].first*n+s;
        if(tmp<ans) ans = tmp,idx = res[i].first;
        else if(tmp==ans) idx = min(idx,res[i].first);
    }
    
    if(res[n-1].second-mxh*n+s<ans) ans = res[n-1].second-mxh*n+s,idx = mxh;
    else if(res[n-1].second-mxh*n+s==ans) idx = min(idx,mxh);

    cout << idx << ' ' << ans;
}
