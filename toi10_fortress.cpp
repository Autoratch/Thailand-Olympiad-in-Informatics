#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int cnt = 20;

    while(cnt--)
    {
        long long n,m;
        cin >> n >> m;
        if(2*m>n) cout << "0\n";
        else cout << max((4*m-n)/2+1,(long long)(0)) << endl;
    }
}
