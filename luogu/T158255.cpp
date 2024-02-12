#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m,p;
    cin>>n>>m>>p;
    set<string>fr;
    set<string>en;
    for(int i=1;i<=n;++i){
        string x;
        cin>>x;
        fr.insert(x);
    }
    for(int i=1;i<=m;++i){
        string x;
        cin>>x;
        en.insert(x);
    }
    for(int i=0;i<p;++i){
        string x;
        cin>>x;
        int len=x.size();
        string xx;
        for(int j=0;j<len;++j){
            xx+=x[j];
            set<string>::iterator it=fr.find(xx);
            if(it!=fr.end()){x.erase(0,it->size());break;}
        }
        xx.clear();
        xx=x;
        len=x.size();
        for(int j=len-1;j>=0;--j){
            xx=x;
            string mid;
            mid=xx.erase(0,j);
            set<string>::iterator it=en.find(mid);
            if(it!=en.end()){x.erase(j);break;}
        }
        cout<<x<<'\n';
    }
    return 0;
}