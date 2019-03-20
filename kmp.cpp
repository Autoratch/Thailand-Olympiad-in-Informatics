#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

string p,t;
int a[N];
vector<int> ans;

void cra()
{
    int i = 1,j = 0;
    while(i<p.length())
    {
        if(p[i]==p[j])
        {
            a[i] = j+1;
            i++;
            j++;
        }
        else 
        {
            if(j==0){ a[i] = 0; i++; }
            else j = a[j-1];
        }
    }
}

void solve()
{
    int i = 0,j = 0;
    while(i<t.length())
    {
        if(t[i]==p[j])
        {
            i++; j++;
            if(j==p.length()){ ans.push_back(i-p.length()); j = a[j-1]; }
        }
        else
        {
            if(j>0) j = a[j-1];
            else i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> p >> t;

    cra();
    solve();

    for(int i = 0;i < ans.size();i++) cout << ans[i] << ' ';
}
