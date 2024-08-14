#include <bits/stdc++.h>
#include <math.h>

template <class _Key, class _Value, class _Hash = std::hash<_Key>,
          class _Equal = std::equal_to<_Key>>
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
        _Value value;
        node *next = nullptr;
    };
    using nodePoint = node *;

   private:
    int _findNextPrime(int x) {
        return *std::upper_bound(prime, prime + 26, x);
    }
    nodePoint _findAndGetPre(const _Key &key) {
        size_t pos = _Hash{}(key) % m_bucket.size();
        if (m_bucket[pos].next == nullptr) return nullptr;

        nodePoint it = &m_bucket[pos];
        while (it->next) {
            if (_Equal{}(it->next->key, key)) return it;
            it = it->next;
        }
        return nullptr;
    }
    bool _insert(std::vector<node> &bucket,
                 const std::pair<_Key, _Value> &value) {
        ++m_size;
        size_t pos = _Hash{}(value.first) % bucket.size();
        nodePoint it = &bucket[pos];
        while (1) {
            if (_Equal{}(*(it->key), value.first)) return false;
            if (it->next == nullptr) break;
            it = it->next;
        }
        it->next = new nodePoint;
        *(it->next->key) = value.first;
        *(it->next->value) = value.second;
        return true;
    }
    void _destroyed(std::vector<nodePoint> &bucket) {
        for (auto it : m_bucket) {
            nodePoint next = it;
            while (it) {
                next = it->next;
                delete it;
                it = next;
            }
        }
    }

    void _expand() {
        if (m_size + 1 < m_bucket.size()) return;
        m_size = 0;
        std::vector<nodePoint> m_tmp(_findNextPrime(m_bucket.size()));
        forEach([this](const std::pair<_Key, _Value> &value) {
            _insert(m_tmp, value);
        });
        m_bucket.swap(m_tmp);
        _destroyed(m_tmp);
    }

   public:
    HashTable() = default;
    ~HashTable() { _destroyed(m_bucket); }
    bool insert(const std::pair<_Key, _Value> &value) {
        _expand();
        return insert(m_bucket, value);
    }
    void forEach(auto func) {
        for (auto it : m_bucket) {
            while (it) {
                func({it->key, it->value});
                it = it->next;
            }
        }
    }
    bool count(const _Key &key) {
        // TODO
    }
    void erase(const _Key key) {
        // TODO
    }
    size_t size() { return m_size; }
    bool empty() { return m_size == 0; }

   private:
    std::vector<nodePoint> m_bucket;
    size_t m_size;
};