#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    vector<int>v1, v2, v3;
    int n;
    cin >> n;
    int k1, k2;
    int x;
    string a;
    while(n--){
        cin >> x >> a;
        if(a[0] == '1')v1.push_back(x);
        if(a[1] == '1')v2.push_back(x);
        if(a[0] == '1' and a[1] == '1')v3.push_back(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    if(!v1.empty() and !v2.empty()){
        if(!v3.empty())cout << min(v1[0] + v2[0], v3[0]) << '\n';
        else cout << v1[0] + v2[0] << '\n';
    }else cout << -1 << '\n';
    
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}