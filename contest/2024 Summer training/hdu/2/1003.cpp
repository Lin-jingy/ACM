#include <bits/stdc++.h>

using L = std::array<int, 4>;
using M = std::array<L, 4>;
using G = std::array<std::array<M, 3>, 4>;

void rotate(M &v) {
    M a;
    a[1][1] = v[3][1];
    a[1][2] = v[2][1];
    a[1][3] = v[1][1];
    a[2][1] = v[3][2];
    a[2][2] = v[2][2];
    a[2][3] = v[1][2];
    a[3][1] = v[3][3];
    a[3][2] = v[2][3];
    a[3][3] = v[1][3];
    v = std::move(a);
}
void r_rotate(M &v) { rotate(v);rotate(v);rotate(v); }
void f1(G &v) {//1
    L tmp = v[1][3][1];
    for(int i = 1; i < 4; ++i) v[1][i][1] = v[1][i - 1][1];
    v[1][0][1] = tmp;
    r_rotate(v[0][1]);
}
void rf1(G &v) { f1(v);f1(v);f1(v); }
void f2(G &v) {//6
    L tmp = v[1][3][3];
    for(int i = 1; i < 4; ++i) v[1][i][3] = v[1][i - 1][3];
    v[1][0][3] = tmp;
    r_rotate(v[2][1]);
}
void rf2(G &v) { f2(v);f2(v);f2(v); }
void f3(G &v) {//2
    L tmp = {0, v[2][1][1][1], v[2][1][2][1], v[2][1][3][1] };
    for(int i = 1; i <)

}


void solve() {
    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}