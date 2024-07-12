#include <algorithm>
#include <bits/stdc++.h>

constexpr static std::vector<int> get_prime(const int n) {  // Euler
    std::vector<int> prime;
    std::vector<bool> not_prime(n + 1);

    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) prime.push_back(i);
        for (int j : prime) {
            if (i * j > n) break;
            not_prime[i * j] = true; 
            if (i % j == 0) break;
        }
    }
    return prime;
}
auto prime = get_prime(1e7 + 5);

constexpr static std::vector<int> get_prime_factor(int x) {
    std::vector<int> prime_factor;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) x /= i, prime_factor.push_back(i);
    }
    if (x != 1) prime_factor.push_back(x);
    return prime_factor;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    std::unordered_map<int, int> mp;
    for(int i = 0; i < 500; ++i) mp[prime[i]] = i;
    int mx = prime[500];
    std::vector<std::array<int, 500>> pre(n + 1);
    std::unordered_map<int, int> hash;
    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> pri(100000);
    std::vector<int> pre1(n + 1);
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        auto it = get_prime_factor(a[i]);
        if(!it.empty() and it.back() >= mx) {
            a[i] = it.back();
            if(!hash.count(a[i])) hash[a[i]] = hash.size();
            pri[hash[a[i]]].push_back(i);
            it.pop_back();
            pre1[i]++;
        } else a[i] = 1;
        pre1[i] += pre1[i - 1];
        std::vector<int> pos(500);
        for(auto j:it) pos[mp[j]] = pos[mp[j]] ^ 1;
        for(int j = 0; j < 500; ++j) pre[i][j] = pos[j] + pre[i - 1][j];
    }
    int ans = 0;
    
    while(q--) {
        int l, r;
        std::cin >> l >> r;
        l ^= ans;
        r ^= ans;
        ans = 0;
        for(int i = 0; i < 500; ++i) {
            int k = pre[r][i] - pre[l - 1][i];
            ans += std::min(k, r - l + 1 - k);
        }
        std::mt19937_64 rnd(time(0));
        if(pre1[r] - pre1[l - 1] == 0) goto A;
        for(int _ = 1; _ <= 20; ++_) {
            int pos = rnd() % (r - l + 1) + l;
            if(a[pos] == 1) continue;
            else pos = hash[a[pos]];
            auto R =  std::upper_bound(pri[pos].begin(), pri[pos].end(), r) - pri[pos].begin() - 1;
            auto L = std::lower_bound(pri[pos].begin(), pri[pos].end(), l) - pri[pos].begin();
            int size = R - L + 1;
            if(size > (r - l + 1) / 2) {
                int sum = pre1[r] - pre1[l - 1];
                ans += r - l + 1 - size + sum - size;
                goto A;
            }
        }
        ans += pre1[r] - pre1[l - 1];
        A:;
        
        std::cout << ans << '\n';
    }
    return 0;
}