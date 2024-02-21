#include <algorithm>
#include <bits/stdc++.h>

int a[1000005];

static bool isPrime(int n) {  // O(7logn)
    if (n < 3 || n % 2 == 0) return n == 2;
    int u = n - 1, t = 0;
    while (u % 2 == 0) u /= 2, ++t;
    auto quickPow = [](int a, int b, int p) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (long long)res * a % p;
            a = (long long)a * a % p;
            b >>= 1;
        }
        return res;
    };
    int p[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (int i = 0; i < 7; ++i) {
        int a = p[i] % (n - 2) + 2, v = quickPow(a, u, n);
        if (v == 1) continue;
        int s;
        for (s = 0; s < t; ++s) {
            if (v == n - 1) break;
            v = (long long)v * v % n;
        }
        if (s == t) return false;
    }
    return true;
}

// void solve(int n) {
//     for(int i = 1; i <= n; ++i) a[i] = i;
//     do {
//         for(int i = 1; i <= n; ++i) {
//             if(!isPrime(a[i] + i)) goto A;
//         }
//         for(int i = 1; i <= n; ++i) {
//             std::cout << a[i] << " \n"[i == n];
//         }
//         return ;
//     A:;
//     }while(std::next_permutation(a + 1, a + 1 + n));
// } 

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // for(int i = 1; i <= 13; ++i) solve(i);
    // int num = 0;
    // for(int i = 1; i <= 26; ++i) if(isPrime(i)) ++num;
    // std::cout << num;
    int n;
    std::cin >> n;
    auto dfs = [&](auto &&self, int n) {
        if(n == 0) return ;
        if(n == 1) {
            a[1] = 1;
            return ;
        }
        if(n == 2) {
            a[1] = 2;
            a[2] = 1;
            return ;
        }
        int k = 0;
        for(int i = n + 1; i < 2 * n; ++i) {
            if(isPrime(i)) {
                k = i;
                break;
            }
        }

        int l = k - n;
        for(int i = l; i <= n; ++i) a[i] = k - i;
        self(self, l - 1);
    };

    dfs(dfs, n);
    for(int i = 1; i <= n; ++i) std::cout << a[i] << ' ';
    return 0;
}


/* 
1
2 1
1 3 2
2 1 4 3
1 5 4 3 2
2 1 4 3 6 5
1 3 2 7 6 5 4
2 1 4 3 8 7 6 5
1 3 2 7 6 5 4 9 8
2 1 4 3 6 5 10 9 8 7
1 3 2 7 6 5 4 11 10 9 8
2 1 4 3 6 5 10 9 8 7 12 11
1 3 2 7 6 5 4 9 8 13 12 11 10



*/