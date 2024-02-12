#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    int x;
    std::vector<std::vector<int>>A(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> x;
            A[i].push_back(x);
        }
    }
    
    std::vector<std::vector<int>>B(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> x;
            B[i].push_back(x);
        }
    }
    
    for (int t = 0; t < 4; t++) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == 1 && B[i][j] == 0) {
                    ok = false;
                }
            }
        }
        if (ok) {
            std::cout << "Yes\n";
            return 0;
        }
        auto C = A;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                A[x][y] = C[N - 1 - y][x];
            }
        }
    }
    
    std::cout << "No\n";
    
    return 0;
}