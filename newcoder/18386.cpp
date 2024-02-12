#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=INT_MAX;
queue<int>q;
map<int,int>p;
map<int,int>::iterator it;
void check(){
    for(it=p.begin();it!=p.end();++it)
        if(it->second<=0)it=--p.erase(it);
}
signed main(){
    string a;
    cin>>a;
    int len=a.size();
    for(int i=0;i<len;++i){
        p[a[i]]++;q.push(a[i]);
        while(p.size()>=26){
            p[q.front()]--;
            q.pop();
            check();
            if(p.size()>=26&&q.size()<ans)ans=q.size();
        }
    }
    cout<<ans;
    return 0;
}