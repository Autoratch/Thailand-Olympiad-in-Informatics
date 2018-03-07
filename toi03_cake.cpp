#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,a = 0,b = 0,c = 0,d = 0,e = 0,ans = 0;

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        int tm;
        cin >> tm;
        a+=tm;
        cin >> tm;
        b+=tm;
        cin >> tm;
        c+=tm;
        cin >> tm;
        d+=tm;
        cin >> tm;
        e+=tm;
    }

    ans = (a*8+b*6+c*4+d*2+e);

    cout << (ans+7)/8;
}
