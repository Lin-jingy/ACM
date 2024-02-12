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

const int N = 1e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int>v;
    for(int i = 1, x; i <= n; ++i) cin >> x, v.emplace_back(x);
    int dis = 0, ans = 0;
    sort(v.begin(), v.end());
    while(!v.empty()){
        ++ans;
        int pos = v.back() - dis;
        while(!v.empty() and v.back() - dis == pos)v.pop_back();
        dis += k;
        while(!v.empty() and v.back() - dis <= 0)v.pop_back();
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
