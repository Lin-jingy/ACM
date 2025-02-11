#include <bits/stdc++.h>

long long getAns(long long L, long long R) {
    // if (L == 0 and R == 1) return 1;
    // if (L == R) return 0;
    // int lenL = 64 - __builtin_clzll(L);
    // int lenR = 64 - __builtin_clzll(R);
    // if (lenL < lenR) return (1LL << lenR) - 1;
    // L -= 1LL << (lenL - 1);
    // R -= 1LL << (lenR - 1);
    // return getAns(L, R);
    std::bitset<64> bl(L), br(R);
    for (int i = 63; i >= 0; --i) {
        if (bl[i] == br[i]) bl[i] = br[i] = 0;
        else {
            while (i >= 0) {
                bl[i] = 1;
                --i;
            }
            break;
        }
    }
    return bl.to_ullong();
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int T;
    std::cin >> T;
    while (T--) {
        long long l, r;
        std::cin >> l >> r;
        std::cout << getAns(l, r) << '\n';
    }
}