#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<string> s;
    double x = 0,y = 0;

    while(true)
    {
        string tm;
        cin >> tm;
        if(tm=="*") break;
        s.push_back(tm);
    }

    for(int i = 0;i < s.size();i++)
    {
        double tmp = 0;
        if(s[i][s[i].length()-2]>='A')
        {
            int mu = 1;
            for(int j = s[i].length()-3;j >= 0;j--){ tmp+=(mu*(s[i][j]-'0')); mu*=10; }
            tmp = (double)(tmp/sqrt(2.0));
            if(s[i][s[i].length()-2]=='N') x+=tmp;
            else x-=tmp;
            if(s[i][s[i].length()-1]=='E') y+=tmp;
            else y-=tmp;
        }
        else
        {
            int mu = 1;
            for(int j = s[i].length()-2;j >= 0;j--){ tmp+=(mu*(s[i][j]-'0')); mu*=10; }
            char c = s[i][s[i].length()-1];
            if(c=='N') x+=tmp;
            else if(c=='S') x-=tmp;
            else if(c=='E') y+=tmp;
            else y-=tmp;
        }
    }

    cout << fixed;
    cout << setprecision(3) << y << ' ' << x << endl << sqrt(x*x+y*y);
}
