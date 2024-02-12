#include<bits/stdc++.h>
#define int long long
using namespace std;
struct people{
    int k;
    int score;
}a[5005];
bool fact(people a,people b){
    if(a.score!=b.score)return a.score>b.score;
    else return a.k<b.k;
}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i].k>>a[i].score;
    }
    int t=m*1.5;
    sort(a,a+n,fact);
    while(t<=n){
        if(a[t-1].score==a[t].score)t++;
        else break;
    }
    cout<<a[t-1].score<<' '<<t<<'\n';
    for(int i=0;i<t;++i){
        cout<<a[i].k<<' '<<a[i].score<<'\n';
    }
    return 0;
}