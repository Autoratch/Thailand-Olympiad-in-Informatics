#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7
#define HASH 5000011

vector<pair<pair<int,int>,pair<int,int> > > tb(HASH);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int ax,ay,n;

    cin >> ax >> ay >> n;

    vector<vector<int> > x(4),y(4);

    for(int i = 0;i < 4;i++)
    {
        x[i].resize(n); y[i].resize(n);
        for(int j = 0;j < n;j++) cin >> x[i][j] >> y[i][j];
    }

    int mxcl = 0;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
    {
        pair<int,int> tmp = {x[0][i]+x[1][j],y[0][i]+y[1][j]};
        int idx = (((x[0][i]+x[1][j])*3+y[0][i]+y[1][j])%HASH+HASH)%HASH;
        int ea = 0;
        while(true)
        {
            if(tb[idx]==make_pair(make_pair(0,0),make_pair(0,0))) break;
            ea++;
            idx++;
            idx%=HASH;
        }
        tb[idx] = {tmp,{i,j}};
        mxcl = max(mxcl,ea);
    }

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
    {
        pair<int,int> tmp = {ax-x[2][i]-x[3][j],ay-y[2][i]-y[3][j]};
        int idx = (((ax-x[2][i]-x[3][j])*3+ay-y[2][i]-y[3][j])%HASH+HASH)%HASH;
        int ea = 0;
        while(true)
        {
            if(tb[idx].first==tmp)
            {
                cout << x[0][tb[idx].second.first] << ' ' << y[0][tb[idx].second.first] << endl;
                cout << x[1][tb[idx].second.second] << ' ' << y[1][tb[idx].second.second] << endl;
                cout << x[2][i] << ' ' << y[2][i] << endl;
                cout << x[3][j] << ' ' << y[3][j] << endl;
                return 0;
            }
            ea++;
            idx++;
            if(ea>mxcl) break;
        }
    }
}
