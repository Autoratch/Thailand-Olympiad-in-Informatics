#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'

int a[100000],s[300005],ll,rr;

void cr(int idx,int l,int r)
{
    if(l==r){ s[idx] = a[l];  return; }
    int mid = (l+r)/2;
    cr(idx*2+1,l,mid);
    cr(idx*2+2,mid+1,r);
    s[idx] = max(s[idx*2+1],s[idx*2+2]);
}

int val(int idx,int l,int r)
{
    if(ll<=l and rr>=r) return s[idx];
    if(l==r) return s[idx];
    int mid = (l+r)/2,ans = 0;
    if(ll<=mid) ans = val(idx*2+1,l,mid);
    if(rr>=mid+1) ans = max(ans,val(idx*2+2,mid+1,r));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,q;

    cin >> n >> q;

    for(int i = 0;i < n;i++) cin >> a[i];

    cr(0,0,n-1);
    while(q--)
    {
        cin >> ll >> rr;
        cout << val(0,0,n-1) << endl;
    }
}
