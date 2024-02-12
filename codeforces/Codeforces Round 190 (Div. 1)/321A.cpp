#include<bits/stdc++.h>

#define int long long
int n, m;
std::string s;

void fact(int &x, int &y){
    for(auto i:s) {
        if(x == n and y == m) std::cout << "Yes\n", exit(0);
        if(i == 'U') y++;
        else if(i == 'D') y--;
        else if(i == 'L') x--;
        else x++;
    }
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    std::cin >> s;
    int x = 0, y = 0;
    fact(x, y);
    int k1 = 0, k2 = 0;
    if(x != 0) k1 = std::max(n / x - 200, k1);
    if(y != 0) k2 = std::max(m / y - 200, k2);
    int xx = x * k1, yy = y * k1;
    int xxx = x * k2, yyy = y * k2;
    for(int i = 0; i <= 200; ++i) fact(xx, yy), fact(xxx, yyy);
    std::cout << "No\n";
    return 0;
}