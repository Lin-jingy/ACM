#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+5;
const int mod = 998244353;
const int P=20005;
int h[N];
int dp[N][2 * P];//dp[i][j]表示以i结尾，以j为公差的等差数列数
void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> h[i];
    int ans = n;
    for(int i = 1; i <= n; ++i){
        for(int j = i - 1; j > 0; --j){
            dp[i][h[i] - h[j] + P] += (dp[j][h[i] - h[j] + P] + 1) % mod;
            ans += dp[j][h[i] - h[j] + P] + 1;
            ans %= mod;
        }
    }
    cout << ans % mod << endl;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t=1;
    while(t--)solve();
    return 0;
}