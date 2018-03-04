#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

bool a[101],b[101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    a[6] = true; a[9] = true; a[20] = true;

    if(n<6){ cout << "no"; return 0; }

    for(int i = 1;i <= 100;i++)
    {
        if(i>6){ if(a[i-6]) a[i] = true; }
        if(i>9){ if(a[i-9]) a[i] = true; }
        if(i>20){ if(a[i-20]) a[i] = true; }
        if(a[i]) cout << i << endl;
        if(i==n) return 0;
    }

}
