#include <bits/stdc++.h>

enum OPTION {
    Nature,
    Single,
    Double,
} ;
template <enum OPTION op, long long base1 = 131, long long base2 = 133331>
class StringHash {
    #define int long long 
private:
    std::vector<int> hash1, hash2, p1, p2;
    int mod1, mod2;
    bool isprime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }
    int findPrime(int n) {
        while (!isprime(n)) n++;
        return n;
    }
    void init_nature(std::string_view s) {
        p1[0] = hash1[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hash1[i] = hash1[i - 1] * base1 + s[i - 1];
            p1[i] = p1[i - 1] * base1;
        }
    }
    void init_single(std::string_view s) {
        p1[0] = hash1[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hash1[i] = (1LL * hash1[i - 1] * base1 + s[i - 1]) % mod1;
            p1[i] = 1LL * p1[i - 1] * base1 % mod1;
        }
    }
    void init_double(std::string_view s) {
        hash2.resize(s.size() + 1);
        p2.resize(s.size() + 1);
        p1[0] = p2[0] = hash1[0] = hash2[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hash1[i] = (1LL * hash1[i - 1] * base1 + s[i - 1]) % mod1;
            hash2[i] = (1LL * hash2[i - 1] * base2 + s[i - 1]) % mod2;
            p1[i] = 1LL * p1[i - 1] * base1 % mod1;
            p2[i] = 1LL * p2[i - 1] * base2 % mod2;
        }
    }
    void init_mod() {
        static int MOD1 = 0, MOD2 = 0;
        if(!MOD1) {
            std::mt19937_64 rnd(time(0));
            MOD1 = findPrime(rnd() % 900'000'000 + 100'000'000);
            MOD2 = findPrime(rnd() % 900'000'000 + 100'000'000);
        }
        mod1 = MOD1; mod2 = MOD2;
    }
public:
    StringHash(std::string_view s): hash1(s.size() + 1), p1(s.size() + 1){
        init_mod();
        if constexpr (op == Nature) init_nature(s);
        if constexpr (op == Single) init_single(s);
        if constexpr (op == Double) init_double(s);
    }
    template <enum OPTION O = op>
    std::enable_if_t<O == Nature, int> get(int l, int r) {
        ++l, ++r;
        return hash1[r] - hash1[l - 1] * p1[r - l + 1];
    }
    template <enum OPTION O = op>
    std::enable_if_t<O == Single, int> get(int l, int r) {
        ++l, ++r;
        return (hash1[r] + (mod1 - hash1[l - 1]) * p1[r - l + 1]) % mod1;
    }
    template <enum OPTION O = op>
    std::enable_if_t<O == Double, std::pair<int, int>> get(int l, int r) {
        ++l, ++r;
        return {(hash1[r] + 1LL * (mod1 - hash1[l - 1]) * p1[r - l + 1]) % mod1,
        (hash2[r] + 1LL * (mod2 - hash2[l - 1]) * p2[r - l + 1]) % mod2};
    }
    template <enum OPTION O = op>
    std::enable_if_t<O == Nature || O == Single, int> getAll() {
        return hash1.back();
    }
    template <enum OPTION O = op>
    std::enable_if_t<O == Double, std::pair<int, int>> getAll() {
        return {hash1.back(), hash2.back()};
    }
    #undef int
};