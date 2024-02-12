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
    int n;
    cin >> n >> a;
    string ans;
    char r = a[0];
    ans += a[0];
    for(auto i = 1; i < n; ++i){
        if(a[i] == r){
            ++i;
            if(i >= n)break;
            r = a[i], ans += r;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
