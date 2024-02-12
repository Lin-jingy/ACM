#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, k, b,s;
    cin >> n >> k >> b >> s;
    int mk = s / k;
    if (b > mk) {cout << "-1\n";return;}
    vector<int> a(n);
    a[0] = s;
    for (int i = 1; i < n; i++) {
        if (mk > b && a[0] >= k) {
            mk -= (a[0] % k != k - 1);
            a[0] -= k - 1;
            a[i] = k - 1;
        }
    }
    if (mk != b) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}