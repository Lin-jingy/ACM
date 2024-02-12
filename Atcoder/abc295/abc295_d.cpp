#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick ios::sync_with_stdio(0),cin.tie(0);
unordered_map<int,int>mp;
void solve(){
    string a;
    cin>>a;
    int n=a.size();
    int mid=0,ans=0;
    mp[0]=1;
    for(int i=0;i<n;++i){
        mid ^= (1<<(a[i]-'0'));
        ans+=mp[mid];
        mp[mid]++;
    }
    cout<<ans;
}
signed main(){
    quick;
    int t=1;
    while(t--)solve();
    return 0;
}