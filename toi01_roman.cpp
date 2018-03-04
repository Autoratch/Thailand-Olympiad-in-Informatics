#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int i,v,x,l,c;

void rm(int n)
{
    if(n>=300) c+=3;
    else if(n>=200) c+=2;
    else if(n>=100) c++;
    n%=100;
    if(n>=90){ x++; c++; }
    else if(n>=80){ l++; x+=3; }
    else if(n>=70){ l++; x+=2; }
    else if(n>=60){ l++; x++; }
    else if(n>=50) l++;
    else if(n>=40){ l++; x++; }
    else if(n>=30) x+=3;
    else if(n>=20) x+=2;
    else if(n>=10) x++;
    n%=10;
    if(n==9){ i++;  x++; }
    else if(n==8){ v++; i+=3; }
    else if(n==7){ v++; i+=2; }
    else if(n==6){ v++; i++; }
    else if(n==5) v++;
    else if(n==4){ v++; i++; }
    else if(n==3) i+=3;
    else if(n==2) i+=2;
    else if(n==1) i++;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    for(int ix = 1;ix <= n;ix++) rm(ix);

    cout << i << ' ' << v << ' ' << x << ' ' << l << ' ' << c;
}
