#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a,b;
    string x,y,z;

    cin >> a >> b >> x >> y >> z;

    vector<char> c(3);

    for(int i = 0;i < b;i++)
    {
        for(int j = 0;j < a;j++)
        {
            c[0] = z[i];
            c[1] = x[j];
            c[2] = y[j];
            sort(c.begin(),c.end());
            z[i] = c[1];
        }
    }

    cout << z;
}
