// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define int long long
using PII = pair<int, int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    vector<bool>p(n + 1);
    for(size_t i(1); i < n; ++i) cin >> a[i];
    int mem(0);
    for(size_t i(1); i < n; ++i){
        if(mem == 0){
            if(a[i] - a[i - 1] > n or p[a[i] - a[i - 1]]) mem = a[i] - a[i - 1];
            else p[a[i] - a[i - 1]] = true;
        }else{
            if(a[i] - a[i - 1] > n or p[a[i] - a[i - 1]]){
                no;
                return;
            }else p[a[i] - a[i - 1]] = true;
        }
    }
    if(mem == 0){
        yes;
        return;
    }
    for(size_t i(1); i <= n; ++i) if(!p[i]) mem -= i;
    if(mem == 0)yes;
    else no;
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
