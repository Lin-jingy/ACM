#include<bits/stdc++.h>
using namespace std;
void dfs(int k,bool pd[9]){
    if(k/10000000>=1){
        string a=to_string(k);
        a.reserve();
        int len=a.size();
        for(int i=0;i<len-1;++i){
            cout<<a[i]<<' ';
        }
        cout<<a[len-1]<<'\n';
        return;
    }
    for(int i=1;i<=8;++i){
        if(!pd[i]){
            pd[i]=true;
            dfs(k*10+i,pd);
            pd[i]=false;
        }
    }
}
signed main(){
    bool pd[9]={false};
    dfs(0,pd);
    return 0;
}