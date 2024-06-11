#include <bits/stdc++.h>

#define ALL(x) begin(x), end(x)
#define EVAL(x) #x " = " << (x)

using std::cin, std::cout;
using i64 = int64_t;
using f64 = long double;
using str = std::string;

template <typename T>
using vec = std::vector<T>;

template <typename T, size_t n>
using arr = std::array<T, n>;

constexpr auto mod = 998244353;
namespace Arith {
inline auto fix(int x) { return x + (x >> 31 & mod); }
inline void sub(int& x, int y) { x = fix(x - y); }
inline auto norm(int x) { return x >= mod ? x - mod : x; }
inline void add(int& x, int y) { x = norm(x + y); }
}  // namespace Arith

void solve() {
  auto n = 0;
  cin >> n, n += 2;

  auto a = vec<int>(n);
  for (auto i = 1; i < n - 1; ++i) cin >> a[i];
  a[0] = *std::max_element(1 + ALL(a) - 1) + 1, a[n - 1] = a[0] + 1;

  auto f = vec<int>(n), s = vec<int>(n);
  f[0] = s[0] = 1;
  auto stk = vec<std::pair<int, int>>{{0, 1}};
  for (auto i = 1; i < n; ++i) {
    while (!stk.empty() && a[i] < a[stk.back().first]) stk.pop_back();
    f[i] = s[i - 1];
    if (!stk.empty())
      Arith::sub(f[i], Arith::fix(s[stk.back().first] - stk.back().second));
    s[i] = Arith::norm(s[i - 1] + f[i]);
    stk.emplace_back(
        i, stk.empty() ? f[i] : Arith::norm(stk.back().second + f[i]));
  }
  cout << f[n - 1] << std::endl;
}

auto main() -> int {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

    for(int i = 1; i <= 12; ++i) {

        std::string address1 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/19 ok/data/{}.in", i);
        std::string address2 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/19 ok/data/rr{}.out", i);
        // std::clog << address1 << std::endl;
        freopen(address1.c_str(), "r", stdin);
        freopen(address2.c_str(), "w", stdout);




        auto t = 0;
        cin >> t;
        while (t--) solve();


        fclose(stdin);
        fclose(stdout);





    }

  
}