#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

bool visited[100][100][1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n;

    cin >> m >> n;

    int a[m][n];

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    queue<pair<int,pair<int,int> > > q;

    q.push({1,{(m-1)/2-1,0}});
    q.push({1,{(m-1)/2,0}});
    q.push({1,{(m-1)/2+1,0}});
    visited[(m-1)/2-1][0][1] = true;
    visited[(m-1)/2][0][1] = true;
    visited[(m-1)/2+1][0][1] = true;

    while(!q.empty())
    {
        int lv = q.front().first,x = q.front().second.first,y = q.front().second.second;
        q.pop();
        if(x==(m-1)/2 and y==n-1){ cout << lv; return 0; }
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(x%2==0 and j==-1) continue;
            if(x%2==1 and j==1) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(!a[ai][aj]) continue;
            if((lv+1)%a[ai][aj]) continue;
            if(visited[ai][aj][lv+1]) continue;
            visited[ai][aj][lv+1] = true;
            q.push({lv+1,{ai,aj}});
        }
    }
}
