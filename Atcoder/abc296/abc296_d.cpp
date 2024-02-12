#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, m, ans = INT64_MAX;

void find(int x) {
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (mid * x >= m) {
            r = mid - 1;
            ans = min(ans, mid * x);
        }
        else l = mid + 1;
    }
}

void solve() {
    cin >> n >> m;
    int k = sqrt(m) + 1;
    for (int i = 1; i <= min(n, k); ++i) {
        find(i);
    }
    if (ans == INT64_MAX)cout << -1;
    else cout << ans;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    while (t--)solve();
    return 0;
}


//#include<bits/stdc++.h>
//
//using namespace std;
//#define int long long
//
//void solve() {
//    int n, m;
//    cin >> n >> m;
//    int ans = INT64_MAX;
//    int k = sqrt(m) + 1;
//    for (int i = 1; i <= min(k, n); ++i) {
//        int x = 0;
//        x = m / i;
//        if (m % i != 0)++x;
//        if (x <= n) ans = min(ans, x * i);
//    }
//    /*for (int i = 1; i <= n; ++i) {
//        int x = (m + i - 1) / i;
//        if (x <= n)ans = min(ans, x * i);
//        if (i > x)break;
//    }*/
//    if (ans == INT64_MAX)cout << -1;
//    else cout << ans;
//}
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr);
//    int t = 1;
//    while (t--)solve();
//    return 0;
//}