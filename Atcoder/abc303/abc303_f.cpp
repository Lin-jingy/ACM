#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 3e5 + 5;
int n, h;

bool check(int x, vector<int>&t, vector<int>&o,vector<int>&pre, vector<int>&suf){
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        int l = 1, r = x;
        if (i) {
            l = max(l, t[o[i - 1]]);
        }
        if (i < n) {
            r = min(r, t[o[i]] - 1);
        }
        if (l <= r) {
            int m;
            if (!suf[i]) m = r;
            else m = max(l - 1, min(r, pre[i] / suf[i]));
            sum = min(__int128(h), sum + __int128(m - l + 1) * pre[i]);
            sum = min(__int128(h), sum + min(__int128(h), __int128(r - m) * (m + r + 1) / 2) * suf[i]);
        }
    }
        return sum >= h;
}
void solve(){
    cin >> n >> h;
    vector<int> t(n), d(n), o(n), pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) cin >> t[i] >> d[i];
    iota(o.begin(), o.end(), 0);
    //for(auto &i:o)
    sort(o.begin(), o.end(), [&](int i, int j) {
        return t[i] < t[j];
    });
    
    for (int i = 0; i < n; i++) pre[i + 1] = max(pre[i], 1LL * t[o[i]] * d[o[i]]);
    for (int i = n - 1; i >= 0; i--) suf[i] = max(suf[i + 1], 1LL * d[o[i]]);
    int l = 1, r = h;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid, t, o, pre, suf)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
