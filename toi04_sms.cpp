#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

bool xx;

int solve(int num,int times)
{
    xx = false;
    if(num==1){ xx = true; return times; }

    if(num!=7 and num!=9) times%=3;
    else times%=4;

    if(num==2 and times==1) return 'A';
    if(num==2 and times==2) return 'B';
    if(num==2 and times==0) return 'C';
    if(num==3 and times==1) return 'D';
    if(num==3 and times==2) return 'E';
    if(num==3 and times==0) return 'F';
    if(num==4 and times==1) return 'G';
    if(num==4 and times==2) return 'H';
    if(num==4 and times==0) return 'I';
    if(num==5 and times==1) return 'J';
    if(num==5 and times==2) return 'K';
    if(num==5 and times==0) return 'L';
    if(num==6 and times==1) return 'M';
    if(num==6 and times==2) return 'N';
    if(num==6 and times==0) return 'O';

    if(num==7 and times==1) return 'P';
    if(num==7 and times==2) return 'Q';
    if(num==7 and times==3) return 'R';
    if(num==7 and times==0) return 'S';

    if(num==8 and times==1) return 'T';
    if(num==8 and times==2) return 'U';
    if(num==8 and times==0) return 'V';

    if(num==9 and times==1) return 'W';
    if(num==9 and times==2) return 'X';
    if(num==9 and times==3) return 'Y';
    if(num==9 and times==0) return 'Z';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,x,y,t,p;
    vector<char> c;

    cin >> n >> x >> t;

    c.push_back(solve(x,t));
    p = x;

    n--;

    while(n--)
    {
        cin >> x >> y >> t;
//        cout << p+x+3*y << endl;
        int a = solve(p+x+3*y,t);
        p = p+x+3*y;

        if(xx){ int mx = max((int)c.size()-a,0); c.resize(mx); }
        else c.push_back((char)a);
    }

    if(c.size()==0) cout << "null";
    else for(int i = 0;i < c.size();i++) cout << c[i];
}
