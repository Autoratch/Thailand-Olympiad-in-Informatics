#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    int o = 0,e = 0,po = n,pe = n;

    n*=2;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        if(x%2==0)
        {
            if(e>=2)
            {
                e++;
                po-=3;
            }
            else
            {
                po-=1;
                if(e==0)
                {
                    o = 0;
                    e = 1;
                }
                else e++;
            }
        }
        else
        {
            if(o>=2)
            {
                o++;
                pe-=3;
            }
            else
            {
                pe-=1;
                if(o==0)
                {
                    e = 0;
                    o = 1;
                }
                else o++;
            }
        }
        if(pe<=0 or po<=0)
        {
            cout << x%2 << endl << x;
            return 0;
        }
    }

}
