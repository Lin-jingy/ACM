#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[50005];
int n,k;
int jc(int left,int r){
    int cover=2*r+1;
    int pos=lower_bound(a,a+n,a[left]+cover)-a;
    if(pos<n)return 1+jc(pos,r);
    else return 1;
}
signed main(){
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    int r=((a[n-1]-a[0])/k+1)/2;
    int bk=0;
    while(1){
        int x=jc(0,r);
        if(x<=k)--r;
        else if(x>k){cout<<r+1;return 0;}
    }
    return 0;
}