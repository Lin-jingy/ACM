#include<bits/stdc++.h>

void solve(){
    int n, m, x, y, i2, j2;
    std::string s;
    std::cin >> n >> m >> x >> y >> i2 >> j2 >> s;
    if(x == i2 and y == j2) {
        std::cout << 0 << '\n';
        return ;
    }
    std::vector<std::vector<int>> p(n + 1, std::vector<int>(m + 1));
    int ans = 0;
    if(x + 1 > n and s[0] == 'D') ++ans;
    else if(x - 1 < 1 and s[0] == 'U') ++ans;
    else if(y + 1 > m and s[1] == 'R') ++ans;
    else if(y - 1 < 1 and s[1] == 'L') ++ans;
    while(1){
        if(x + 1 > n and s[0] == 'D') s[0] = 'U';
        if(x - 1 < 1 and s[0] == 'U') s[0] = 'D';
        if(y + 1 > m and s[1] == 'R') s[1] = 'L';
        if(y - 1 < 1 and s[1] == 'L') s[1] = 'R';
        int x1, y1;
        if(s == "DL") x1 = x + std::min(n - x, y - 1), y1 = y - std::min(n - x, y - 1);
        else if(s == "DR") x1 = x + std::min(n - x, m - y), y1 = y + std::min(n - x, m - y);
        else if(s == "UL") x1 = x - std::min(x - 1, y - 1), y1 = y - std::min(x - 1, y - 1);
        else if(s == "UR") x1 = x - std::min(x - 1, m - y), y1 = y + std::min(x - 1, m - y);
        if((i2 >= x and i2 <= x1) or (i2 >= x1 and i2 <= x)){
            if((s[1] == 'L' and j2 == y - abs(i2 - x)) or (s[1] == 'R' and j2 == y + abs(i2 - x))){
                std::cout << ans << '\n';
                return;
            }
        }
        x = x1, y = y1;
        if(p[x][y] == 2){
            std::cout << -1 << '\n';
            return ;
        }
        ++p[x][y];
        ++ans;
    }

}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}