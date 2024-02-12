#include<bits/stdc++.h>
using namespace std;
#define int long long
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve() {
    unordered_map<int,int,custom_hash>m1,m2;
    int n,k;
    cin>>n>>k;
    int x;
    for(int i=1;i<=n;++i){
        cin>>x;
        m2[x]=i;
        if(!m1.count(x))m1[x]=i;
    }
    int a,b;
    while(k--){
        cin>>a>>b;
        if(m1.count(a) and m2.count(b) and m1[a]<m2[b])cout<<"YES\n";
        else cout<<"NO\n";
    }
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}