#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(n);
    long long x;

    for(int i = 0;i < n;i++){cin >> x; x = --x; a[i] = x; }

    stack<int> s;
    unordered_map<int,bool> visited;

    int ans = -1;

    for(int i = 0;i < n;i++)
    {
        if(!visited[a[i]]){ s.push(a[i]); visited[a[i]] = true; }
        else
        {
            int mx = -1;
            if(ans>a[i]) continue;
            while(!s.empty() and s.top()!=a[i]){ mx = max(mx,s.top()); s.pop(); }
            ans = max(ans,min(a[i],mx));
            mx = max(mx,a[i]);
            s.push(mx);
        }
    }

    cout << ans + 1;
}
