#include<bits/stdc++.h>
using namespace std;
#define int long long
map<string,int>q;
map<string,int>::iterator it;
bool flag[10005];
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        string x;
        cin>>x;
        q.insert(make_pair(x,i));
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;++i){
        string x;
        cin>>x;
        it=q.find(x);
        if(it!=q.end()&&!flag[it->second]){
            flag[it->second]=1;
            cout<<"OK"<<'\n';
        }else if(it!=q.end()&&flag[it->second])cout<<"REPEAT"<<'\n';
        else cout<<"WRONG"<<'\n';
    }
    return 0;
}