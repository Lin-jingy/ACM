#include <bits/stdc++.h>

#define int long long

static std::vector<int> get_prime(int n) {  // Euler
    std::vector<int> prime;
    std::vector<bool> not_prime(n + 1);

    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) prime.push_back(i);
        for (int pri_j : prime) {
            if (i * pri_j > n) break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) break;
        }
    }
    return std::move(prime);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<int> prime = get_prime(2e5);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int &i:a) std::cin >> i;
    int num = std::count(a.begin(), a.end(), 0);
    int ans = num * (n - num);
    ans += num * (num - 1) / 2;
    std::map<int, int> mp;
    for(auto &i:a) {
        if(i == 0) continue;
        for(auto j:prime) {
            if(j * j > i) break;
            while(i % (j * j) == 0) i /= j * j;
        }
        ans += mp[i];
        mp[i]++;
    }
    std::cout << ans << '\n';
    return 0;
}