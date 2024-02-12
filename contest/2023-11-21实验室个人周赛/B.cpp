#include<bits/stdc++.h>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector v(n, std::vector<int>(m));
    std::vector<int> mid;
    std::set<int> ans;
    for(auto &i:v) for(auto &j:i) std::cin >> j, mid.push_back(j);
    std::sort(mid.begin(), mid.end());
    for(auto i:v) for(auto j:i) {
        if(k % j == 0) {
            int r = k / j;
            int num = std::upper_bound(mid.begin(), mid.end(), r) - mid.begin();
            if(r <= num) ans.insert(j);
        }
    }
    if(ans.empty()) {
        std::cout << "No\n";
        return ;
    }
    while(!ans.empty()) {
        int d = *ans.begin();
        ans.erase(ans.begin());
        std::vector<std::vector<int>> r(v);
        int sum = 0;
        std::queue<std::pair<int, int>> q;
        std::vector vis(n, std::vector<bool>(m));
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
            if(v[i][j] >= d) {
                j = d, sum++;
                if(q.empty()) q.push({i, j});
            } else a[i][j] = 0;
        }
        while(!q.empty()) {
            auto pos = q.front();
            q.pop();

        }


    }
    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}