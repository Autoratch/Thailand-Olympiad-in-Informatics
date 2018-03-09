#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
#define endl '\n'
#define DST dist[min(an[i],an[i+1])][max(an[i],an[i+1])]

int n;
vector<vector<vector<int> > > dist(26);
vector<vector<int> > x(26),y(26);
vector<vector<int> > adj(26);
vector<int> ans;
vector<bool> xt(26),yt(26);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 0;i < 26;i++){ dist[i].resize(26); adj[i].resize(26); }

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        char a,b;
        int d;
        cin >> a >> b >> d;
        if(a=='X'){ x[b-'a'].push_back(d); xt[b-'a'] = true; }
        else if(b=='X'){ x[a-'a'].push_back(d); xt[a-'a'] = true; }
        else if(a=='Y'){ y[b-'a'].push_back(d); yt[b-'a'] = true; }
        else if(b=='Y'){ y[a-'a'].push_back(d); yt[a-'a'] = true; }
        else
        {
            adj[a-'a'][b-'a'] = true;
            adj[b-'a'][a-'a'] = true;
            dist[min((int)(a-'a'),(int)(b-'a'))][max((int)(a-'a'),(int)(b-'a'))].push_back(d);
        }
    }

    queue<pair<int,int> > q;
    vector<int> t(26);
    vector<int> an;

    int ans = -1;

    for(int i = 0;i < 26;i++) if(xt[i]) q.push({i,(1<<i)});

//    cout << q.size()

    while(!q.empty())
    {
        int lst = q.front().first,used = q.front().second;
        q.pop();
        for(int i = 0;i < 26;i++) t[i] = false;
        int tmp = used,cnt = 0;
        while(tmp)
        {
            t[cnt] = tmp%2;
            tmp/=2;
            cnt++;
        }
        if(yt[lst]){ ans = used; break; }
        for(int i = 0;i < 26;i++)
        {
            if(t[i]) continue;
            if(adj[lst][i]) q.push({i,used+(1<<i)});
        }
    }

    if(ans==-1) cout << "broken";
    else
    {
        for(int i = 0;i < 26;i++) t[i] = false;
        int cnt = 0,s,e;
        while(ans)
        {
            t[cnt] = ans%2;
            ans/=2;
            cnt++;
        }
        for(int i = 0;i < 26;i++){ if(x[i].size()>0 and t[i]) s = i; if(y[i].size()>0 and t[i]) e = i; }
        int xa = s;
        an.push_back(s);
        while(xa!=e)
        {
            for(int i = 0;i < 26;i++)
                if(t[i] and adj[xa][i]){ an.push_back(i); adj[i][xa] = false; xa = i; break; }
        }
//        an.push_back(e);

        double dst,det,sum = 0.0;
        sort(x[s].begin(),x[s].end());
        sort(y[e].begin(),y[e].end());
        if(x[s].size()%2==0) dst = (x[s][x[s].size()/2]+x[s][x[s].size()/2-1])/2.0;
        else dst = x[s][x[s].size()/2];
        cout << fixed;
        cout << setprecision(1) << "X " << (char)(s+'a') << ' ' << dst << endl;
        sum+=dst;

        for(int i = 0;i < an.size()-1;i++)
        {
            double each;
            sort(DST.begin(),DST.end());
            if(DST.size()%2==0) each = (DST[DST.size()/2]+DST[DST.size()/2-1])/2.0;
            else each = DST[DST.size()/2];
            sum+=each;
            cout << (char)(an[i]+'a') << ' ' << (char)(an[i+1]+'a') << ' ' << each << endl;
        }

        if(y[e].size()%2==0) det = (y[e][y[e].size()/2]+y[e][y[e].size()/2-1])/2.0;
        else det = y[e][y[e].size()/2];
        cout << fixed;
        cout << setprecision(1) << (char)(e+'a') << " Y " << det << endl;
        sum+=det;

        cout << fixed;
        cout << setprecision(1) << sum;
    }
}
