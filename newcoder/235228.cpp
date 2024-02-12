#include<bits/stdc++.h>
using namespace std;
#define int long long
bool prime(int x) {
    if (x < 2)return false;
    else if (x == 2 or x == 3)return true;
    else {
        int k = sqrt(x);
        for (int i = 3; i <= k; i += 2)if (x % i == 0)return false;
    }
    return true;
}
signed main() {
    int l, r; cin >> l >> r;
    //大于3的素数只分布在6n-1和6n+1两数列中
    int ans = 0, k = 0;
    for (int i = l; i <= r; ++i) {
        if (i == 2 or i == 3)ans++;
        else if (i % 6 == 0) {
            k = i;
            break;
        }
    }
    for (int i = k; i <= r; i += 6) {
        if (i - 1 >= l and prime(i - 1))++ans;
        if (i + 1 <= r and prime(i + 1))++ans;
    }
    cout << ans;
    return 0;
}

