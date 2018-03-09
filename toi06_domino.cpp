#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int k;

    cin >> k;

    queue<pair<int,int> > q;
    vector<bool> c,visited;

    for(int i = 0;i <= k/2;i++)
    {
        int n = k-(2*i)+i,r = i;
        q.push({0,0});
        c.resize(n);
        visited.assign(1<<(n+1),0);
        while(!q.empty())
        {
            int cd = q.front().first,lv = q.front().second;
            int tm = cd,cnt = 0;
            q.pop();
            for(int j = 0;j < n;j++) c[j] = 0;
            while(cd)
            {
                c[cnt] = cd%2;
                cd/=2;
                cnt++;
            }
            if(lv==r){ for(int j = 0;j < n;j++) if(c[j]==0) cout << "--\n"; else cout << "||\n"; cout << "E\n"; }
            for(int j = 0;j < n;j++)
            {
                if(c[j]==0 and !visited[tm+(1<<(j))]) q.push({tm+(1<<(j)),lv+1});
                visited[tm+(1<<(j))] = true;
            }
        }
    }
}
