#include <queue>
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;

    cin >> n >> k;

    vector<int> a(n+1);

    for(int i = 1;i <= n;i++){ cin >> a[i]; a[i]+=a[i-1]; }

    deque<pair<int,int> > q;

    q.push_back({0,0});

    int mx = 0,len = 0;

    for(int i = 1;i <= n;i++)
    {
        while(!q.empty())
        {
            if(i-q.front().second<=k){ break; }
            q.pop_front();
        }
        if(a[i]-q.front().first>mx){ mx = a[i]-q.front().first; len = i-q.front().second; }
        else if(mx==a[i]-q.front().first and len>i-q.front().second) len = i-q.front().second;
        while(!q.empty())
        {
            if(q.back().first>=a[i]) q.pop_back();
            else break;
        }
        q.push_back({a[i],i});
    }

    cout << mx << '\n' << len << '\n';
}
