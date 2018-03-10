#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<pair<int,int> > a(n);

    for(int i = 0;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int p = 0,mxp = 0,mxa = 0;

    for(int i = 0;i < n;i++)
    {
        bool ok = true;
        if(i==0)
        {
            p = a[i].first;
            mxp = a[i].second;
        }
        else
        {
            if(a[i].first==p){ if(mxa>a[i].second) ok = false; mxp = max(mxp,a[i].second); }
            else
            {
                p = a[i].first;
                if(mxp>a[i].second) ok = false;
                mxp = max(mxp,a[i].second);
                mxa = mxp;
            }
        }
        if(ok) cout << a[i].first << ' ' << a[i].second << endl;
    }
}
