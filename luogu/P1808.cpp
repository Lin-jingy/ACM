#include<bits/stdc++.h>
#define int long long
using namespace std;
set<string>str;
string x;
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        sort(x.begin(),x.end());
        str.insert(x);
    }
    cout<<str.size();
    return 0;
}