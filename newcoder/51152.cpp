//#include<bits/stdc++.h>
//using namespace std;
//const int N = 3e3 + 5;
//int dp[N][N], a[N], b[N];
//void solve() {
//    int n; cin >> n;
//    for (int i = 1; i <= n; ++i)cin >> a[i];
//    for (int i = 1; i <= n; ++i)cin >> b[i];
//    int ans = 0;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (a[i] == b[j]) {
//                int mx = 1;
//                for (int k = 1; k < j; ++k) {
//                    if (a[i] > b[k])mx = max(mx, dp[i - 1][k] + 1);
//                }
//                dp[i][j] = max(dp[i][j], mx);
//            }
//            ans = max(ans, dp[i][j]);
//        }
//    }
//    cout << ans;
//    return;
//}
//signed main() {
//    solve();
//    return 0;
//}



#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
int dp[N][N], a[N], b[N];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)cin >> a[i];
    for (int i = 1; i <= n; ++i)cin >> b[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int mx = 1;
        for (int j = 1; j <= n; ++j) {
            if (a[i] > b[j])mx = max(mx, dp[i - 1][j] + 1);
            dp[i][j] = dp[i - 1][j];
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], mx);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return;
}
signed main() {
    solve();
    return 0;
}