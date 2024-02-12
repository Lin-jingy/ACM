#include<bits/stdc++.h>

int ans;

void fact(char *p, int k) {
    if(*p == 'X') ans += k, *p = '.';
}

void solve() {
    char a[11][11];
    for(int i = 1; i <= 10; ++i) for(int j = 1; j <= 10; ++j) std::cin >> a[i][j];
    ans = 0;
    for(int i = 1; i <= 5; ++i) {
        for(int j = i; j <= 11 - i; ++j) 
            fact(&a[j][i], i), fact(&a[i][j], i),
            fact(&a[j][11-i], i), fact(&a[11-i][j], i);
    }
    std::cout << ans << '\n';

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}