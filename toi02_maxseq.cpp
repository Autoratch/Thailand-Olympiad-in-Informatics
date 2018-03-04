#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(n);
    bool ok = false;

    for(int i = 0;i < n;i++){ cin >> a[i]; if(a[i]>0) ok = true; }

    if(!ok){ cout << "Empty sequence"; return 0; }

    int st = 0,en = 0,mxa = INT_MIN,mxe = 0,x = 0;

    for(int i = 0;i < n;i++)
    {
        mxe+=a[i];
        if(mxe>mxa)
        {
            mxa = mxe;
            st = x;
            en = i;
        }
        if(mxe<a[i])
        {
            mxe = a[i];
            x = i;
        }
//        cout << i << ' ' << mxe << ' ' << mxa << ' ' << st << ' ' << en << endl;
    }

    for(int i = st;i <= en;i++) cout << a[i] << ' ';
    cout << endl << mxa;
}
