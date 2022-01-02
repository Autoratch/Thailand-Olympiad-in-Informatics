#include<bits/stdc++.h>
using namespace std;
#define N 100005

int a[N];
priority_queue<int,vector<int>,greater<int>> q;

int main(){
    int n,m,k,i,l,r,mid,cnt,last,sum,ans;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    l=0,r=2e9;
    while(l<=r){
        mid=l+(r-l)/2;
        cnt=last=sum=0;
        for(i=1;i<=n;i++){
            q.push(a[i]);
            sum+=a[i];
            if(q.size()>k){
                sum-=q.top();
                q.pop();
            }
            if(sum>=mid){
                i=max(i,last+k);
                last=i;
                if(i<=n)cnt++;
                while(!q.empty())q.pop();
                sum=0;
            }
        }
        while(!q.empty())q.pop();
        if(cnt>=m)ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}
