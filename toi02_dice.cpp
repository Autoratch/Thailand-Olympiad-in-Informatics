#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;

    cin >> t;

    while(t--)
    {
        string s;
        int a = 1,b = 2,c = 3,d = 5,e = 4,f = 6;
        cin >> s;
        for(int i = 0;i < s.length();i++)
        {
            int tmp;
            if(s[i]=='F')
            {
                tmp = a;
                a = d;
                d = f;
                f = b;
                b = tmp;
            }
            else if(s[i]=='B')
            {
                tmp = b;
                b = f;
                f = d;
                d = a;
                a = tmp;
            }
            else if(s[i]=='L')
            {
                tmp = a;
                a = e;
                e = f;
                f = c;
                c = tmp;
            }
            else if(s[i]=='R')
            {
                tmp = c;
                c = f;
                f = e;
                e = a;
                a = tmp;
            }
            else if(s[i]=='C')
            {
                tmp = b;
                b = e;
                e = d;
                d = c;
                c = tmp;
            }
            else
            {
                tmp = c;
                c = d;
                d = e;
                e = b;
                b = tmp;
            }
        }
        cout << b << ' ';
    }
}
