#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

string t,p;
vector<int> a,ans;

void kmp()
{
    int i = 0,j = 0;
    while(i<t.length())
    {
        if(p[j]==t[i]){ i++; j++; }
        if(j==p.length()){ ans.push_back(i-j); j = a[j-1]; }
        else if(i<t.length() and p[j]!=t[i])
        {
            if(j>0) j = a[j-1];
            else i++;
        }
    }
}

void crtable()
{
    int len = 0,i = 1;

    a.resize(p.length());
    a[0] = 0;

    while(i<p.length())
    {
        if(p[i]==p[len]){ len++; a[i] = len; i++; }
        else
        {
            if(len>0) len = a[len-1];
            else
            {
                a[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t >> p;

    crtable();
    kmp();

    for(int i = 0;i < ans.size();i++) cout << ans[i] << ' ';
}
