#include <bits/stdc++.h>

template <class _Key, class _Value, class _Hash = std::hash<_Key>,
          class Comp = std::equal_to<_Key>>
class HashTable {
   private:
    constexpr static size_t prime[26] = {
        53,        97,        193,      389,       769,       1543,
        3079,      6151,      12289,    24593,     49157,     98317,
        196613,    393241,    786433,   1572869,   3145739,   6291469,
        12582917,  25165843,  50331653, 100663319, 201326611, 402653189,
        805306457, 1610612741};
    struct node {
        _Key key;
        node *next;
    };
    using nodePoint = node *;
    nodePoint *bucket;

   private:
    int findNextPrime(int x) { return *std::upper_bound(prime, prime + 26, x); }

   public:
};