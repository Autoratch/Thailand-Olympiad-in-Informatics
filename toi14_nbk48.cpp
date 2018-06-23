#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int n,q;
vector<pair<int,int> > s;

int solve(int x)
{
    int l = 0,r = n;
    while(l<r)
    {
        int m = (l+r)/2;
        if(s[m].first>x) r = m-1;
        else
        {
            if(m==n) return s[m].second;
            if(s[m+1].first>x) return s[m].second;
            l = m+1;
        }
    }
    return s[l].second;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    s.resize(n+1);
    s[0] = {0,0};
    for(int i = 0;i < n;i++)
    {
        cin >> s[i+1].first;
        s[i+1].second = i+1;
        s[i+1].first+=s[i].first;
    }

    sort(s.begin(),s.end());

    for(int i = 1;i <= n;i++) s[i].second = max(s[i].second,s[i-1].second);

    for(int i = 0;i < q;i++)
    {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
}
