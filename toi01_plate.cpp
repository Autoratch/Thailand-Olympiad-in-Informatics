#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int c,s;

    cin >> c >> s;

    map<int,int> m;

    for(int i = 0;i < s;i++)
    {
        int a,b;
        cin >> a >> b;
        m[b] = a;
    }

    queue<int> q;
    vector<queue<int> > ea(c+1);
    vector<bool> iq(c+1,false);

    while(true)
    {
        char c;
        cin >> c;
        if(c=='X'){ cout << "0"; return 0; }
        if(c=='E')
        {
            int x;
            cin >> x;
            if(iq[m[x]]) ea[m[x]].push(x);
            else
            {
                iq[m[x]] = true;
                ea[m[x]].push(x);
                q.push(m[x]);
            }
        }
        else
        {
            if(q.empty()) cout << "empty";
            else
            {
                cout << ea[q.front()].front();
                ea[q.front()].pop();
                if(ea[q.front()].empty()){ iq[q.front()] =  false; q.pop(); }
            }
            cout << endl;
        }
    }
}
