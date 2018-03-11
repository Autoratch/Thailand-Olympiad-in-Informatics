#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

vector<vector<int> > adj(26);
int m;
bool fin;

void dfs(vector<int> a)
{
    if(fin) return;
    if(a.size()==m+1){ for(int i = 0;i < a.size();i++) cout << (char)(a[i]+'A') << ' '; fin = true; return; }
    vector<vector<bool> > t(26);
    for(int i = 0;i < 26;i++) t[i].assign(26,false);
    for(int i = 0;i < a.size()-1;i++){ t[a[i]][a[i+1]] = true; t[a[i+1]][a[i]] = true; }
    a.push_back(0);
    for(int i = 0;i < adj[a[a.size()-2]].size();i++)
    {
        if(t[adj[a[a.size()-2]][i]][a[a.size()-2]]) continue;
        a[a.size()-1] = adj[a[a.size()-2]][i];
        dfs(a); if(fin) return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m;

    for(int i = 0;i < m;i++)
    {
        string s;
        cin >> s;
        adj[s[0]-'A'].push_back(s[1]-'A');
        adj[s[1]-'A'].push_back(s[0]-'A');
    }

    vector<int> od;

    for(int i = 0;i < 26;i++) if(adj[i].size()%2==1) od.push_back(i);

    vector<int> a;
    a.push_back(0);

    if(od.size()==0)
    {
        for(int i = 0;i < 26;i++) if(adj[i].size()){ a[0] = i; dfs(a); }
        if(fin) return 0;
    }
    else
    {
        for(int i = 0;i < od.size();i++){ a[0] = od[i]; dfs(a); }
        if(fin) return 0;
    }
}
