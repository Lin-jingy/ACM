#include<bits/stdc++.h>

using namespace std;
#define int long long 

void solve(){
    int n;
    cin >> n;
    int ans = 0, x;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        ans ^= x;
        if (x > 1) flag = true;
    }
    if ((ans and flag) or (!ans and !flag))cout << "John" << '\n';
    else cout << "Brother" << '\n';

}

signed main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}