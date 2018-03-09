#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'

vector<int> ans;
bool ok;
int st = 1;

void solve(string s)
{
    ans.resize(0);
    for(int i = 0;i < 8;i++)
    {
        char t[2];
        t[0] = s[i*2]; t[1] = s[i*2+1];
        if(st==1)
        {
            if(t[0]=='0'){ st = 1; ans.push_back(0); }
            else { st = 2; ans.push_back(1); }
        }
        else if(st==2)
        {
            if(t[0]=='1'){ st = 3; ans.push_back(0); }
            else { st = 4; ans.push_back(1); }
        }
        else if(st==3)
        {
            if(t[0]=='0'){ st = 2; ans.push_back(1); }
            else { st = 1; ans.push_back(0); }
        }
        else
        {
            if(t[0]=='0'){ st = 3; ans.push_back(0); }
            else ans.push_back(1);
        }
    }
//    if(st!=1)
    int tmp = 0;
    for(int i = 0;i < 8;i++) if(ans[i]) tmp+=(1<<(7-i));

    cout << (char)(tmp);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;
        if(s.length()<16) return 0;
        solve(s);
    }
}
