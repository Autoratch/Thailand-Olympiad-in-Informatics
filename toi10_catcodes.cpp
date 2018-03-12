#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    map<int,int> m;
    bool ok;
    string s;
    int n,l,q,tmpp,num;

    cin >> n >> l;

    bool visited[n];

    for(int i = 0;i < n;i++)
    {
        string s;
        int tmp = 0;
        cin >> s;
        for(int j = 0;j < l;j++) tmp+=((s[j]-'0')*(1<<j));
        m[tmp] = i+1;
    }

    cin >> q;

    while(q--)
    {
        ok = true;
        num = 0;
        cin >> tmpp >> s;
        for(int i = 0;i < n;i++) visited[i] = false;
        for(int i = 0;i < l;i++) num+=((s[i]-'0')*(1<<i));
        for(int i = 0;i+l <= tmpp;i++)
        {
            if(i)
            {
                num = num>>1;
                num+=((s[i+l-1]-'0')*(1<<(l-1)));
            }
//        cout << num << ' ';
            if(m[num]){ visited[m[num]-1] = true; ok = false; }
        }
//        cout << endl;
        if(ok) cout << "OK";
        else for(int i = 0;i < n;i++) if(visited[i]) cout << i+1 << ' ';
        cout << endl;
    }
}
