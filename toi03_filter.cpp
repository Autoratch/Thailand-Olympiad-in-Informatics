#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int w,h,n;

    cin >> w >> h >> n;

    vector<int> a(w);

    for(int i = 0;i < n;i++)
    {
        int x,l;
        cin >> x >> l;
        if(x<w) a[x]++;
        if(x+l<w) a[x+l]--;
    }

    for(int i = 1;i < w;i++) a[i]+=a[i-1];

//for(int i = 0;i < w;i++) cout << a[i] << ' ';

    int x = 0,y = 0;

    for(int i = 0;i < w;i++) if(a[i]==1) x++; else if(a[i]==0) y++;

    cout << y*h << ' ' << x*h;
}
