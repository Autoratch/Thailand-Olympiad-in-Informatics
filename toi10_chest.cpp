#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n;

    cin >> m >> n;

    vector<pair<int,int> > s2,s3,s5,s7;
    vector<pair<int,int> > m2,m3,m5,m7;

    while(m--)
    {
        int l,r,x;
        cin >> x >> l >> r;
        if(x%2==0){ s2.push_back({l,0}); s2.push_back({r+1,0}); }
        if(x%3==0){ s3.push_back({l,0}); s3.push_back({r+1,0}); }
        if(x%5==0){ s5.push_back({l,0}); s5.push_back({r+1,0}); }
        if(x%7==0){ s7.push_back({l,0}); s7.push_back({r+1,0}); }
        while(x%2==0){ m2.push_back({l,r}); x/=2; }
        while(x%3==0){ m3.push_back({l,r}); x/=3; }
        while(x%5==0){ m5.push_back({l,r}); x/=5; }
        while(x%7==0){ m7.push_back({l,r}); x/=7; }
    }

    s2.push_back({0,0});
    s2.push_back({n,0});
    s3.push_back({0,0});
    s3.push_back({n,0});
    s5.push_back({0,0});
    s5.push_back({n,0});
    s7.push_back({0,0});
    s7.push_back({n,0});
    sort(s2.begin(),s2.end());
    sort(s3.begin(),s3.end());
    sort(s5.begin(),s5.end());
    sort(s7.begin(),s7.end());

    auto it = unique(s2.begin(),s2.end());
    s2.resize(distance(s2.begin(),it));
    it = unique(s3.begin(),s3.end());
    s3.resize(distance(s3.begin(),it));
    it = unique(s5.begin(),s5.end());
    s5.resize(distance(s5.begin(),it));
    it = unique(s7.begin(),s7.end());
    s7.resize(distance(s7.begin(),it));

    for(auto it : m2)
    {
        auto lo = lower_bound(s2.begin(),s2.end(),make_pair(it.first,-1));
        auto up = lower_bound(s2.begin(),s2.end(),make_pair(it.second+1,-1));
        lo->second++;
        up->second--;
    }
    for(auto it : m3)
    {
        auto lo = lower_bound(s3.begin(),s3.end(),make_pair(it.first,-1));
        auto up = lower_bound(s3.begin(),s3.end(),make_pair(it.second+1,-1));
        lo->second++;
        up->second--;
    }
    for(auto it : m5)
    {
        auto lo = lower_bound(s5.begin(),s5.end(),make_pair(it.first,-1));
        auto up = lower_bound(s5.begin(),s5.end(),make_pair(it.second+1,-1));
        lo->second++;
        up->second--;
    }
    for(auto it : m7)
    {
        auto lo = lower_bound(s7.begin(),s7.end(),make_pair(it.first,-1));
        auto up = lower_bound(s7.begin(),s7.end(),make_pair(it.second+1,-1));
        lo->second++;
        up->second--;
    }

    for(auto it = s2.begin()+1;it != s2.end();it++)
    {
        auto it2 = it;
        it2--;
        it->second+=it2->second;
    }
    for(auto it = s3.begin()+1;it != s3.end();it++)
    {
        auto it2 = it;
        it2--;
        it->second+=it2->second;
    }
    for(auto it = s5.begin()+1;it != s5.end();it++)
    {
        auto it2 = it;
        it2--;
        it->second+=it2->second;
    }
    for(auto it = s7.begin()+1;it != s7.end();it++)
    {
        auto it2 = it;
        it2--;
        it->second+=it2->second;
    }

    auto it2 = s2.begin();
    auto it3 = s3.begin();
    auto it5 = s5.begin();
    auto it7 = s7.begin();

    long long mx = 1;
    int cnt = 0;

    for(int i = 0;i < n;i++)
    {
        auto it = it2; it++;
        if(it->first==i) it2++;
        it = it3; it++;
        if(it->first==i) it3++;
        it = it5; it++;
        if(it->first==i) it5++;
        it = it7; it++;
        if(it->first==i) it7++;
        long long ea = 1;
        ea*=((it2->second)+1);
        ea*=((it3->second)+1);
        ea*=((it5->second)+1);
        ea*=((it7->second)+1);
        if(ea>mx){ mx = ea; cnt = 1; }
        else if(ea==mx) cnt++;
    }

    cout << mx << ' ' << cnt;
}
