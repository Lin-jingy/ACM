// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int a, b;
    while(std::cin >> a >> b){
        int k = std::__gcd(a, b);
        std::cout << k << ' ' << a / k * b << '\n';
    }
    return 0;
}
