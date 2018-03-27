#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n,k,mx = 0,s;
    bool used = false;

    cin >> m >> n >> k;

    vector<int> a(n),idh(m+1);
    vector<bool> visit(m+1,false);
    vector<pair<int,int> > b(k);

    for(int i = 0;i < n;i++){ cin >> a[i]; mx = max(mx,a[i]); }

    for(int i = 0;i < k;i++)
    {
        int h,x;
        cin >> x >> h;
        b[i] = {h,x-1};
    }

    cin >> s; s--;
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());

    for(int i = 0;i < k;i++)
    {
        int x = b[i].second,y = b[i].second+1;
        int tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
    }

    if(a[s]==mx){ cout << mx << endl << "NO"; return 0; }

    reverse(b.begin(),b.end());

    for(int i = 0;i < k;i++) if(!visit[b[i].first]){ idh[b[i].first] =  i; visit[idh[b[i].first]] = true; }

    int h = 0,idx = 0,p = s;
    mx = a[s];

    while(true)
    {
        int px = p;
        if(b[idx].second==p)
        {
            p++;
            h = b[idx].first;
            idx++;
        }
        else if(b[idx].second==p-1)
        {
            p--;
            h = b[idx].first;
            idx++;
        }
        if(p>0) if(a[p-1]>mx){ mx = a[p-1]; used = true; }
        if(p<n-1) if(a[p+1]>mx){ mx = a[p+1]; used = true; }
        if(idx==b.size()) break;
        int tmp = a[b[idx].second];
        a[b[idx].second] = a[b[idx].second+1];
        a[b[idx].second+1] = tmp;
        if(p>0) if(a[p-1]>mx){ mx = a[p-1]; used = true; }
        if(p<n-1) if(a[p+1]>mx){ mx = a[p+1]; used = true; }
        int tmpp = idh[h];

        while(true)
        {
            if(tmpp==b.size()) break;
            if(b[tmpp].second==p-2) if(a[p-2]>mx){ mx = a[p-2]; used = true; }
            if(b[tmpp].second==p+1) if(a[p+2]>mx){ mx = a[p+2]; used = true; }
            if(b[tmpp].second==p or b[tmpp].second==p-1) break;
            tmpp++;
        }

        idx++;
        if(idx==b.size()) break;
    }

    cout << mx << endl;
    if(used) cout << "USE";
    else cout << "NO";
}
