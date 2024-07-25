#include <bits/stdc++.h>

void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}

template <size_t base = 26>
class tril {
private:
    std::array<std::vector<int>, base> next;
    int tot = 0;
public:
    tril(int sumSize) {
        for(int i = 0; i < base; ++i) next[i].resize(sumSize);
    }
    void insert(const std::string &s) {
        int p = 0;
        for(auto i:s) {
            int c = i - '0';
            if(!next[c][p]) next[c][p] = ++tot;
            p = next[c][p];
        }
    }
    bool find(const std::string &s) {
        int p = 0;
        for(auto i:s) {
            int c = i - '0';
            if(!next[c][p]) return 0;
            p = next[c][p];
        }
        return 1;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for(int i = 0; i < n; ++i) std::cin >> v[i];
    std::ranges::sort(v, [](const std::string &a, const std::string &b) {
        return a.size() > b.size();
    });
    tril<10> T(1e5 + 5);
    for(int i = 0; i < n; ++i) {
        if(T.find(v[i])) {
            std::cout << "NO\n";
            return ;
        }
        T.insert(v[i]);
    }
    std::cout << "YES\n";
}