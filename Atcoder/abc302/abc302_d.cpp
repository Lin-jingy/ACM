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

const int N = 2e5 + 5;
vector<int>a, b;

void solve(){
    a.clear(), b.clear();
    int n, m, d, x;
    cin >> n >> m >> d;
    for(int i = 1; i <= n; ++i) cin >> x, a.emplace_back(x);
    for(int i = 1; i <= m; ++i) cin >> x, b.emplace_back(x);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = -1;
    while(!a.empty() and !b.empty()){
        if(a.back() > b.back()){
            if(a.back() <= b.back() + d) ans = max(ans, a.back() + b.back());
            a.pop_back();
        }
        else if(b.back() >= a.back()){
            if(b.back() <= a.back() + d) ans = max(ans, a.back() + b.back());
            b.pop_back();
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
