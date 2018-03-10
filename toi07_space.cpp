#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<bool> t;

    for(int i = 0;i < (1<<n);i++)
    {
        t.assign(n,false);
        int cnt = 0,tmp = i;
        while(tmp)
        {
            t[cnt] = tmp%2;
            tmp/=2;
            cnt++;
        }
        for(int j = 0;j < n;j++) if(t[j]==0)
        {
            for(int k = 0;k < n;k++) cout << t[k];
            cout << ' ';
            t[j] = 1;
            for(int k = 0;k < n;k++) cout << t[k];
            t[j] = 0;
            cout << endl;
        }
    }
}
