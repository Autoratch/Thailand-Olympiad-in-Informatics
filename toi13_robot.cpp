#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n;

    cin >> m >> n;

    vector<string> s(m);
    vector<vector<bool> > visited(m),vsa(m);

    for(int i = 0;i < m;i++){ cin >> s[i]; visited[i].assign(n,false); vsa[i].assign(n,false); }

    int am = 0,ds = 0;
    queue<pair<pair<int,int>,int> > q;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) if(s[i][j]=='X'){ q.push({{i,j},0}); visited[i][j] = true; }

    while(!q.empty())
    {
        int x = q.front().first.first,y = q.front().first.second,lv = q.front().second;
        q.pop();
        if(s[x][y]=='A' and !vsa[x][y])
        {
            ds+=(lv*2);
            am++;
        }
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(s[ai][aj]=='W') continue;
            if(visited[ai][aj]) continue;
            visited[ai][aj] = true;
            q.push({{ai,aj},lv+1});
        }
    }

    cout << am << ' ' << ds;
}
