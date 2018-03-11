#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int k,a,b;

void solve(vector<char> x,int w,int l)
{
    if(w==k or l==k)
    {
        for(int i = 0;i < x.size();i++) cout << x[i] << ' ';
        cout << endl;
        return;
    }
    x.push_back('W');
    solve(x,w+1,l);
    x[x.size()-1] = 'L';
    solve(x,w,l+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> a >> b;

    vector<char> x;

    solve(x,a,b);
}
