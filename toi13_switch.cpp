#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    string s;

    cin >> n >> s;

    int o = 0,z = 0;

    for(int i = 0;i < n;i++)
    {
        if(s[i]=='0') z++;
        else o++;
    }

    if(!z or !o){ cout << "1"; return 0; }

    int po = -1,pz = -1,lo = -1,lz = -1;
    bool ok = false,zk = false;
    int so,sz,eo,ez;

    for(int i = 0;i < n;i++) if(s[i]=='0'){ sz = i; break; }
    for(int i = 0;i < n;i++) if(s[i]=='1'){ so = i; break; }
    for(int i = n-1;i >= 0;i--) if(s[i]=='0'){ ez = n-1-i; break; }
    for(int i = n-1;i >= 0;i--) if(s[i]=='1'){ eo = n-1-i; break; }

    for(int i = 0;i < n;i++)
    {
        if(s[i]=='0')
        {
            if(zk) continue;
            if(pz==-1) pz = i;
            else if(lz==-1) lz = i-pz;
            else if(i-pz!=lz) zk = true;
            pz = i;
        }
        else
        {
            if(ok) continue;
            if(po==-1) po = i;
            else if(lo==-1) lo = i-po;
            else if(i-po!=lo) ok = true;
            po = i;
        }
    }

    if(so+eo+1!=lo) ok = true;
    if(sz+ez+1!=lz) zk = true;

    if(ok and zk) cout << n;
    else if(ok) cout << lz;
    else cout << lo;
}
