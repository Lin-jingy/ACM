#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for(int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        mp[x]++;
    }
    int ans = 0;
    while(!mp.empty()) {
        ++ans;
        int la = mp.begin()->first - 1;
        for(auto it = mp.begin(); it != mp.end(); ) {
            if(it->first == la + 1) {
                it->second--;
                la++;
                if(it->second == 0) it = mp.erase(it);
                else ++it;
            } else break;
        }
    }

    std::cout << ans << '\n';

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}