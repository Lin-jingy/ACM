#include<bits/stdc++.h>
using namespace std;
#define int long long
struct stu{
    string name;
    int chinese;
    int math;
    int english;
    int sum;
    int k;
}a[1005];
bool fact(stu a,stu b){
    if(a.sum!=b.sum)return a.sum>b.sum;
    else return a.k<b.k;
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].name>>a[i].chinese>>a[i].math>>a[i].english;
        a[i].sum=a[i].chinese+a[i].math+a[i].english;
        a[i].k=i;
    }
    sort(a,a+n,fact);
    cout<<a[0].name<<' '<<a[0].chinese<<' '<<a[0].math<<' '<<a[0].english;
    return 0;
}