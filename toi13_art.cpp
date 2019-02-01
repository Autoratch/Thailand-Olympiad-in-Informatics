#include <bits/stdc++.h>
using namespace std;

struct node
{
    int s,e,w,h,o;
}res[(int)1e5];

int n,k;
int a[(int)1e6];
vector<int> idx[(int)4e6 + 1];
int lst;
long long ans;

void update(int idx,int val)
{
    while(idx<=1e6)
    {
        a[idx]+=val;
        idx+=(idx & -idx);
    }
}

int read(int idx)
{
    int val = 0;
    while(idx>0)
    {
        val+=a[idx];
        idx-=(idx & -idx);
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++)
    {
        cin >> res[i].s >> res[i].h >> res[i].w >> res[i].o;
        res[i].e = res[i].s+res[i].w-1;
        lst  = max(lst,res[i].e);
        idx[res[i].s].push_back(i+1);
        idx[res[i].e+1].push_back(-i-1);
    }

    for(int i = 1;i <= lst;i++)
    {
        for(int j = 0;j < idx[i].size();j++)
        {
            int x = idx[i][j];
            if(x<0)
            {
                x = -x;
                x--;
                update(1,-res[x].o);
                update(res[x].h+1,res[x].o);
            }
            else
            {
                x--;
                update(1,res[x].o);
                update(res[x].h+1,-res[x].o);
            }
        }
        int l,r;
        int ll = 1,rr = 1e6;
        while(ll<rr)
        {
            int m = (ll+rr)/2;
            int tmp = read(m);
            if(tmp>k) ll = m+1;
            else if(tmp<k) rr = m-1;
            else rr = m;
        }
        if(read(ll)==k) l = ll;
        else continue;
        ll = 1;
        rr = 1e6;
        while(ll<rr)
        {
            int m = (ll+rr)/2;
            int tmp = read(m);
            if(tmp>k) ll = m+1;
            else if(tmp<k) rr = m-1;
            else if(read(m+1)==k) ll = m+1;
            else{ ll = m; break; }
        }
        r = ll;
        ans+=(r-l+1);
    }

    cout << ans;
}
