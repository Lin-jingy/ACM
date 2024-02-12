#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    if(x==1)cout<<"x^"<<n;
    else if(x>0)cout<<x<<"x^"<<n;
    else if(x==-1)cout<<"-"<<"x^"<<n;
    else if(x<0)cout<<x<<"x^"<<n;
    for(int i=n-1;i>1;--i){
        x=0;
        cin>>x;
        if(x==1)cout<<"+"<<"x^"<<i;
        else if(x>0)cout<<"+"<<x<<"x^"<<i;
        else if(x==-1)cout<<"-"<<"x^"<<i;
        else if(x<0)cout<<x<<"x^"<<i;
    }
    x=0;
    cin>>x;
    if(x==1)cout<<"+"<<"x";
    else if(x>0)cout<<"+"<<x<<"x";
    else if(x==-1)cout<<"-"<<"x";
    else if(x<0)cout<<x<<"x";
    x=0;
    cin>>x;
    if(x>0)cout<<"+"<<x;
    else if(x<0)cout<<x;
    return 0;
}