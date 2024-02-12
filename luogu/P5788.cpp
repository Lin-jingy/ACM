#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>k;
map<int,int>::iterator it;
map<int,int>::iterator fi;
int a[1000005];
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        a[i]=x;
        k.insert(make_pair(x,i));
    }
    for(int i=0;i<n;++i){
        it=k.upper_bound(a[i]);
        cout<<it->second<<' ';
    }
    return 0;
}