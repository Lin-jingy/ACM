// #include <bits/stdc++.h>

// const int z = 13431;
// const int zz = 1247;
// #define int long long

// signed main() {
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);
    
//     int n;
//     std::cin >> n;
//     std::vector<std::string> a(n);
//     long long sum = 0;
//     for(auto &i:a) std::cin >> i, sum += i.size();
//     sum = sum * n * 2;
//     std::unordered_map<size_t, int> mp;
//     std::unordered_map<size_t, int> mp1;
//     for(auto i:a) {
//         unsigned long long k = 0;
//         unsigned long long k1 = 0;
//         for(int j = 0; j < i.size(); ++j) {
//             k = (k * z + i[j]);
//             k1 = (k1 * zz + i[j]);
//             mp[k]++;
//             mp1[k1]++;
//         }
//     }
//     long long ans = sum;
//     for(auto i:a) {
//         unsigned long long k = 0;
//         unsigned long long k1 = 0;
//         std::reverse(i.begin(), i.end());
//         long long sum = 0;
//         std::vector<std::pair<unsigned long long, unsigned long long>> p(i.size());
//         for(int j = 0; j < i.size(); ++j) {
//             k = (k * z + i[j]);
//             k1 = (k1 * zz + i[j]);
//             p[j] = {k, k1};
//         }
//         for(int j = i.size() - 1; j >= 0; --j) {
//             ans -= (std::min(mp[p[j].first], mp1[p[j].second]) - sum) * (j + 1) * 2;
//             sum = std::min(mp[p[j].first], mp1[p[j].second]);
//         }
//     }
//     std::cout << ans << '\n';
//     return 0;
// }

#include <bits/stdc++.h>

#define int long long

const int N = 1e6 + 6;
int a[N][26], f = 1;
int p[N];
int ans = 0;

void add(std::string &s) {
    int k = 1;
    for(int i = 0; i < s.size(); ++i) {
        if(!a[k][s[i] - 'a']) {
            a[k][s[i] - 'a'] = ++f;
        }
        k = a[k][s[i] - 'a'];
        p[k]++;
    }
}

void query(std::string &s) {
    int k = 1;
    for(int i = 0; i < s.size(); ++i) {
        ans -= 2 * p[k];
        k = a[k][s[i] - 'a'];
    }
    ans -= 2 * p[k];
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> v;
    for(int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        add(s);
        v.push_back(s);
        ans += s.size();
    }
    ans = ans * n * 2;
    for(auto s:v) {
        std::reverse(s.begin(), s.end());
        query(s);
    }
    std::cout << ans << '\n';

}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}
