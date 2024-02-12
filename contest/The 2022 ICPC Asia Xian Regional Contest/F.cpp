#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n,c1,c2;cin >> n >> c1 >> c2;
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        string s;cin >> s;
        set<char>c;
        for (int i = 0;i < 3;i++) {
            c.insert(s[i]); 
        }
        int k = c.size();
        if (c2 <= c1) {
            if (k <= 2) {
                ans += c2 * 2;
            }
            else ans += c2 * 3;
        }
        else {
           if (k <= 2) {
            if (c1 * 2 >= c2) {
                ans += c2 + c1;
            }
            else {
                ans += 3 * c1;
            }
           }
           else {
            ans += 3 * c1;
           }
        }
    }
    cout << ans;

    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}