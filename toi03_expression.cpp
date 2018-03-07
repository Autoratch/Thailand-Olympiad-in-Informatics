#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    int n;
    vector<int> a;

    cin >> s >> n;

    while(n--)
    {
        int l = 0,r = s.length()-1,x;
        bool br = false;
        cin >> x;
        a.resize(0);
        while(x)
        {
            a.push_back(x);
            if(br){ cin >> x; continue; }
            int cnt = 1;
            int o = 0,c = 0;
            int pl = 0,mu = 0,po = 0,pa = 0,nl = -1,nr = -1,par = 1;
            for(int i = l;i <= r;i++)
            {
                if(s[i]=='(') o++;
                if(s[i]==')') c++;
                if(s[i]=='+' and o==c)
                {
                    pl++;
                    if(o==c) par = false;
                }
                if(s[i]=='*' and o==c)
                {
                    mu++;
                    if(o==c) par = false;
                }
                if(s[i]=='^' and o==c)
                {
                    po++;
                    if(o==c) par = false;
                }
                if(s[i]=='(' or ')') pa++;
            }
            pa/=2;
            o = 0; c = 0;
            if(x==1 and l==r){ cin >> x; continue; }
            if(x>1 and l==r){ l = -1; r = -1; br = true; cin >> x; continue; }
            if(x==1) nl = l;
            if(par and x>1) br = true;
            else if(par){ nl = l+1; nr = r-1; }
            else if(pl>0)
            {
                for(int i = l;i <= r;i++)
                {
                    if(s[i]=='(') o++;
                    if(s[i]==')') c++;
                    if(cnt>=x and s[i]=='+' and c==o){ nr = i-1; break; }
                    if(cnt==x) nr = i;
                    if(s[i]=='+' and c==o)
                    {
                        cnt++;
                        if(cnt==x) nl = i+1;
                    }
                }
            }
            else if(mu>0)
            {
                for(int i = l;i <= r;i++)
                {
                    if(s[i]=='(') o++;
                    if(s[i]==')') c++;
                    if(cnt>=x and s[i]=='*' and c==o){ nr = i-1; break; }
                    if(cnt==x) nr = i;
                    if(s[i]=='*' and c==o)
                    {
                        cnt++;
                        if(cnt==x) nl = i+1;
                    }
                }
            }
            else if(po>0)
            {
                for(int i = l;i <= r;i++)
                {
                    if(s[i]=='(') o++;
                    if(s[i]==')') c++;
                    if(cnt>=x and s[i]=='^' and c==o){ nr = i-1; break; }
                    if(cnt==x) nr = i;
                    if(s[i]=='^' and c==o)
                    {
                        cnt++;
                        if(cnt==x) nl = i+1;
                    }
                }
            }
            l = nl; r = nr;
            if(l==-1 or r==-1) br = true;
            cin >> x;
        }
        for(int i = a.size()-1;i >= 0;i--) cout << "op(" << a[i] << ',';
        cout << 'p';
        for(int i = 0;i < a.size();i++) cout << ')';
        cout << '=';
        if(l==-1 or r==-1) cout << "null";
        else for(int i = l;i <= r;i++) cout << s[i];
        cout << endl;
    }
}
