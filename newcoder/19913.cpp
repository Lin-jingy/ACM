#include<bits/stdc++.h>
using namespace std;
#define int long long
struct ff{
    int left;
    int right;
};
stack<ff>s;
set<pair<int,int>>p;
int a[100005],ans=1;
signed main(){
    int n,b;
    cin>>n>>b;
    int x;
    ff k;
    for(int i=0;i<n;++i){
        cin>>x;
        if(x>b)a[i]=1;
        else if(x<b)a[i]=-1;
        else{
            a[i]=0;
            k.left=i;k.right=i;
        }
    }
    s.push(k);p.insert(make_pair(k.left,k.right));
    while(!s.empty()){
        k=s.top();
        s.pop();
        ff mid=k;
        mid.left--;mid.right++;
        if(mid.left>=0&&mid.right<n&&a[mid.left]+a[mid.right]==0){
            s.push(mid);
            int lens=p.size();
            p.insert(make_pair(mid.left,mid.right));
            if(p.size()!=lens)ans++;
        }
        mid=k;
        mid.left-=2;
        if(mid.left>=0&&mid.right<n&&a[mid.left]+a[mid.left+1]==0){
            s.push(mid);
            int lens=p.size();
            p.insert(make_pair(mid.left,mid.right));
            if(p.size()!=lens)ans++;
        }
        mid=k;
        mid.right+=2;
        if(mid.left>=0&&mid.right<n&&a[mid.right-1]+a[mid.right]==0){
            s.push(mid);
            int lens=p.size();
            p.insert(make_pair(mid.left,mid.right));
            if(p.size()!=lens)ans++;
        }
    }
    cout<<ans;
    return 0;
}