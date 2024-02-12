#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
map<int,int>p1;
map<int,int>p2;
signed main(){
    int m,n,k,l,d;
    cin>>m>>n>>k>>l>>d;
    int ans=d;
    while(d--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        p1[max(x1,x2)]++;
        p2[max(y1,y2)]++;
    }
    while(k--){
        ans-=p2.rbegin()->second;
        p2.erase(p2.end());
    }
    while(l--){
        
    }
    return 0;
}