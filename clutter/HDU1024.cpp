#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 10 + 1e6;
int dp[N];
int a[N];
int pre_max[N]; 
int n, m;
void solve()
{
    int mx = INT_MIN;
    memset(dp, 0, sizeof dp);
    memset(pre_max, 0, sizeof pre_max);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= m; i++){
        mx = INT_MIN;
        for (int j = i; j <= n; j++){
            dp[j] = max(dp[j - 1], pre_max[j - 1]) + a[j];
            pre_max[j - 1] = mx;
            mx = max(dp[j], mx);
        }
    }
    cout << mx << endl;
}
int main()
{
    ios::sync_with_stdio();
    while (cin >> m >> n)
        solve();

    return 0;
}
