#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'

string cd,q;
int a,b,c,sa,sb,sc;

void solve(int x)
{
    x = sa+x-1;
    if(x>9) x-=9;
    x = sb+x-1;
    if(x>9) x-=9;
    x = sc+x-1;
    if(x>9) x-=9;
    cout << x;
    sa+=a;
    if(sa>9) sa-=9;
    sb-=1;
    if(sb==0) sb = 9;
    sc+=c;
    if(sc>9) sc-=9;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> cd >> q;

    a = cd[0]-'0'; b = cd[1]-'0'; c = cd[2]-'0';
    sa = a; sb = b; sc = c;

    for(int i = 0;i < q.length();i++) solve(q[i]-'0');
}
