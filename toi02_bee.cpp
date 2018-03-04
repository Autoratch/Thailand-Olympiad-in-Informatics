#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int a[25],b[25];

void cr()
{
    a[0] = 1; b[0] = 0;
    for(int i = 1;i <= 24;i++)
    {
        a[i] = a[i-1]+b[i-1]+1;
        b[i] = a[i-1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cr();

    while(true)
    {
        int n;
        cin >> n;
        if(n==-1) return 0;
        cout << a[n] << ' ' << a[n]+b[n]+1 << endl;
    }
}
