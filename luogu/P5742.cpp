#include<bits/stdc++.h>
using namespace std;
#define int long long
struct student{
    int name;
    int std;
    int tz;
    int zh;
    int sum;
}a[1008];
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].name>>a[i].std>>a[i].tz;
        a[i].zh=a[i].std*7+a[i].tz*3;
        a[i].sum=a[i].std+a[i].tz;
    }
    for(int i=0;i<n;++i){
        if(a[i].zh>=800 && a[i].sum>140)cout<<"Excellent"<<'\n';
        else cout<<"Not excellent"<<'\n';
    }
    return 0;
}