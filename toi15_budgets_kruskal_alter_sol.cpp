#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int B,E,S,T,R,P;
long long int C,D,L,ans=0;
priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>> > q;
vector<pii> cost;
int parent[3010];

int root(int n)
{
    if(parent[n]==n) return n;
    return parent[n] = root(parent[n]);
}

int main()
{
    for(int a=0;a<3010;a++){
        parent[a]=a;
    }
    scanf(" %d %d",&B,&E);
    for(int a=0;a<E;a++)
    {
        scanf(" %d %d %lld %d",&S,&T,&L,&R);
        if(R==1) L=0;
        q.push({L,{S,T}});
    }
    scanf(" %d",&P);
    cost.push_back({0,0});
    for(int a=0;a<P;a++)
    {
        scanf(" %lld %lld",&C,&D);
        cost.push_back({C,D});
    }
    sort(cost.begin(),cost.end());
    for(int a=P-1;a>=0;a--)
    {
        cost[a].second=min(cost[a].second,cost[a+1].second);
    }
    while(!q.empty())
    {
        int lt=q.top().first;
        int par_a=root(q.top().second.first);
        int par_b=root(q.top().second.second);
        q.pop();
        if(par_a!=par_b)
        {
            parent[par_a]=par_b;
            for(int a=P;a>=0;a--)
            {
                if(cost[a].first<lt){
                    ans+=cost[a+1].second;
                    break;
                }
            }
        }
    }
    printf("%lld",ans);
}
