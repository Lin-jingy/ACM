#include<bits/stdc++.h>
#define int long long
using namespace std;
int fact(int m,int n){
    int z = n;
    while (m % n != 0){
        z = m % n;
        m = n;
        n = z;
    }
    return z;
}
int sum;
signed main(){
    int x,y;
    cin>>x>>y;
    int k=x*y;
    if(y%x==0)sum++;
    for(int i=x;i<=y/2;i+=x){
        if(k%i!=0)continue;
        int j=k/i;
        if(fact(i,j)==x)sum++;
    }
    cout<<sum;
    return 0;
}