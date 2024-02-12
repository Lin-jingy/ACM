#include<bits/stdc++.h>
using namespace std;
#define int long long
struct gold_coin{
    int weight;
    int value;
    double ratio;
}a[105];
bool fact(gold_coin x,gold_coin y){
    return x.ratio>y.ratio;
}
signed main(){
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;++i){
        cin>>a[i].weight>>a[i].value;
        a[i].ratio=(double)a[i].value/(double)a[i].weight;
    }
    sort(a,a+n,fact);
    int remain_space=t;
    double total_value=0;
    for(int i=0;i<n&&remain_space!=0;++i){
        if(remain_space>=a[i].weight){
            remain_space-=a[i].weight;
            total_value+=a[i].value;
        }else{
            total_value+=a[i].ratio*remain_space;
            remain_space=0;
        }
    }
    printf("%.2lf",total_value);
    return 0;
}