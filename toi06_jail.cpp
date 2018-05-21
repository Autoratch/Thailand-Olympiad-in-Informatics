#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int n,k,fw[1000001],bw[1000001],cur;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) fw[i] = i+1;
    for(int i = 2;i <= n;i++) bw[i] = i-1;
    fw[n] = 1; bw[1] = n;

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < k;j++) cur = fw[cur];
        cout << cur << ' ';
        fw[bw[cur]] = fw[cur];
        bw[fw[cur]] = bw[cur];
    }
}
