#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}
signed main(){
    int t;cin>>t;
    for(int ii=0;ii<t;++ii){
        int n,k;
        cin>>n>>k;
        int a[n]={};
        for(int i=0;i<n;++i)a[i]=read();
        sort(a,a+n);
        cout<<a[k-1]<<'\n';
    }
    return 0;
}