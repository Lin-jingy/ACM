#include<bits/stdc++.h>
using namespace std;
#define int long long
stack<int>s;
int a[1000005],b[1000005];
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=n-1;i>=0;--i)
        b[i]=max(b[i+1],a[i]);
    for(int i=0;i<n;++i){
        if(a[i]>b[i+1])cout<<a[i]<<' ';
        else s.push(a[i]);
    }
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}