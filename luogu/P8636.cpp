#include<bits/stdc++.h>
using namespace std;
int a[105];
set<int>s;
void prim(int m){
    int i = 2;
    while(i < m){
        if(m % i == 0){
            s.insert(i);
            m /= i;
        }
        else i++;
    }
    s.insert(m);
}
signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    pair<int,int>k=make_pair(a[1],a[2]);

    return 0;
}