#include<bits/stdc++.h>
#define int long long
using namespace std;
queue<int>k;
int a[1005];
int sum=0;
signed main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        if(a[x]==1)continue;
        else{
            sum++;
            a[x]=1;
            k.push(x);
            if(k.size()>m){
                a[k.front()]=0;
                k.pop();
            }
        }
    }  
    cout<<sum;
    return 0;
}