#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>mins;
priority_queue<pair<int,int>>maxs;
int min1[1000005],max1[1000005];
signed main(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<k;++i){
        mins.push({a[i],i});
        maxs.push({a[i],i});
    }
    min1[0]=mins.top().first;
    max1[0]=maxs.top().first;
    for(int i=k;i<n;++i){
        mins.push({a[i],i});
        maxs.push({a[i],i});
        while(i-mins.top().second>=k)mins.pop();
        while(i-maxs.top().second>=k)maxs.pop();
        min1[i-k+1]=mins.top().first;
        max1[i-k+1]=maxs.top().first;
    }
    for(int i=0;i<=n-k;++i)cout<<min1[i]<<' ';
    cout<<'\n';
    for(int i=0;i<=n-k;++i)cout<<max1[i]<<' ';
    return 0;
}