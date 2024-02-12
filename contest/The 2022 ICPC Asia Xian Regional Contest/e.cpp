#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[1005];

int dfs(int x) {
    if(x <= 100) return f[x];
    if(x % 3 == 0) return 1 + dfs(x / 3);
    else return 1 + dfs(x - 1);
}

void solve() {
    f[0] = 1;
    for (int i = 1;i <= 1000;i++) {
        if (i % 3 == 0) f[i] = f[i / 3] + 1;
        else f[i] = f[i - 1] + 1;
    }
    // int l, r;
    // cin >> l >> r;
    // int mx = l;
    // for(int i = l + 1; i <= r; ++i) if(f[i] > f[mx]) mx = i;
    // cout << f[mx] << '\n';
    int l, r;
    cin >> l >> r;
    int lll[200] = {},rrr[200] = {};
    long double ll = l, rr = r;
    int k = 0;
    while(rr > 100 and rr - ll > 10) {
        ll /= 3, rr /= 3;
        k++;
        lll[k] = ll,rrr[k] = rr;
    }
    l = ceil(ll);
    r = rr;
    if(rr - ll <= 10) {
        int mx = 0;
        for(int i = l; i <= r; ++i) {
            mx = max(mx, dfs(i));
        }
        cout << mx + k * 3 << '\n';
        return ;
    }
    //cout << l << ' ' << r << '\n';
    int mx = 0;
    for(int i = l; i <= r; ++i) mx = max(mx, f[i]);
    int p[mx + 5] = {};
    for(int i = l; i <= r; ++i) {
        if(f[i] == mx) {
            if (p[mx] == 0) p[mx] = i;
        }
        else if (f[i] == mx - 1) {
            if (p[mx - 1] == 0) p[mx - 1] = i;
        }
        else if (f[i] == mx - 2) {
            if (p[mx] == 0) p[mx - 1] = i;
        }
    }
    for (int i = k;i >= 1;i--) {
        if ((p[mx] * 3 + 2 <= rrr[i])) {
            mx = mx + 3;
        }
    }
    cout << mx + 3 * k << '\n';
    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}