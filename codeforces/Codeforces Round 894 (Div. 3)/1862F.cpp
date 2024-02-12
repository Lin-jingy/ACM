// #include <bits/stdc++.h>

// void solve() {
//     int w, f;
//     std::cin >> w >> f;
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n);
//     long long sum = 0;
//     for(int i = 0; i < n; ++i) std::cin >> a[i], sum += a[i];
//     std::set<long long> s;
//     s.insert(0);
//     std::deque<long long> dq;
//     for(int i = 0; i < n; ++i) {
//         for(auto j:s) dq.push_back(j + a[i]);
//         for(auto j:dq) s.insert(j);
//         while(!dq.empty()) s.insert(dq.back()), dq.pop_back();
//     }

//     int l = 1, r = 1e6, ans = 0;
//     auto check = [&](long long x) -> bool {
//         long long aa = x * w;
//         long long bb = x * f;
//         if(aa > bb) std::swap(aa, bb);
//         if(bb >= sum) return true;
//         if(aa + bb < sum) return false;
//         int kk = 0;
//         auto k = s.lower_bound(aa);
//         if(k == s.begin()) kk = 0;
//         else kk = *(--k);
//         if(bb >= sum - kk) return true;
//         else return false;

//     };

//     while(l <= r) {
//         int mid = l + r >> 1;
//         if(check(mid)) ans = mid, r = mid - 1;
//         else l = mid + 1;
//     }

//     std::cout << ans << '\n';
// }

// int main() {
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);
//     int T = 1;
//     std::cin >> T;
//     while(T--) solve();
//     return 0;
// }


#include <bits/stdc++.h>

void solve() {
    int w, f, n;
    std::cin >> w >> f >> n;
    std::bitset<1000001>bi;
    bi[0] = 1;
    int sum = 0, ans = INT_MAX;
    for(int i = 0, x; i < n; ++i) std::cin >> x, bi |= (bi << x), sum += x;
    for(int i = 0; i <= 1000000; ++i) {
        if(bi[i]) ans = std::min(ans, std::max((i - 1) / w + 1, (sum - i - 1) / f + 1));
    }
    std::cout << ans << '\n';

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
