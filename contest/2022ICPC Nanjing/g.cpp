#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e6 + 5;
int a[maxn];

void solve() {
    int n;cin >> n;
    int sum = 1,g = 1,ok = 0,check = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] == 0 || a[i] == 1) cnt++;
        else {
            cnt--;
        } 
        if (cnt < 0) {
            cout << "-1" << '\n';
            return ;
        }
    }
    for (int i = 1;i <= n;i++) {
        if (a[i] == 0) {
            if (sum > 1) {
                ok++;
                sum--;
            }
            else {
                sum++;
                g++;
            }
        }
        else if (a[i] == 1) {
            sum++,g++;
        }
        else {
            if (sum > 1) {
                sum--;
            }
            else {
                if (ok > 0) {
                    sum += 2,g++;
                    sum--;
                }
                ok--;
            }
        }
    }
    cout << g / __gcd(sum,g) << ' ' << sum / __gcd(sum,g) << '\n';
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