#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

vector<bool> a(7368788,true);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    int cn = 1;

    a[1] = false;

    for(int i = 2;;i++)
    {
        if(!a[i]) continue;
        if(cn==n){ cout << i; return 0; }
        cn++;
        for(int j = 2;j*i <= 7368787;j++) a[j*i] = false;
    }
}
