#include<bits/stdc++.h>
using namespace std;
#define int long long

int num[30];

void solve() {
    string s;cin >> s;
    for (int i = 0;i < 26;i++) num[i] = 0;
    int len = s.size();
    for (int i = 0;i < len;i++) {
        num[s[i] - 'a']++;
    }
    int ans = INT_MAX;
    for (int i = 0;i < 26;i++) {
        ans = min(len - num[i],ans);
    }
    cout << ans << '\n';
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