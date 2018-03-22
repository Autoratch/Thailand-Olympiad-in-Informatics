#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

bool pr[9];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,n;

    cin >> t >> n;

    vector<vector<pair<int,int> > > s(8);
    vector<vector<pair<int,pair<int,int> > > > m(8);

    pr[2] = true; pr[3] = true; pr[5] = true; pr[7] = true;

    while(t--)
    {
        int l,r,x;
        cin >> x >> l >> r;
        for(int i = 2;i <= 7;i++)
        {
            if(!pr[i]) continue;
            if(x%i==0){ s[i].push_back({l,0}); s[i].push_back({r+1,0}); }
            int tmp = 0;
            while(x%i==0){ tmp++; x/=i; }
            m[i].push_back({tmp,{l,r}});
        }
    }

    for(int i = 2;i <= 7;i++)
    {
        if(!pr[i]) continue;
        s[i].push_back({0,0});
        s[i].push_back({n,0});
        sort(s[i].begin(),s[i].end());
        auto it2 = unique(s[i].begin(),s[i].end());
        s[i].resize(distance(s[i].begin(),it2));
        for(auto it : m[i])
        {
            auto lo = lower_bound(s[i].begin(),s[i].end(),make_pair(it.second.first,-1000));
            auto up = lower_bound(s[i].begin(),s[i].end(),make_pair(it.second.second+1,-1000));
            lo->second+=it.first;
            up->second-=it.first;
        }
        for(auto it = s[i].begin()+1;it != s[i].end();it++)
        {
            auto it2 = it; it2--;
            it->second+=it2->second;
        }
    }

    auto it2 = s[2].begin();
    auto it3 = s[3].begin();
    auto it5 = s[5].begin();
    auto it7 = s[7].begin();

    long long mx = 1;
    int cnt = 0;

    int p2,p3,p5,p7;

    while(true)
    {
        if(!(it2->first!=n or it3->first!=n or it5->first!=n or it7->first!=n)) break;
        auto it22 = it2;
        auto it33 = it3;
        auto it55 = it5;
        auto it77 = it7;
        int mn = INT_MAX,mn2 = INT_MAX;
        long long ea = 1;
        mn = min(mn,it2->first);
        mn = min(mn,it3->first);
        mn = min(mn,it5->first);
        mn = min(mn,it7->first);
        if(mn==it2->first){ ea*=((it2->second)+1); p2 = it2->second; it2++; it22++; }
        else ea*=(p2+1);
        if(mn==it3->first){ ea*=((it3->second)+1); p3 = it3->second; it3++; it33++; }
        else ea*=(p3+1);
        if(mn==it5->first){ ea*=((it5->second)+1); p5 = it5->second; it5++; it55++; }
        else ea*=(p5+1);
        if(mn==it7->first){ ea*=((it7->second)+1); p7 = it7->second; it7++; it77++; }
        else ea*=(p7+1);
        mn2 = min(mn2,it22->first);
        mn2 = min(mn2,it33->first);
        mn2 = min(mn2,it55->first);
        mn2 = min(mn2,it77->first);
        if(ea>mx){ mx = ea; cnt = mn2-mn; }
        else if(ea==mx) cnt+=mn2-mn;
    }

    cout << mx << ' ' << cnt;
}
