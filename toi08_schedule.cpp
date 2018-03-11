#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n;

    cin >> m >> n;

    int a[n+1],b[n+1],d[n+1][n+1],l[n+1][n+1];

    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 0;i <= n;i++) for(int j = 0;j <= n;j++)
    {
        if(i==0 and j==0){ d[i][j] = 0; l[i][j] = 0; }
        else if(i==0)
        {
            d[i][j] = d[i][j-1];
            l[i][j] = l[i][j-1];
            if(l[i][j-1]+b[j]>m)
            {
                d[i][j]++;
                l[i][j] = b[j];
            }
            else l[i][j]+=b[j];
        }
        else if(j==0)
        {
            d[i][j] = d[i-1][j];
            l[i][j] = l[i-1][j];
            if(l[i-1][j]+a[i]>m)
            {
                d[i][j]++;
                l[i][j] = a[i];
            }
            else l[i][j]+=a[i];
        }
        else
        {
            int d1,l1,d2,l2;
            d1 = d[i-1][j];
            l1 = l[i-1][j];
            if(l1+a[i]>m)
            {
                d1++;
                l1 = a[i];
            }
            else l1+=a[i];
            d2 = d[i][j-1];
            l2 = l[i][j-1];
            if(l2+b[j]>m)
            {
                d2++;
                l2 = b[j];
            }
            else l2+=b[j];
            if(d1<d2 or (d1==d2 and l1<l2))
            {
                d[i][j] = d1;
                l[i][j] = l1;
            }
            else
            {
                d[i][j] = d2;
                l[i][j] = l2;
            }
        }
    }

    cout << d[n][n]+1 << endl << l[n][n];
}
