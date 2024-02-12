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

const int N = 15;
int n;
double a[N][N];
const int eps = 1e-9;

int gauss(){
    int c, r;
    for (c = 0, r = 0; c < n; c ++){
       int t = r;
       for (int i = t; i < n; i ++) if (fabs(a[i][c]) > fabs(a[t][c])) t = i;
       if (fabs(a[t][c]) < eps) continue;
       for (int i = c; i <= n; i ++) std::swap(a[t][i], a[r][i]);
       for (int i = n; i >= c; i --) a[r][i] /= a[r][c]; 
       for (int i = r + 1; i < n; i ++) if (fabs(a[i][c]) > eps) for (int j = n; j >= c; j --) a[i][j] -= a[r][j] * a[i][c];
       r ++;
    }
    if (r < n) {// 说明有效的方程个数小于n,那要么无穷解，要么无解
        for (int i = r; i < n; i ++)if (fabs(a[i][n]) > eps) return 2;  // 不等于0无解
        return 1;  // 都是0 = 0的方程，无穷解
    }
    // 唯一解，从下往上回代，得到方程的解
    for (int i = n - 1; i >= 0; i --) for (int j = i + 1; j < n; j ++) a[i][n] -=  a[i][j] * a[j][n];
    return 0;
}


void solve(){
    std::cin >> n;
    for(int i = 1; i <= n + 1; ++i) for(int j = 1; j <= n; ++j) std::cin >> a[j][i];
    gauss();
    for(int i = 1; i <= n; ++i) printf("%.3lf ", a[i][n + 1]);
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    //std::cin >> _;
    while (_--)
        solve();
    return 0;
}
