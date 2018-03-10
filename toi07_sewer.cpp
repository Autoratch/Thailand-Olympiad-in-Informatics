#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n;

    cin >> m >> n;

    vector<vector<char> > a(m);
    vector<vector<int> > visited(m);

    for(int i = 0;i < m;i++)
    {
        a[i].resize(n); visited[i].assign(n,INT_MAX);
        for(int j = 0;j < n;j++) cin >> a[i][j];
    }

    queue<pair<pair<int,int>,int> > q;

    q.push({{0,0},1});
    visited[0][0] = 1;

    while(!q.empty())
    {
        int x = q.front().first.first,y = q.front().first.second,lv = q.front().second;
        q.pop();
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(i==-1 and !(a[ai][aj]=='D' or a[ai][aj]=='B')) continue;
            if(i==1 and !(a[x][y]=='D' or a[x][y]=='B')) continue;
            if(j==-1 and !(a[ai][aj]=='R' or a[ai][aj]=='B')) continue;
            if(j==1 and !(a[x][y]=='R' or a[x][y]=='B')) continue;
            if(visited[ai][aj]<lv+1) continue;
            if(visited[ai][aj]==lv+1){ cout << lv+1 << endl << ai+1 << ' ' << aj+1; return 0; }
            q.push({{ai,aj},lv+1}); visited[ai][aj] = lv+1;
        }
    }
}
