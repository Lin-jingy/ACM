#include<bits/stdc++.h>
using namespace std;
#define int long long
string a;
signed main(){
    int n;cin>>n;
    int sum=0;
    for(int i=0;i<n;++i){
        cin>>a;
        int len=a.size();
        for(int k=0;k<len-2;++k){
            if(a[i]=='o' and a[i+1]=='w' and a[i+2]=='o')++sum;
        }

    }
    return 0;
}