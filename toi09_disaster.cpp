#include <bits/stdc++.h>
using namespace std;

int m;
vector<vector<int> > adj(26);
bool visited[26][26];

bool solve(int p,int lv)
{
    if(lv==m){ cout << (char)(p+'A') << ' '; return true; }
    for(int i = 0;i < adj[p].size();i++)
    {
        if(visited[p][adj[p][i]]) continue;
        visited[p][adj[p][i]] = true;
        visited[adj[p][i]][p] = true;
        if(solve(adj[p][i],lv+1)){ cout << (char)(p+'A') << ' '; return true; }
        visited[p][adj[p][i]] = false;
        visited[adj[p][i]][p] = false;
    }
    return false;
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

    for(int i = 0;i < 26;i++)
    {
        if(adj[i].size()%2==0) continue;
        for(int j = 0;j < 26;j++) for(int k = 0;k < 26;k++) visited[j][k] = false;
        if(solve(i,0)) return 0;
    }

    for(int i = 0;i < 26;i++) if(solve(i,0)) return 0;
}
