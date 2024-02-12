#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::string> S(H);
    int maxx = -1, minx = H, maxy = -1, miny = W;
    for (int i = 0; i < H; i++) {
        std::cin >> S[i];
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                maxx = std::max(maxx, i);
                minx = std::min(minx, i);
                maxy = std::max(maxy, j);
                miny = std::min(miny, j);
            }
        }
    }
    
    for (int i = minx; i <= maxx; i++) {
        for (int j = miny; j <= maxy; j++) {
            if (S[i][j] == '.') {
                std::cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }
    
    return 0;
}
