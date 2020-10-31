#include <bits/stdc++.h>
using namespace std;

int N,K,a,sum=0,last=INT_MIN,mx=0,length=0;
deque<pair<int,int>> q;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    q.push_back({0,0});
    for(int i=1;i<=N;i++)
    {
        cin >> a;
        sum+=a;
        while(!q.empty()&&i-q.front().second>K) q.pop_front();
        if(sum-q.front().first>mx){ mx=sum-q.front().first; length=i-q.front().second; }
        else if(sum-q.front().first==mx && i-q.front().second<length) length=i-q.front().second;
        while(!q.empty()&&q.back().first>=sum) q.pop_back();
        q.push_back({sum,i});
    }
    if(mx<=0) cout << "0\n0";
    else cout << mx << "\n" << length;
}
