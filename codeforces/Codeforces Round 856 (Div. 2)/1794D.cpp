#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick ios::sync_with_stdio(false),cin.tie(nullptr);
const int mod=998244353;
const int N=2100;
vector<int>a;//存储原始数据
vector<int>sum;//记录两两组合的值
vector<pair<int,int>>psum;//记录原组合数
int Prime[1000005];//记录判断过是否素数的结果
bool isPrime(int x){//判断质数
    if(x<2)return false;
    for(int i=2;i*i<=x;++i){
        if(x%i==0)return false;
    }
    return true;
}
int quickpow(int a,int b){//快速幂
    int sum=1;
    while(b){
        if(b&1)sum=sum*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return sum;
}
void solve(){
    memset(Prime,-1,sizeof Prime);
    int n;cin>>n;
    int x;
    for(int i=0;i<n;++i){
        cin>>x;
        a.emplace_back(x);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++i){
            if(i==j)continue;
            if(Prime[i]==-1 and isPrime(i) or Prime[i]==1){
                Prime[i]=1;
                sum.emplace_back(quickpow(i,j));
                psum.emplace_back(i,j);
            }else if(Prime[i]==-1){
                Prime[i]=0;
            }else
        }
    }


    return;
}
signed main(){
    quick;
    int t=1;
    while(t--)solve();
    return 0;
}