#include<bits/stdc++.h>
using namespace std;
#define int long long
struct student{
    string name;
    int age;
    int score;
}a[100];
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].name>>a[i].age>>a[i].score;
        a[i].age++;
        a[i].score*=1.2;
        if(a[i].score>600)a[i].score=600;
    }
    for(int i=0;i<n;++i){
        cout<<a[i].name<<' '<<a[i].age<<' '<<a[i].score<<'\n';
    }
    return 0;
}