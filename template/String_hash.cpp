#include <bits/stdc++.h>

enum OPTION {
    Nature,
    Single,
    Double,
};
class StringHash {
private:
    std::vector<int> hashcode_1, hashcode_2, p_1, p_2;
    int base_1 = 131; 
    int base_2 = 133331;
    OPTION op;
    int mod_1;
    int mod_2;
    constexpr bool isprime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }
    constexpr int findPrime(int n) {
        while (!isprime(n)) n++;
        return n;
    }
    void init_nature(const std::string &s) {
        hashcode_1.assign(s.size() + 1, {});
        p_1.assign(s.size() + 1, {});
        p_1[1] = 1;
        for(int i = 1; i <= s.size(); ++i) hashcode_1[i] = hashcode_1[i - 1] * base_1 + s[i - 1];
        for(int i = 2; i <= s.size(); ++i) p_1[i] = p_1[i - 1] * base_1;
    }
    void init_single(const std::string &s) {
        hashcode_1.assign(s.size() + 1, {});
        p_1.assign(s.size() + 1, {});
        p_1[1] = 1;
        for(int i = 1; i <= s.size(); ++i) hashcode_1[i] = (1LL * hashcode_1[i - 1] * base_1 + s[i - 1]) % mod_1;
        for(int i = 2; i <= s.size(); ++i) p_1[i] = 1LL * p_1[i - 1] * base_1 % mod_1;
    }
    void init_double(const std::string &s) {
        hashcode_1.assign(s.size() + 1, {});
        hashcode_2.assign(s.size() + 1, {});
        p_1.assign(s.size() + 1, {});
        p_2.assign(s.size() + 1, {});
        p_1[1] = 1;
        p_2[1] = 1;
        for(int i = 1; i <= s.size(); ++i) hashcode_1[i] = (1LL * hashcode_1[i - 1] * base_1 + s[i - 1]) % mod_1;
        for(int i = 1; i <= s.size(); ++i) hashcode_2[i] = (1LL * hashcode_2[i - 1] * base_2 + s[i - 1]) % mod_2;
        for(int i = 2; i <= s.size(); ++i) p_1[i] = 1LL * p_1[i - 1] * base_1 % mod_1;
        for(int i = 2; i <= s.size(); ++i) p_2[i] = 1LL * p_2[i - 1] * base_2 % mod_2;
    }
    std::pair<int, int> get_nature(int l, int r) {
        return {hashcode_1[r] - hashcode_1[l - 1] * p_1[r - l + 1], 0LL};
    }
    std::pair<int, int> get_single(int l, int r) {
        return {(hashcode_1[r] + (mod_1 - hashcode_1[l - 1]) * p_1[r - l + 1]) % mod_1, 0LL};
    }
    std::pair<int, int> get_double(int l, int r) {
        return {(hashcode_1[r] + 1LL * (mod_1 - hashcode_1[l - 1]) * p_1[r - l + 1]) % mod_1,
        (hashcode_2[r] + 1LL * (mod_2 - hashcode_2[l - 1]) * p_2[r - l + 1]) % mod_2};
    }
public:
    StringHash(const std::string &s, enum OPTION option) {
        op = option;
        static bool first = true;
        static int MOD_1;
        static int MOD_2;
        if(first) {
            first = false;
            std::mt19937 rnd(time(0));
            MOD_1 = findPrime(rnd() % 900000000 + 100000000);
            MOD_2 = findPrime(rnd() % 900000000 + 100000000);
        }
        mod_1 = MOD_1;
        mod_2 = MOD_2;
        if(op == OPTION::Nature) init_nature(s);
        else if(op == OPTION::Single) init_single(s);
        else if(op == OPTION::Double) init_double(s);
    }
    std::pair<int, int> get(int l, int r) {
        ++l, ++r;
        if(op == OPTION::Nature) return get_nature(l, r);
        else if(op == OPTION::Single) return get_single(l, r);
        else if(op == OPTION::Double) return get_double(l, r);
        return {0, 0};
    }
    std::pair<int, int> getAll() {
        if(op == OPTION::Double) return {hashcode_1.back(), hashcode_2.back()};
        else return {hashcode_1.back(), 0};
    }
};