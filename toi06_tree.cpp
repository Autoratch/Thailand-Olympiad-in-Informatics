#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tst = 5,n;
    vector<pair<int,int> > a,b;

    while(tst--)
    {
        cin >> n;
        a.clear(); b.clear();
        for(int i = 1;i < n;i++)
        {
            int x,y;
            cin >> x >> y;
            a.push_back({min(x,y),max(x,y)});
        }
        for(int i = 1;i < n;i++)
        {
            int x,y;
            cin >> x >> y;
            b.push_back({min(x,y),max(x,y)});
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b) cout << "Y";
        else cout << "N";
    }
}
