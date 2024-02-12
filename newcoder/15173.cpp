#include<bits/stdc++.h>
using namespace std;
#define int long long
int fact(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    if(sum<10)return sum;
    else return fact(sum);
    
}
signed main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}