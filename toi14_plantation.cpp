#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second

const int N = 1e5;

int q,n,r,d;
pair<double,double> s[N];
vector<pair<double,double> > tmp;

bool cmpx(pair<double,double> a,pair<double,double> b){ return a.x < b.x; }

bool cmpy(pair<double,double> a,pair<double,double> b){ return a.y < b.y; }

double dist(pair<double,double> a,pair<double,double> b){ return (double)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }

double solve(int l,int r)
{
    if(r-l+1<=3)
    {
        double mn = (double)INT_MAX;
        for(int i = l;i <= r;i++) for(int j = i+1;j <= r;j++) mn = min(mn,dist(s[i],s[j]));
        return mn;
    }
    int mid = (l+r)/2;
    double ml = solve(l,mid);
    double mr = solve(mid+1,r);
    double mn = min(ml,mr);
    tmp.resize(0);
    for(int i = l;i < r;i++) if(abs(s[mid].x-s[i].x)<mn) tmp.push_back(s[i]);
    sort(tmp.begin(),tmp.end(),cmpy);
    for(int i = 0;i < tmp.size();i++) for(int j = i+1;j < tmp.size() and tmp[j].y-tmp[i].y < mn;j++) mn = min(mn,dist(tmp[i],tmp[j]));
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> q;

    while(q--)
    {
        cin >> n >> r >> d;
        for(int i = 0;i < n;i++) cin >> s[i].x >> s[i].y;
        sort(s,s+n,cmpx);
        double ans = solve(0,n-1);
        if(ans<d+r+r) cout << 'N';
        else cout << 'Y';
        cout << endl;
    }
}
