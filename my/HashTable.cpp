#include <bits/stdc++.h>

template <class _Key, class _Value, class _Hash = std::hash<_Key>,
          class _Equal = std::equal_to<_Key>>
class HashTable {
   private:
    constexpr static size_t prime[29] = {
        7,         13,        29,        53,        97,        193,
        389,       769,       1543,      3079,      6151,      12289,
        24593,     49157,     98317,     196613,    393241,    786433,
        1572869,   3145739,   6291469,   12582917,  25165843,  50331653,
        100663319, 201326611, 402653189, 805306457, 1610612741};
    using pair = std::pair<_Key, _Value>;
    using list = std::forward_list<pair>;

   private:
    constexpr int _findNextPrime(int x) {
        return *std::upper_bound(prime, prime + 29, x);
    }
    constexpr auto _find(std::vector<list> &bucket, const _Key &key) {
        const size_t hashcode = _Hash{}(key) % bucket.size();
        auto &it = bucket[hashcode];
        for (auto i = it.begin(); i != it.end(); ++i) {
            if (_Equal{}(i->first, key)) return std::make_pair(i, &it);
        }
        return std::make_pair(it.end(), &it);
    }
    constexpr bool _insert(std::vector<list> &bucket,
                 const pair &value) {
        auto it = _find(bucket, value.first);
        if (it.first != it.second->end()) return false;
        it.second->push_front(value);
        return true;
    }

    constexpr bool _expand() {
        if (m_size <= (int)m_bucket.size() * 0.75) return false;
        std::vector<list> m_tmp(_findNextPrime(m_bucket.size()));
        for (auto &it : m_bucket)
            for (auto &value : it) _insert(m_tmp, value);
        m_bucket.swap(m_tmp);
        return true;
    }

   public:
    constexpr HashTable() : m_bucket(3), m_size(0){};
    constexpr bool insert(const pair &value) {
        ++m_size;
        _expand();
        return _insert(m_bucket, value);
    }
    constexpr bool count(const _Key &key) {
        auto it = _find(m_bucket, key);
        return it.first != it.second->end();
    }
    constexpr void erase(const _Key &key) {
        --m_size;
        auto &it = m_bucket[_Hash{}(key) % m_bucket.size()];
        if (_Equal{}(it.front().first, key)) return it.pop_front(), void();
        auto last = it.begin();
        for (auto i = it.begin(); i != it.end(); ++i) {
            last = i;
            if (_Equal{}(i->second, key)) return it.erase_after(last), void();
        }
    }
    constexpr _Value &operator[](const _Key &key) {
        auto it = _find(m_bucket, key);
        if (it.first == it.second->end()) {
            ++m_size;
            if (_expand()) it = _find(m_bucket, key);
            it.second->push_front({key, {}});
            it.first = it.second->begin();
        }
        return it.first->second;
    }
    constexpr size_t size() { return m_size; }
    constexpr bool empty() { return m_size == 0; }

   private:
    std::vector<list> m_bucket;
    size_t m_size;
};