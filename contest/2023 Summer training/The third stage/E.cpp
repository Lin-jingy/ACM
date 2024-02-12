#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

string a;
void solve(){
    int k;
    cin >> k;
    // int l = 0, r = 1e9;
    // int ans = 0;
    // while(l <= r){
    //     int mid = l + r >> 1;
    //     int sk = (mid * (mid + 1)) / 2;
    //     if(sk >= k)r = mid - 1;
    //     else l = mid + 1, ans = sk;
    // }
    // cout << k - ans << '\n';
    cout << a[k - 1];
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i = 1; a.size() <= 1e9; ++i){
        for(int j = 1; j < i and a.size() <= 1e9; ++i)a+=to_string(j);
    }
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
