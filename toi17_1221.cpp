#include<bits/stdc++.h>
using namespace std;
#define N 505

long long dis[N][N],v[N],w,sum;
int sz[N][N];

int main(){
    int n,m,q,i,j,k,a,b;
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=n;i++)scanf("%lld",&v[i]);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)dis[i][j]=v[i]+v[j],sz[i][j]=2;
    for(i=1;i<=m;i++){
        scanf("%d %d %lld",&a,&b,&w);
        dis[a][b]=dis[b][a]=w;
    }
    for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++){
        sum=dis[i][k]+dis[k][j];
        if(sum<dis[i][j])dis[i][j]=sum,sz[i][j]=sz[i][k]+sz[k][j];
        else if(sum==dis[i][j])sz[i][j]=max(sz[i][j],sz[i][k]+sz[k][j]);
    }
    while(q--){
        scanf("%d %d",&a,&b);
        printf("%lld %d\n",dis[a][b],sz[a][b]);
    }
    return 0;
}
