//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int>a(n + 1), mn(5, inf), mx(5, -inf);
    for(size_t i(1); i <= n; ++i) a[i] = s[i - 1] - 'A';
    int rp[] = {1, 10, 100, 1000, 10000};
    for(int i(1); i <= n; ++i) 
        mn[a[i]] = min(mn[a[i]], i), mx[a[i]] = max(mx[a[i]], i);
    int ans(-INF);
    auto change = [&](int x, int flag){
        if(flag > 0) a[mn[x]] += flag;
        else a[mx[x]] += flag;
        int sum(0);
        int mxs(0);
        for(size_t i(n); i >= 1; --i){
            mxs = max(mxs, a[i]);
            if(a[i] < mxs) sum -= rp[a[i]];
            else sum += rp[a[i]]; 
        }
        if(flag > 0) a[mn[x]] -= flag;
        else a[mx[x]] -= flag;
        return sum;
    };
    
    for(int i = 0; i < 5; ++i){
        if(mn[i] == inf) continue;
        for(int j = -4; j <= 4; ++j){
            if(i + j >= 0 and i + j < 5) ans = max(ans, change(i, j));
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
