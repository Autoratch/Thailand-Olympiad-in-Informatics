#include<bits/stdc++.h>
using namespace std;
#define N 1005

struct A{
    int x,y;
};
char s[N];

int ans,di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
bitset<N> bl[N],vis[N],use[N];
queue<A> q;

int main(){
    int n,m,i,j,k,x,y,cnt;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",s+1);
        for(j=1;j<=m;j++)if(s[j]=='X')bl[i][j]=true;
    }
    for(i=1;i<=n;i++)q.push({i,1}),q.push({i,m}),vis[i][1]=vis[i][m]=true;
    for(i=2;i<m;i++)q.push({1,i}),q.push({n,i}),vis[1][i]=vis[n][i]=true;
    while(!q.empty()){
        x=q.front().x;
        y=q.front().y;
        q.pop();
        for(k=0;k<4;k++){
            int X=x+di[k],Y=y+dj[k];
            if(X>0&&X<=n&&Y>0&&Y<=m&&!bl[X][Y]&&!vis[X][Y])q.push({X,Y}),vis[X][Y]=true;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(!use[i][j]&&bl[i][j]){
                q.push({i,j});
                use[i][j]=true;
                cnt=0;
                while(!q.empty()){
                    x=q.front().x;
                    y=q.front().y;
                    q.pop();
                    for(k=0;k<4;k++){
                        int X=x+di[k],Y=y+dj[k];
                        if(X>0&&X<=n&&Y>0&&Y<=m&&bl[X][Y]&&!use[X][Y])q.push({X,Y}),use[X][Y]=true;
                        if(X>0&&X<=n&&Y>0&&Y<=m&&vis[X][Y])cnt++;
                    }
                }
                ans=max(ans,cnt);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
