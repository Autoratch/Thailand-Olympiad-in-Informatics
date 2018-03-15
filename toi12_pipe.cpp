#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7
#define pii pair<int,int>

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;

    cin >> n >> k;

    vector<int> x(n),y(n);
    vector<bool> visited(n,false);
    priority_queue<int,vector<int>,greater<int> > ans;
    priority_queue<pii,vector<pii>,greater<pii> > q;

    for(int i = 0;i < n;i++) cin >> x[i] >> y[i];

    q.push({0,0});

    while(!q.empty())
    {
        int w = q.top().first,p = q.top().second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        if(w) ans.push(w);
        for(int i = 0;i < n;i++)
        {
            if(visited[i]) continue;
            q.push({abs(x[p]-x[i])+abs(y[p]-y[i]),i});
        }
    }

    int cnt = 0;

    for(int i = k;i < n;i++){ cnt+=ans.top(); ans.pop(); }

    cout << cnt;
}
