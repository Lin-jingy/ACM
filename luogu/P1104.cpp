#include<bits/stdc++.h>
using namespace std;
#define int long long
struct student{
    string name;
    int year;
    int month;
    int day;
    int flag;
}a[105];
bool fact(student q,student p){
    if(q.year!=p.year)return q.year<p.year;
    else if (q.month!=p.month)return q.month<p.month;
    else if(q.day!=p.day)return q.day<p.day;
    else return q.flag>p.flag;
}
signed main(){
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>a[i].name>>a[i].year>>a[i].month>>a[i].day;
        a[i].flag=i;
    }
    sort(a,a+t,fact);
    for(int i=0;i<t;++i){
        cout<<a[i].name<<'\n';
    }
    return 0;
}