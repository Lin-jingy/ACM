#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int mod = 998244353;
int a[N], b[N];
void solve(){
    int l, n, m;
    cin >> l >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i];
    for (int i = n; i < n + m; i++)cin >> a[i] >> b[i];
    int c = 0, d = n, ans = 0;
    for (int i = 0; i < n + m; i++){
        if (a[c] == a[d])ans += min(b[c], b[d]);
        if (b[c] < b[d])b[d] -= b[c],c++;
        else b[c] -= b[d],d++;
    }
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t=1;
    while(t--)solve();
    return 0;
}