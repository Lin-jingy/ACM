#include "hashmap.h"

template <class _Key, class _Value, class _Hash>
hashmap<_Key, _Value, _Hash>::hashmap() : m_size(0), m_buckets(0), point(0) {}

template <class _Key, class _Value, class _Hash>
hashmap<_Key, _Value, _Hash>::~hashmap() {
    for (auto& item : m_buckets) {
        delete item;
    }
    m_size = 0;
    point = 0;
}

template <class _Key, class _Value, class _Hash>
size_t hashmap<_Key, _Value, _Hash>::hash(_Key key) {
    return std::hash<_Key>()(key);
}

template <class _Key, class _Value, class _Hash>
void hashmap<_Key, _Value, _Hash>::resize(size_t size) {
    if (size >= m_buckets.size()) {
        std::vector<Bucket*> new_buckets(_stl_prime[point++]);
        for (auto& _i : m_buckets) {
            if (_i) {
                for (auto& [_key, _value] : *_i) {
                    size_t hashcode = hash(_key) % new_buckets.size();
                    if (!new_buckets[hashcode]) new_buckets[hashcode] = new Bucket();
                    (*new_buckets[hashcode])[_key] = _value;
                }
                delete _i;
            }
        }
        m_buckets = std::move(new_buckets);
    }
    ++m_size;
}

template <class _Key, class _Value, class _Hash>
typename hashmap<_Key, _Value, _Hash>::iterator& 
hashmap<_Key, _Value, _Hash>::iterator::operator++() {
    if (entry_it != (*bucket_it)->end()) {
        ++entry_it;
    }
    else {
        ++bucket_it;
        while (bucket_it != it->m_buckets.end() && (*bucket_it == nullptr || (*bucket_it)->empty())) {
            ++bucket_it;
        }
        if (bucket_it != it->m_buckets.end()) {
            entry_it = (*bucket_it)->begin();
        }
    }
    return *this;
}

template <class _Key, class _Value, class _Hash>
typename hashmap<_Key, _Value, _Hash>::iterator
hashmap<_Key, _Value, _Hash>::iterator::operator++(int) {
    iterator old(*this);
    ++(*this);
    return old;
}

template <class _Key, class _Value, class _Hash>
typename hashmap<_Key, _Value, _Hash>::Key_Value&
hashmap<_Key, _Value, _Hash>::iterator::operator*() const { return *entry_it; }

template <class _Key, class _Value, class _Hash>
typename hashmap<_Key, _Value, _Hash>::Key_Value*
hashmap<_Key, _Value, _Hash>::iterator::operator->() const { return &*entry_it; }


template <class _Key, class _Value, class _Hash>
bool hashmap<_Key, _Value, _Hash>::iterator::operator==
(const iterator& other) {
    return bucket_it == other.bucket_it && 
           entry_it == other.entry_it && 
           it == other.it;
}

template <class _Key, class _Value, class _Hash>
bool hashmap<_Key, _Value, _Hash>::iterator::operator!=
(const iterator& other) {
    return !(*this == other);
}

template <class _Key, class _Value, class _Hash>
typename hashmap<_Key, _Value, _Hash>::iterator hashmap<_Key, _Value, _Hash>::begin() {
    for (auto it = m_buckets.begin(); it != m_buckets.end(); ++it) {
        if (*it && !(*it)->empty()) {
            return iterator(it, (*it)->begin(), this);
        }
    }
    return end();
}

template <class _Key, class _Value, class _Hash>
typename hashmap<_Key, _Value, _Hash>::iterator hashmap<_Key, _Value, _Hash>::end() {
    return iterator(m_buckets.end(), typename Bucket::iterator(), this);
}

template <class _Key, class _Value, class _Hash>
typename hashmap<_Key, _Value, _Hash>::Bucket::mapped_type&
hashmap<_Key, _Value, _Hash>::operator[](const _Key& key) {
    if (m_buckets.empty()) m_buckets.assign(_stl_prime[point++], nullptr);
    size_t hashcode = hash(key) % m_buckets.size();
    if (!m_buckets[hashcode]) {
        m_buckets[hashcode] = new Bucket();
    }
    auto it = m_buckets[hashcode]->find(key);
    if (it == m_buckets[hashcode]->end()) {
        resize(m_size + 1);
        hashcode = hash(key) % m_buckets.size();
        if (!m_buckets[hashcode]) m_buckets[hashcode] = new Bucket();
    }
    return it;
}

template <class _Key, class _Value, class _Hash>
void hashmap<_Key, _Value, _Hash>::erase(const _Key& key) {
    m_buckets[_hash(key) % m_buckets.size()].erase(key);
    --m_size;
}

template <class _Key, class _Value, class _Hash>
typename hashmap<_Key, _Value, _Hash>::iterator
hashmap<_Key, _Value, _Hash>::erase(iterator it) {
    iterator new_it(it);
    ++new_it;
    m_buckets[it.bucket_it].erase(it.entry_it);
    --m_size;
    return new_it;
}

template<class _Key, class _Value, class _Hash>
typename hashmap<_Key, _Value, _Hash>::iterator 
hashmap<_Key, _Value, _Hash>::find(const _Key& key){
    if (m_buckets.empty()) return nullptr;
    size_t hashcode = hash(key) % m_buckets.size();
    if (m_buckets[hashcode] && m_buckets[hashcode].count(key)) {
        return hashmap<_Key, _Value, _Hash>::iterator(
            m_buckets.begin() + hashcode,
            m_buckets[hashcode].find(key),
            this
        );
    }
}

template <class _Key, class _Value, class _Hash>
size_t hashmap<_Key, _Value, _Hash>::size() {
    return m_size;
}

template <class _Key, class _Value, class _Hash>
bool hashmap<_Key, _Value, _Hash>::empty() {
    return m_size == 0;
}

template <class _Key, class _Value, class _Hash>
void hashmap<_Key, _Value, _Hash>::clear() {
    for (auto& item : m_buckets) {
        delete item;
    }
    m_size = 0;
    point = 0;
    m_buckets.clear();
}

template <class _Key, class _Value, class _Hash>
hashmap<_Key, _Value, _Hash>&
hashmap<_Key, _Value, _Hash>::operator=
(const hashmap<_Key, _Value, _Hash>& other) {
    if (this != &other) {
        clear();
        m_size = other.m_size;
        m_buckets.resize(other.m_buckets.size());
        for (size_t i = 0; i < other.m_buckets.size(); ++i) {
            if (other.m_buckets[i]) {
                m_buckets[i] = new Bucket(*other.m_buckets[i]);
            }
            else {
                m_buckets[i] = nullptr;
            }
        }
        point = other.point;
    }
    return *this;
}

template <class _Key, class _Value, class _Hash>
hashmap<_Key, _Value, _Hash>&
hashmap<_Key, _Value, _Hash>::operator=
(hashmap<_Key, _Value, _Hash>&& other) noexcept {
    if (this != &other) {
        clear();
        m_size = other.m_size;
        m_buckets = std::move(other.m_buckets);
        point = other.point;
        other.m_size = 0;
        other.m_capacity = 0;
    }
    return *this;
}