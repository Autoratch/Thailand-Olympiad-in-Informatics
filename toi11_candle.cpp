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
    queue<pair<int,int> > q;
    vector<vector<bool> > visited(m);

    for(int i = 0;i < m;i++)
    {
        cin >> s[i];
        visited[i].resize(n);
    }

    int ans = 0;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(visited[i][j]) continue;
        if(!(s[i][j]-'0')) continue;
        ans++;
        q.push({i,j});
        visited[i][j] = true;
        while(!q.empty())
        {
            int x = q.front().first,y = q.front().second;
            q.pop();
            for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
            {
                if(i==0 and j==0) continue;
                int ai = x+i,aj = y+j;
                if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
                if(visited[ai][aj]) continue;
                if(!(s[ai][aj]-'0')) continue;
                visited[ai][aj] = true;
                q.push({ai,aj});
            }
        }
    }

    cout << ans;
}
