#include<bits/stdc++.h>
#define int long long
using namespace std;
map<pair<int,int>,int>q;
map<pair<int,int>,int>::iterator it;
signed main(){
    int n,t;
    cin>>n>>t;
    for(int w=1;w<=t;++w){
        int flag,i,j,k;
        cin>>flag;
        if(flag==1){
            cin>>i>>j>>k;
            if(k!=0)
                q.insert(make_pair(make_pair(i,j),k));
            else{
                it=q.find(make_pair(i,j));
                q.erase(it);
            }
        }
        else{
            cin>>i>>j;
            it=q.find(make_pair(i,j));
            cout<<it->second<<'\n';
        }
    }
    return 0;
}