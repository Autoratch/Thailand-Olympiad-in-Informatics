#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define k 333

int a[N],qs[k][N];

int main(){
    int n,q,m,i,j,l,r;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<k;i++){
        for(j=1;j<=n;j++){
            qs[i][j]=a[j];
            if(j-i>0)qs[i][j]+=qs[i][j-i];
        }
    }
    while(q--){
        scanf("%d %d %d",&l,&m,&r);
        if(m<k)printf("%d ",qs[m][l+(r-l)/m*m]-qs[m][l]+a[l]);
        else{
            int ans=0;
            for(i=l;i<=r;i+=m)ans+=a[i];
            printf("%d ",ans);
        }
    }
    return 0;
}
