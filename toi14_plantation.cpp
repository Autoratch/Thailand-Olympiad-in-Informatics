#include <bits/stdc++.h>
using namespace std;

int t,n,x,y;
vector<pair<double,double> > pts;
set<pair<double,double> > s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> t;

    while(t--)
    {
        cin >> n >> x >> y;

        pts.resize(n);
        for(int i = 0;i < n;i++) cin >> pts[i].first >> pts[i].second;
        sort(pts.begin(),pts.end());
        s.clear();
        
        int j = 0;
        double ans = 1e18;
        for(int i = 0;i < n;i++)
        {
            double d = ceil(sqrt(ans));
            while(pts[i].first-pts[j].first>=ans)
            {
                s.erase({pts[j].second,pts[j].first});
                j++;
            }
            auto it1 = s.lower_bound({pts[i].second-d,pts[i].first});
            auto it2 = s.upper_bound({pts[i].second+d,pts[i].first});
            for(auto it = it1;it != it2;it++)
            {
                double dx = pts[i].first-it->second;
                double dy = pts[i].second-it->first;
                ans = min(ans,sqrt(dx*dx+dy*dy));
            }
            s.insert({pts[i].second,pts[i].first});
        }
        if(ans<x*2+y) cout << 'N';
        else cout << 'Y';
        cout << '\n';
    }
}
