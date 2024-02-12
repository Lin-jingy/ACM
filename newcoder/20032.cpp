#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005][5005];
int b[5005][5005];
signed main(){
    int n,r;
    cin>>n>>r;
    int maxx=0,maxy=0;
    for(int i=0;i<n;++i){
        int x,y,v;
        cin>>x>>y>>v;
        if(x>maxx)maxx=x;
        if(y>maxy)maxy=y;
        a[x][y]=v;
    }
    int max=0;
    
    return 0;
}